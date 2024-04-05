#ifndef CHECKING_H
#define CHECKING_H

#include "bankAccount.h"
#include <vector>
#include <ctime>


///////////////////////////////
/// digitalCheck to be sent by checkingAccounts.
///     To be written and received by checking accounts.
///     Contains data. Does not change data.
///     checkingValidater serves as bridge between
///         source checking and recipient checking info.
class digitalCheck
{
private:
    std::string signer;
    std::string recipient = "";
    std::string dateWritten = "";
    double amount = 0;
    unsigned int account = 0;


    unsigned int checkNumber = 0;
    static int generateCheckNumber() {
        unsigned int num = 0;
        num++;
        return num;
    }

    std::string dateOfDeposit = "";

public:

    digitalCheck(std::string _signer, std::string _recipient, double _amount,
                    std::string _dateWritten, unsigned int _account)
    {
        signer = _signer;
        recipient = _recipient;
        dateWritten = _dateWritten;
        amount = _amount;
        account = _account;
        checkNumber = generateCheckNumber();
    }
    ~digitalCheck() {}


    std::string gSigner() { return signer; }
    std::string gRecipient() { return recipient; }
    std::string gDateWritten() { return dateWritten; }
    double gAmount() { return amount; }
    unsigned int gAccountNumber() { return account; }
    unsigned int gCheckNumber() { return checkNumber; }

