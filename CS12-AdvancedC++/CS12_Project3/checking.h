#ifndef CHECKING_H
#define CHECKING_H

#include "bankAccount.h"
#include <vector>
#include <ctime>
#include <memory>

///////////////////////////////
/* digitalCheck to be sent by checkingAccounts.
     To be written and received by checking accounts.
     Contains data. Does not change data.
     checkingValidater serves as bridge between source checking
            and recipient checking info.
*/
class digitalCheck
{
private:
    std::string signer;
    std::string recipient = "";
    std::string dateWritten = "";
    double amount = 0;
    int account = 0;


    int checkNumber = 0;
    static int generateCheckNumber() {
        int num = 0;
        num++;
        return num;
    }

    std::string dateOfDeposit = "";

public:

    digitalCheck(std::string _signer, std::string _recipient, double _amount,
                    std::string _dateWritten, int _account)
    {
        signer = _signer;
        recipient = _recipient;
        dateWritten = _dateWritten;
        if (amount < 0)
        {
            amount = 0;
        }
        else
        {
            amount = _amount;
        }
        account = _account;
        checkNumber = generateCheckNumber();
    }
    ~digitalCheck() {}


    std::string gSigner() { return signer; }
    std::string gRecipient() { return recipient; }
    std::string gDateWritten() { return dateWritten; }
    double gAmount() { return amount; }
    int gAccountNumber() { return account; }
    int gCheckNumber() { return checkNumber; }

    void outputCheckContents()
    {
        std::cout << '\n' << signer << "'s check to " << recipient
            << "\n    " << "Amount: $" << roundToLeastSignificantOrHundredth(std::to_string(amount))
            << "\n    " << "Account Number: " << account
            << "\n    " << "Check Number: " << checkNumber
            << "\n    " << "Signed date of " << dateWritten
            << std::endl;
    }
};

///////////////////////////////////////////////
/*
   Abstract checking Account
        inherits from bankAccount
        Abstract Methods
            writeCheck
            receiveCheck
*/
class checkingAccount : public bankAccount
{
protected:
    std::vector<digitalCheck> writtenChecks;
    std::vector<digitalCheck> receivedChecks;
    std::vector<std::string> dateReceivedChecks;

    result validateCheckAsReceiving(digitalCheck * check)
    {
        for (unsigned long i = 0; i < writtenChecks.size(); i++)
        {
            if (bankAccount::name != check->gRecipient()) { continue; }

            return result (true, "Account holder's info matches check recipient info");
        }

        return result (false, "Account holder's info does not match check recipient info.");
    }

public:

    result didThisAccountWriteThisCheck(digitalCheck check)
    {
        for (unsigned long i = 0; i < writtenChecks.size(); i++)
        {
            if (writtenChecks[i].gSigner() != check.gSigner()) { continue; }
            if (writtenChecks[i].gRecipient() != check.gRecipient()) { continue; }
            if (writtenChecks[i].gDateWritten() != check.gDateWritten()) { continue; }
            if (writtenChecks[i].gAmount() != check.gAmount()) { continue; }
            if (writtenChecks[i].gAccountNumber() != check.gAccountNumber()) { continue; }
            if (writtenChecks[i].gCheckNumber() != check.gCheckNumber()) { continue; }

            return result (true, "Confirmed");
        }

        return result (false, "Check was not written from this account.");
    }

    result isThisAccountSupposedToReceiveThisCheck (digitalCheck check)
    {
        if (check.gRecipient() != name)
        {
            return result (false, "Name of recipient on check does not match account holder's name for account " + name);
        }

        for (unsigned long i =0; i < receivedChecks.size(); i++)
        {
            if (check.gCheckNumber() == receivedChecks[i].gCheckNumber())
            {
                return result(false, "Copy of digital check already deposited in this account. Check should be considered void");
            }
        }

        return result(true, "Account and check match. Check can be deposited in this account.");
    }

    virtual digitalCheck * writeCheck(std::string signer, std::string recipient, double amount,
                                        std::string date, int account) = 0;
    virtual result receiveCheck(const digitalCheck c) = 0;
};


