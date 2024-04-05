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

    const std::string gName() {return name;}
    const unsigned int gAccountNumber() {return accountNumber;}
    const double gBalance() {return balance;}
    const double gInterestRate() {return interest;}

    const std::string getMonthlyStatement()
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

    const std::string gName() {return name;}
    const unsigned int gAccountNumber() {return accountNumber;}
    const double gBalance() {return balance;}
    const double gInterestRate() {return interest;}

    result deposit(const double amount)
    {
        return bankAccount::deposit(amount);
    }

    result withdraw(const double givenAmount)
    {
        double actualAmount = givenAmount;
        if (balance - givenAmount < MIN_BALANCE)
        {
            actualAmount -= MIN_BALANCE;
        }

        result r = bankAccount::withdraw(actualAmount);
        return r;
    }

    const std::string getMonthlyStatement()
    {
        return "Not implemented";
    }

};
#endif // SAVINGS_H


