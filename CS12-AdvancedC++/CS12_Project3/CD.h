#ifndef CD_H
#define CD_H

#include "bankAccount.h"
#include <ctime>
#include <vector>


static const std::string monthStrings[] = { "Jan", "Feb", "Mar", "Apr", "May"
    "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };


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
private:
    unsigned int monthCreated = 0;
    unsigned int CDPeriod = 0;

protected:
    double interest = gMIN_INTEREST();

public:

    certificateOfDeposit(std::string _name, unsigned int _monthCreated,
                            unsigned int _CDPeriod)
    {
        bankAccount::init(_name);
        assert(monthCreated > 0 && monthCreated <= 12 && "Month created is invalid");
        monthCreated = _monthCreated;
        assert(_CDPeriod > 0 && _CDPeriod <= 12 && "Period of CD is invalid");
        CDPeriod = _CDPeriod;
    }

    double gMIN_INTEREST() {return 1.01;}
    double gMAX_INTEREST() {return 1.99999;}
    unsigned int gCurrentMonth()
    {
        time_t now = time(0);
        std::string time = (std::ctime(&now));
        std::string month = time.substr(3,3);
        for (int i = 0; i < 12; i++)
        {
            if (monthStrings[i] == month)
            {
                return i;
            }
        }

        assert(false && "No matching month was found");
    }

    //
};

#endif // CD_H


