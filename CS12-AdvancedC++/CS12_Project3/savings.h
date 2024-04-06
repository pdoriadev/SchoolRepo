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
class savingsAccount : protected bankAccount
{

protected:
    double interest = gMIN_INTEREST();

public:

    static double gMIN_INTEREST()
    {
        static constexpr double MIN_INTEREST = 1.000001;
        return MIN_INTEREST;
    }

    static double gMAX_INTEREST()
    {
        static constexpr double MAX_INTEREST = 1.9999999;
        return MAX_INTEREST;
    }


    savingsAccount (const std::string _name, const double bal, const double _interest)
    {
        result r = bankAccount::init(_name);
        assert((r.gMessage(), r.gSuccess()));

        r = bankAccount::deposit(bal);
        assert((r.gMessage(), r.gSuccess()));

        assert(_interest >= gMAX_INTEREST() && _interest <= gMAX_INTEREST() && "Interest is an invalid value.");
        interest = _interest;
    }

    const double gInterestRate() {return interest;}

    std::string getMonthlyStatement()
    {
        return "Not implemented";
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
class highInterestSavings : protected savingsAccount
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

    static double gMIN_INTEREST()
    {
        static constexpr double MIN_INTEREST = 1.01;
        return MIN_INTEREST;
    }

    static double gMIN_BALANCE()
    {
        static constexpr double MIN_BALANCE = 50;
        return MIN_BALANCE;
    }

    result withdraw(const double givenAmount)
    {
        double actualAmount = givenAmount;
        std::string supplementaryMess = "";
        if (balance - givenAmount < gMIN_BALANCE())
        {
            actualAmount -= gMIN_BALANCE();
            supplementaryMess = "\n    Supplementary Message: Amount adjusted so as not to exceeded minimum balance.";
        }

        result r = bankAccount::withdraw(actualAmount);

        return result(r.gSuccess(), r.gMessage() + supplementaryMess);
    }

    std::string getMonthlyStatement()
    {
        return "Not implemented";
    }

};
#endif // SAVINGS_H