    void outputCheckContents()
    {
        std::cout << '\n' << signer << "'s check to " << recipient
            << "\n    " << "Amount: $" << amount
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


    const result didThisAccountWriteThisCheck(digitalCheck *check)
    {
        for (unsigned long i = 0; i < writtenChecks.size(); i++)
        {
            if (writtenChecks[i].gSigner() != check->gSigner()) { continue; }
            if (writtenChecks[i].gRecipient() != check->gRecipient()) { continue; }
            if (writtenChecks[i].gDateWritten() != check->gDateWritten()) { continue; }
            if (writtenChecks[i].gAmount() != check->gAmount()) { continue; }
            if (writtenChecks[i].gAccountNumber() != check->gAccountNumber()) { continue; }
            if (writtenChecks[i].gCheckNumber() != check->gCheckNumber()) { continue; }

            return result (true, "Confirmed");
        }

        return result (false, "Check was not written from this account.");
    }

    const result isThisAccountSupposedToReceiveThisCheck (digitalCheck *check)
    {
        bool success = true;
        std::string mess = "";

        if (check->gRecipient() != gName())
        {
            success = false;
            mess += "Name of recipient on check does not match account holder's name for account " + std::to_string(gAccountNumber());
        }

        for (unsigned long i =0; i < receivedChecks.size(); i++)
        {
            if (check->gCheckNumber() == receivedChecks[i].gCheckNumber())
            {
                success = false;
                if (mess != "")
                {
                    mess += '\n';
                }
                mess += "Copy of digital check already deposited in this account. Check should be considered void";
            }
        }


        if (success)
        {
            mess = "Account and check match. Check can be deposited in this account.";
        }

        return result(success, mess);

    }

    virtual digitalCheck writeCheck(std::string signer, std::string recipient, double amount,
                                        std::string date, unsigned int account) = 0;
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
    const unsigned int CHECK_LIMIT = 10;
    const double SERVICE_CHARGE_AMOUNT = 9.99;
    unsigned int checksThisMonth = 0;

public:

    const unsigned int gCheckLimit() {return CHECK_LIMIT;}
    const unsigned int gChecksThisMonth() { return checksThisMonth;}

    const result didThisAccountWriteThisCheck(digitalCheck *check)
    {
        return checkingAccount::didThisAccountWriteThisCheck(check);
    }

    const std::string getMonthlyStatement()
    {
        return std::string("Account Info: ") +
                std::string("\n    ") + std::string("Name: ") + gName()
                + std::string("\n    ") + std::string("Account Number: ") + std::to_string(gAccountNumber())
                + std::string("\n    ") + std::string("Balance: $") + std::to_string(gBalance());
    }

    serviceChargeChecking(std::string _name, double _bal, unsigned int _checksThisMonth)
    {
        result r = bankAccount::init(_name);
        assert((r.gMessage(), r.gSuccess()));

        r = bankAccount::deposit(_bal);
        assert((r.gMessage(), r.gSuccess()));

        assert(("Given value for checks this month is less than 0 or greater than the check limit.", _checksThisMonth >= 0 && _checksThisMonth <= CHECK_LIMIT));
        checksThisMonth = _checksThisMonth;
    }

    result deposit(double amount)
    {
        return checkingAccount::deposit(amount);
    }

    result withdraw(double amount)
    {
        return checkingAccount::withdraw(amount);
    }

    digitalCheck writeCheck(std::string signer, std::string recipient, double amount, std::string date, unsigned int accountNumber)
    {
        digitalCheck check(signer, recipient, amount, date, accountNumber);
        writtenChecks.push_back(check);
        return  check;
    }

    result receiveCheck(digitalCheck c)
    {
        result r = checkingAccount::isThisAccountSupposedToReceiveThisCheck(&c);
        if (r.gSuccess() == false) { return r; }

        receivedChecks.push_back(c);
        time_t now = time(0);
        dateReceivedChecks.push_back(std::ctime(&now));

        return result(true, "Check deposited.");
    }

    result payServiceCharge()
    {
        return withdraw(SERVICE_CHARGE_AMOUNT);
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
    const double MIN_BALANCE = 30;
    const unsigned int CHECK_LIMIT = 50;
    unsigned int checksThisMonth = 0;
    double interest = 1.0001;

public:

    const unsigned int gCheckLimit() {return CHECK_LIMIT;}
    const unsigned int gChecksThisMonth() { return checksThisMonth;}
    const double gInterestRate() {return interest;}

    const std::string getMonthlyStatement()
    {
        return std::string("Account Info: ") +
                std::string("\n    ") + std::string("Name: ") + gName()
                + std::string("\n    ") + std::string("Account Number: ") + std::to_string(gAccountNumber())
                + std::string("\n    ") + std::string("Balance: $") + std::to_string(gBalance())
                + std::string("\n    ") + std::string("Minimum Balance: $") + std::to_string(MIN_BALANCE)
                + std::string("\n    ") + std::string("Check Limit: ") + std::to_string(CHECK_LIMIT)
                + std::string("\n    ") + std::string("Checks written this month: ") + std::to_string(checksThisMonth)
                + std::string("\n    ") + std::string("Interest: ") + std::to_string(interest) + "%";
    }

    const result didThisAccountWriteThisCheck(digitalCheck *check)
    {
        return checkingAccount::didThisAccountWriteThisCheck(check);
    }

    noServiceChargeChecking(std::string _name, double _bal, unsigned int _checksThisMonth, double _interest)
    {
        result r = checkingAccount::init(_name);
        assert((r.gMessage(), r.gSuccess()));

        r = checkingAccount::deposit(_bal);
        assert((r.gMessage(), r.gSuccess()));
        assert(balance >= MIN_BALANCE && "Balance must be greater than or equal to MIN_BALANCE");

        assert(_checksThisMonth >= 0 && _checksThisMonth <= CHECK_LIMIT && "Given value for checks this month is less than 0 or greater than the check limit.");
        checksThisMonth = _checksThisMonth;

        assert(_interest >= 1 && _interest <= 2 && "Interest is an invalid value.");
        interest = _interest;
    }

    digitalCheck writeCheck(std::string signer, std::string recipient, double amount, std::string date, unsigned int accountNumber)
    {
        digitalCheck check(signer, recipient, amount, date, accountNumber);
        writtenChecks.push_back(check);
        return  check;
    }
    result receiveCheck(digitalCheck c)
    {
        result r = checkingAccount::isThisAccountSupposedToReceiveThisCheck(&c);
        if (r.gSuccess() == false) { return r; }

        receivedChecks.push_back(c);
        time_t now = time(0);
        dateReceivedChecks.push_back(std::ctime(&now));

        return result(true, "Check deposited.");
    }

    result deposit (double amount)
    {
        return bankAccount::deposit(amount);
    }

    result withdraw (double amount)
    {
        return bankAccount::withdraw(amount);
        // TODO: Check for min_balance in withdraw
    }
};


#endif // CHECKING_H
