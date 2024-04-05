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
private:
    static constexpr double MIN_INTEREST = 1.00001;

protected:
    static constexpr double MAX_INTEREST = 1.9999999;
    double interest = MIN_INTEREST;

public:

    savingsAccount (const std::string _name, const double bal, const double _interest)
    {
        result r = bankAccount::init(_name);
        assert((r.gMessage(), r.gSuccess()));

        r = bankAccount::deposit(bal);
        assert((r.gMessage(), r.gSuccess()));

        assert(_interest >= MIN_INTEREST && _interest <= MAX_INTEREST && "Interest is an invalid value.");
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
private:
    static constexpr double MIN_INTEREST = 1.01;
    const double MIN_BALANCE = 50;

public:
    highInterestSavings(const std::string _name, const double bal, const double _interest) : savingsAccount(_name, bal, _interest)
    {
        assert(balance >= MIN_BALANCE && "Balance must be greater than or equal to minimum balance.");

    }

    result withdraw(const double givenAmount)
    {
        double actualAmount = givenAmount;
        std::string supplementaryMess = "";
        if (balance - givenAmount < MIN_BALANCE)
        {
            actualAmount -= MIN_BALANCE;
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