/////////////////////////////
/*
    serviceChargeChecking Account
        inherits from checkingAccount
        Features
            No interest
            Limited number of monthly checks
            No minimum balance
            monthly service charge
*/
class serviceChargeChecking : public checkingAccount
{
protected:
    int checksThisMonth = 0;

public:
    serviceChargeChecking(std::string _name, double _bal, int _checksThisMonth)
    {
        result r = bankAccount::init(_name);
        assert((r.gMessage(), r.gSuccess()));

        r = bankAccount::deposit(_bal);
        assert((r.gMessage(), r.gSuccess()));

        assert(("Given value for checks this month is less than 0 or greater than the check limit.", _checksThisMonth <= gCHECK_LIMIT()));
        checksThisMonth = _checksThisMonth;
    }

    int gCHECK_LIMIT() {return 50;}
    double gSERVICE_CHARGE_AMOUNT() { return 9.99;}

    int gChecksThisMonth() { return checksThisMonth;}

    result didThisAccountWriteThisCheck(digitalCheck check)
    {
        return checkingAccount::didThisAccountWriteThisCheck(check);
    }

    digitalCheck * writeCheck(std::string signer, std::string recipient,
                              double amount, std::string date, int accountNumber)
    {
        if (checksThisMonth == gCHECK_LIMIT())
        {
            return NULL;
        }

        digitalCheck check(signer, recipient, amount, date, accountNumber);
        writtenChecks.push_back(check);
        return &writtenChecks[writtenChecks.size() -1];
    }

    result receiveCheck(digitalCheck c)
    {
        result r = checkingAccount::isThisAccountSupposedToReceiveThisCheck(c);
        if (r.gSuccess() == false) { return r; }

        r = checkingAccount::deposit(c.gAmount());
        if (r.gSuccess() == false) { return r; }

        receivedChecks.push_back(c);
        time_t now = time(0);
        dateReceivedChecks.push_back(std::ctime(&now));

        return result(true, "Check from " + c.gSigner() + " to " + c.gRecipient() +" deposited.");
    }

    result payServiceCharge()
    {
        return withdraw(gSERVICE_CHARGE_AMOUNT());
    }

    std::string getMonthlyStatement()
    {
        return "Account Info: "
                + std::string("\n    Account Type: Service Charge Checking")
                + std::string("\n    ") + std::string("Name: ") + gName()
                + std::string("\n    ") + std::string("Account Number: ") + std::to_string(gAccountNumber())
                + std::string("\n    ") + std::string("Balance: $") + roundToLeastSignificantOrHundredth(std::to_string(gBalance()))
                + std::string("\n    ") + std::string("Checks written this month: ") + std::to_string(checksThisMonth)
                + std::string("\n    ") + std::string("Check Limit: ") + std::to_string(gCHECK_LIMIT())
                + std::string("\n    ") + std::string("Monthly Service Charge: $") + roundToLeastSignificantOrHundredth(std::to_string(gSERVICE_CHARGE_AMOUNT()));

    }
};

/////////////////////////////////////
/*
noServiceChargeChecking
    Inherits from checkingAccount
    Features
        No monthly service charge
        Pays interest
        Limited number of checks
        Requires minimum balance
*/
class noServiceChargeChecking : public checkingAccount
{

protected:
    int checksThisMonth = 0;
    double interest = 1.0001;

public:

    noServiceChargeChecking(std::string _name, double _bal, int _checksThisMonth, double _interest)
    {
        result r = checkingAccount::init(_name);
        assert((r.gMessage(), r.gSuccess()));

        r = checkingAccount::deposit(_bal);
        assert((r.gMessage(), r.gSuccess()));
        assert(balance >= gMIN_BALANCE() && "Balance must be greater than or equal to MIN_BALANCE");

        assert(_checksThisMonth <= gCHECK_LIMIT() && "Given value for checks this month is less than 0 or greater than the check limit.");
        checksThisMonth = _checksThisMonth;

        assert(_interest >= gMIN_INTEREST() && _interest <= gMAX_INTEREST() && "Interest is an invalid value.");
        interest = _interest;
    }

    double gMIN_BALANCE() { return 50 ; }
    double gMIN_INTEREST(){ return 1.001; }
    double gMAX_INTEREST(){ return 1.9999;}
    int gCHECK_LIMIT() {return 50;}

