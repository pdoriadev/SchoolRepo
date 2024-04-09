#ifndef SAVINGS_H
#define SAVINGS_H
#include "bankAccount.h"
#include <assert.h>

///////////////////////////////
/*
savingsAccount
    inherits from bankAccount
    Features
        pays interest
*/
class savingsAccount : public bankAccount
{

protected:
    double interest = gMIN_INTEREST();

public:

    savingsAccount (const std::string _name, const double bal, const double _interest)
    {
        result r = bankAccount::init(_name);
        assert((r.gMessage(), r.gSuccess()));

        r = bankAccount::deposit(bal);
        assert((r.gMessage(), r.gSuccess()));

        assert(_interest >= gMIN_INTEREST() && _interest <= gMAX_INTEREST() && "Interest is an invalid value.");
        interest = _interest;
    }

    double gMIN_INTEREST() { return 1.001; }
    double gMAX_INTEREST() { return 1.9999999; }
    double gInterestRate() {return interest;}

    std::string getMonthlyStatement()
    {
        return std::string("Account Info: ")
                + std::string("\n    Account Type: Savings Account")
                + std::string("\n    ") + std::string("Name: ") + gName()
                + std::string("\n    ") + std::string("Account Number: ") + std::to_string(gAccountNumber())
                + std::string("\n    ") + std::string("Balance: $") + roundToLeastSignificantOrHundredth(std::to_string(gBalance()))
                + std::string("\n    ") + std::string("Interest: ") + roundToLeastSignificantOrHundredth(std::to_string(interest)) + "%";
    }
};


///////////////////////////////
/*
highInterestSavings
    inherits from savingsAccount
    Features
        Requires minimum balance
        pays higher interest than typical savings account
*/
class highInterestSavings : public savingsAccount
{
public:
    highInterestSavings(const std::string _name, const double bal, const double _interest) : savingsAccount(_name, bal, _interest)
    {
        assert(balance >= gMIN_BALANCE() && "Balance must be greater than or equal to minimum balance.");
        try
        {
            if (balance < gMIN_BALANCE())
            {
                throw balance;
            }
        }
        catch(double bal)
        {
            std::cout << "Balance must be greater than or equal to minimum balance of " << gMIN_BALANCE()
                        << ". Balance given is: " << bal <<".";
        }
    }

    double gMIN_INTEREST() { return 1.01; }
    double gMIN_BALANCE() { return 300; }

    result withdraw(const double givenAmount)
    {
        double actualAmount = givenAmount;
        std::string supplementaryMess = "";
        if (balance - givenAmount < gMIN_BALANCE())
        {
            actualAmount = balance - gMIN_BALANCE();
            supplementaryMess = " -- Supplementary Message: Withdraw amount adjusted to "
                    + roundToLeastSignificantOrHundredth(std::to_string(actualAmount))
                    + " to avoid bringing account below minimum balance.";
        }

        result r = bankAccount::withdraw(actualAmount);

        return result(r.gSuccess(), r.gMessage() + supplementaryMess);
    }

    std::string getMonthlyStatement()
    {
        return std::string("Monthly Statement: ")
                + std::string("\n    Account Type: High Interest Savings Account")
                + std::string("\n    ") + std::string("Name: ") + gName()
                + std::string("\n    ") + std::string("Account Number: ") + std::to_string(gAccountNumber())
                + std::string("\n    ") + std::string("Balance: $") + roundToLeastSignificantOrHundredth(std::to_string(gBalance()))
                + std::string("\n    ") + std::string("Minimum Balance: $") + roundToLeastSignificantOrHundredth(std::to_string(gMIN_BALANCE()))
                + std::string("\n    ") + std::string("Interest: ") + roundToLeastSignificantOrHundredth(std::to_string(interest)) + "%";
    }

};
#endif // SAVINGS_H


