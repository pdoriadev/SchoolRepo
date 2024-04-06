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
    double interest = gMIN_INTEREST();
    unsigned int monthCreated = 0;
    unsigned int yearCreated = 0;
    unsigned int CDPeriod = 0;
    inline static const std::string monthStrings[] = { "Jan", "Feb", "Mar", "Apr", "May"
        "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    unsigned int gCurrentMonth()
    {
        time_t now = time(0);
        std::string time = (std::ctime(&now));
        std::string month = time.substr(3,3);
        for (int i = 0; i < 12; i++)
        {
            if (monthStrings[i] == month)
            {
                return i + 1;
            }
        }

        assert(false && "No matching month was found");
    }

    unsigned int gCurrentYear()
    {
        time_t now = time(0);
        std::string time = (std::ctime(&now));
        unsigned int year = std::stoul(time.substr(time.length() - 5, 4));
        assert (year >= yearCreated && "Current year cannot be year of CD creation.");\
        return year;
    }
public:

    certificateOfDeposit(std::string _name, double _amount, double _interest,
                         unsigned int _monthCreated, unsigned int _yearCreated, unsigned int _CDPeriod)
    {
        bankAccount::init(_name);
        bankAccount::deposit(_amount);
        assert(_interest >= gMIN_INTEREST() && _interest <= gMAX_INTEREST() && "Interest is not valid value.");
        interest = _interest;

        assert(monthCreated > 0 && monthCreated <= 12 && "Month created is invalid");
        monthCreated = _monthCreated;
        assert(_CDPeriod > 0 && _CDPeriod <= 12 && "Period of CD is invalid");
        CDPeriod = _CDPeriod;

        assert(_yearCreated <= gCurrentYear() && "Year of creation cannot be after current year.");
        yearCreated = _yearCreated;

    }


    double gMIN_INTEREST() {return 1.01;}
    double gMAX_INTEREST() {return 1.99999;}
    bool gIsMatured()
    {
        unsigned int currentYear = gCurrentYear();
        unsigned int currentMonth = gCurrentMonth();
        unsigned int monthsSinceCreation = 0;

        if (yearCreated > currentYear)
        {
            unsigned int monthsYearCreated = 13 - monthCreated;
            unsigned int monthsInbetweenYears = (currentYear - yearCreated - 1) * 12;
            unsigned int monthsThisYear = 13 - currentMonth;

            monthsSinceCreation = monthsYearCreated + monthsInbetweenYears + monthsThisYear;
        }
        else
        {
            monthsSinceCreation = 13 - currentMonth;
        }

        if (monthsSinceCreation >= CDPeriod)
        {
            return true;
        }

        return false;
    }

    // TODO: withdraw override. Stop from withdrawing if CD hasn't matured.

};

#endif // CD_H


