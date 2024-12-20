#ifndef CD_H
#define CD_H

#include "bankAccount.h"
#include <ctime>
#include <vector>

///////////////////////////////
/*
certificateOfDeposit
    Inherits from bankAccount
    Features
        Instance variables to store number of CD maturity months
        Pays interest
        Current CD month

*/
class certificateOfDeposit : public bankAccount
{
protected:
    inline static const std::string monthStrings[] = { "Jan", "Feb", "Mar",
        "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    double interest = gMIN_INTEREST();
    int monthCreated = -1;
    int yearCreated = -1;
    int CDPeriod = -1;

    int gCurrentMonth()
    {
        time_t now = time(0);
        std::string time = (std::ctime(&now));
        std::string month = time.substr(4,3);
        for (int i = 0; i < 12; i++)
        {
            if (monthStrings[i] == month)
            {
                return i + 1;
            }
        }

        assert(false && "No matching month was found");
    }

    int gCurrentYear()
    {
        time_t now = time(0);
        std::string time = (std::ctime(&now));
        int year = std::stoi(time.substr(time.length() - 5, 4));
        assert (year >= yearCreated && "Current year cannot be year of CD creation.");\
        return year;
    }

public:

    certificateOfDeposit(std::string _name, double _amount, double _interest,
                         int _monthCreated, int _yearCreated, int _CDPeriod)
    {
        bankAccount::init(_name);

        bankAccount::deposit(_amount);

        assert(_interest >= gMIN_INTEREST() && _interest <= gMAX_INTEREST() && "Interest is not valid value.");
        interest = _interest;

        assert(_monthCreated > 0 && _monthCreated <= 12 && "Month created is invalid");
        monthCreated = _monthCreated;

        assert(_yearCreated > 0 && _yearCreated <= gCurrentYear() && "Year of creation cannot be after current year.");
        yearCreated = _yearCreated;

        assert(_CDPeriod > 0 && "Period of CD is invalid");
        CDPeriod = _CDPeriod;
    }


    double gMIN_INTEREST() {return 1.01;}
    double gMAX_INTEREST() {return 1.99999;}


    int gMonthsTilMatured()
    {
        int currentYear = gCurrentYear();
        int currentMonth = gCurrentMonth();

        int monthsSinceCreation = 0;
        if (currentYear > yearCreated)
        {
            int monthsYearCreated = 13 - monthCreated;
            int monthsInbetweenYears = (currentYear - yearCreated - 1) * 12;

            monthsSinceCreation = monthsYearCreated + monthsInbetweenYears + currentMonth;
        }
        else
        {
            monthsSinceCreation = currentMonth - monthCreated;
        }

        int monthsTilMaturity = CDPeriod - monthsSinceCreation;
        if (monthsTilMaturity < 0)
        {
            monthsTilMaturity = 0;
        }

        return monthsTilMaturity;
    }

    result withdraw(double amount)
    {
        if (gMonthsTilMatured() > 0)
        {
            return result (false, "Withdrawl denied. CD cannot withdraw until matured. "
                           + std::to_string(gMonthsTilMatured()) + " months until CD is matured.");
        }

        return bankAccount::withdraw(amount);
    }

    std::string getMonthlyStatement()
    {
        return "Account Info: "
                + std::string("\n    Account Type: Certificate of Deposit")
                + std::string("\n    ") + std::string("Name: ") + gName()
                + std::string("\n    ") + std::string("Account Number: ") + std::to_string(gAccountNumber())
                + std::string("\n    ") + std::string("Balance: $") + roundToLeastSignificantOrHundredth(std::to_string(gBalance()))
                + std::string("\n    ") + std::string("CD Period: ") + std::to_string(CDPeriod)
                + std::string("\n    ") + std::string("Months til maturity: ") + std::to_string(gMonthsTilMatured())
                + std::string("\n    ") + std::string("Interest: ") + roundToLeastSignificantOrHundredth(std::to_string(interest)) + "%";
    }
};

#endif // CD_H