    int gChecksThisMonth() { return checksThisMonth;}
    double gInterestRate() {return interest;}

    result didThisAccountWriteThisCheck(digitalCheck check)
    {
        return checkingAccount::didThisAccountWriteThisCheck(check);
    }

    digitalCheck * writeCheck(std::string signer, std::string recipient, double amount, std::string date, int accountNumber)
    {
        if (checksThisMonth == gCHECK_LIMIT())
        {
            return NULL;
        }

        digitalCheck check(signer, recipient, amount, date, accountNumber);
        writtenChecks.push_back(check);
        return &writtenChecks[writtenChecks.size() -1];
    }

    result receiveCheck(digitalCheck c)
    {
        result r = checkingAccount::isThisAccountSupposedToReceiveThisCheck(c);
        if (r.gSuccess() == false) { return r; }

        r = checkingAccount::deposit(c.gAmount());
        if (r.gSuccess() == false) { return r; }

        receivedChecks.push_back(c);
        time_t now = time(0);
        dateReceivedChecks.push_back(std::ctime(&now));

        return result(true, "Check from " + c.gSigner() + " to " + c.gRecipient() +" deposited.");
    }

    result withdraw(const double givenAmount)
    {
        double actualAmount = givenAmount;
        std::string supplementaryMess = "";
        if (balance - givenAmount < gMIN_BALANCE())
        {
            actualAmount = balance - gMIN_BALANCE();
            supplementaryMess = " -- Supplementary Message: Withdraw amount adjusted to "
                    + std::to_string(actualAmount) + "to avoid bringing account below minimum balance.";
        }

        result r = bankAccount::withdraw(actualAmount);

        return result(r.gSuccess(), r.gMessage() + supplementaryMess);
    }

    std::string getMonthlyStatement()
    {
        return std::string("Account Info: ")
                + std::string("\n    Account Type: No Service Charge Checking")
                + std::string("\n    ") + std::string("Name: ") + gName()
                + std::string("\n    ") + std::string("Account Number: ") + std::to_string(gAccountNumber())
                + std::string("\n    ") + std::string("Balance: $") + roundToLeastSignificantOrHundredth(std::to_string(gBalance()))
                + std::string("\n    ") + std::string("Minimum Balance: $") + roundToLeastSignificantOrHundredth(std::to_string(gMIN_BALANCE()))
                + std::string("\n    ") + std::string("Checks written this month: ") + std::to_string(checksThisMonth)
                + std::string("\n    ") + std::string("Check Limit: ") + std::to_string(gCHECK_LIMIT())
                + std::string("\n    ") + std::string("Interest: ") + roundToLeastSignificantOrHundredth(std::to_string(interest)) + "%";
    }
};

//////////////////////////////////////
/* highInterestChecking
    - No monthly service charge
    - higher interest than noServiceChargeChecking
    - minimum balance
*/
class highInterestChecking : public noServiceChargeChecking
{
public :
    highInterestChecking(std::string _name, double _bal, int _checksThisMonth, double _interest)
            : noServiceChargeChecking(_name, _bal, _checksThisMonth, _interest)
    { }

    double gMIN_BALANCE() { return 500 ; }
    double gMIN_INTEREST(){ return 1.01; }

    std::string getMonthlyStatement()
    {
        return std::string("Account Info: ")
                + std::string("\n    Account Type: High Interest Checking")
                + std::string("\n    ") + std::string("Name: ") + gName()
                + std::string("\n    ") + std::string("Account Number: ") + std::to_string(gAccountNumber())
                + std::string("\n    ") + std::string("Balance: $") + roundToLeastSignificantOrHundredth(std::to_string(gBalance()))
                + std::string("\n    ") + std::string("Minimum Balance: $") + roundToLeastSignificantOrHundredth(std::to_string(gMIN_BALANCE()))
                + std::string("\n    ") + std::string("Checks written this month: ") + std::to_string(checksThisMonth)
                + std::string("\n    ") + std::string("Check Limit: ") + std::to_string(gCHECK_LIMIT())
                + std::string("\n    ") + std::string("Interest: ") + roundToLeastSignificantOrHundredth(std::to_string(interest)) + "%";
    }
};


#endif // CHECKING_H
