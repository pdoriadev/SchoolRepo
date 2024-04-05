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
protected:
    std::string name = "";
    double balance = 0;

    unsigned int accountNumber = 0;
    bool hasAccountNumber = false;

    static unsigned int generateAccountNumber()
    {
        static unsigned int number = 0;
        number++;
        return number;
    }

public:

    const std::string gName() {return name;}
    const unsigned int gAccountNumber() {return accountNumber;}
    const double gBalance() {return balance;}

    result init(const std::string _name)
    {
        resultSettable r;
        if (r.gSuccess() == true)
        {
            return result(false, "Account has already been created. Cannot re-initialize account.");
        }

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

        return result(r.success, r.message);
    }

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

    virtual const std::string getMonthlyStatement() = 0;
};


#endif // BANKACCOUNT_H
