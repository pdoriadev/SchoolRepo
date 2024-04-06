#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include "result.h"
#include "round.h"

/*
 * Abstract class bankAccount class.
 *      Members
 *          Name
 *          Account Number
 *          Balance
 *      Methods
 *          member getters
 *      Abstract methods
 *          deposit
 *          withdraw
 *          create monthly statement
*/
class bankAccount
{
    bool initialized = false;
    bool hasAccountNumber = false;
    int accountNumber = 0;

protected:
    std::string name = "";
    double balance = 0;

    static int generateAccountNumber()
    {
        static int number = 0;
        number++;
        return number;
    }

    result init(const std::string _name)
    {
        if (initialized == true)
        {
            return result(false, "Account has already been created. Cannot re-initialize account.");
        }

        resultSettable r;
        r.success = true;
        r.message = "";

        if (name == "")
        {
            name = _name;
        }
        else
        {
            if (r.message != "")
            {
                r.message += "\n";
            }
            r.message += "Account already has a name associated with it. ";
            r.success = false;
        }

        if (!hasAccountNumber)
        {
            accountNumber = generateAccountNumber();
            hasAccountNumber = true;
            r.message += "Account number successfully generated and assigned";
        }
        else
        {
            if (r.message != "")
            {
                r.message += "\n";
            }
            r.message += " Account number already exists.";
            r.success = false;
        }

        initialized = true;
        return result(r.success, r.message);
    }

public:

    const std::string gName() {return name;}
    const int gAccountNumber() {return accountNumber;}
    const double gBalance() {return balance;}


    result deposit(const double amount)
    {
        std::string str = std::to_string(amount);
        roundToLeastSignificantOrHundredth(&str);

        if (amount <= 0) {
            return result(false, "Failed to deposit. Attempted to add " + str + " 0 or negative amount to balance.");
        }

        balance += amount;
        return result(true, "Deposited $" + str + " to account balance.");
    }
    result withdraw(const double amount)
    {
        std::string str = std::to_string(amount);
        roundToLeastSignificantOrHundredth(&str);

        if (balance - amount < 0) {
            return result(false, "Withdraw amount of $" + str + " exceeds account balance.");
        }

        balance -= amount;
        return result(true, "Withdrew $" + str + ".");;
    }

    virtual std::string getMonthlyStatement() = 0;
};


#endif // BANKACCOUNT_H
