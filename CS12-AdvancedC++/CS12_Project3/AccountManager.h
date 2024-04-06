#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include <memory>
#include "savings.h"
#include "checking.h"
#include "CD.h"

//Forward delcaration for global static instance
class AccountManager;

class AccountManager
{
    std::vector<serviceChargeChecking> accountsServiceChargeChecking;
    std::vector<noServiceChargeChecking> accountsNoServiceChargeCheckings;
    std::vector<highInterestChecking> accountsHighInterestChecking;
    std::vector<savingsAccount> accountsSavings;
    std::vector<highInterestSavings> accountsHighInterestSavings;
    std::vector<certificateOfDeposit> CDs;

public:
    static AccountManager* getInstance() {
        static AccountManager manager;
        return &manager;
    }

    result AddAccount (std::string accountData)
    {
        size_t pos = accountData.find(' ');
        std::string accountType = accountData.substr(0,pos);


        size_t leftPos = pos+1;
        size_t lastSpace = accountData.find_last_of(' ');
        bool foundLastSpace = false;

        std::string name = "";
        double balance = -1;
        if (accountType == "sc")
        {
            int checksThisMonth = 0;
            for (int i = 0; i < 3; i++)
            {
                if (!foundLastSpace)
                {
                    pos = accountData.find(' ', leftPos);
                    if (pos == lastSpace)
                    {
                        foundLastSpace = true;
                    }
                }
                else
                {
                    pos = accountData.length() - 1;
                }
                assert(("Bad data or bad search", pos != std::string::npos));
                std::string substring = accountData.substr(leftPos, pos - leftPos);

                switch(i)
                {
                    case 0:
                        name = substring;
                        break;
                    case 1:
                        balance = std::stod(substring);
                        break;
                    case 2:
                        checksThisMonth = std::stoul(substring);
                        break;
                    default:
                        assert(("Case has not been accounted for.", false));
                }

                leftPos = pos+1;
            }

            serviceChargeChecking acc(name, balance, checksThisMonth);
            accountsServiceChargeChecking.push_back(acc);
            return result(true, "success");
        }
        else if(accountType == "nsc")
        {
            int checksThisMonth = 0;
            double interest = 0;
            for (int i = 0; i < 4; i++)
            {
                if (!foundLastSpace)
                {
                    pos = accountData.find(' ', leftPos);
                    if (pos == lastSpace)
                    {
                        foundLastSpace = true;
                    }
                }
                else
                {
                    pos = accountData.length() - 1;
                }
                assert(("Bad data or bad search", pos != std::string::npos));
                std::string substring = accountData.substr(leftPos, pos - leftPos);

                switch(i)
                {
                    case 0:
                        name = substring;
                        break;
                    case 1:
                        balance = std::stod(substring);
                        break;
                    case 2:
                        checksThisMonth = std::stoul(substring);
                        break;
                    case 3:
                        interest = std::stod(substring);
                        break;
                    default:
                        assert(("Case has not been accounted for.", false));
                }

                leftPos = pos+1;
            }

            noServiceChargeChecking acc(name, balance, checksThisMonth, interest);
            accountsNoServiceChargeCheckings.push_back(acc);
            return result (true, "success");
        }
        else if(accountType == "hich")
        {
            int checksThisMonth = 0;
            double interest = 0;
            for (int i = 0; i < 4; i++)
            {
                if (!foundLastSpace)
                {
                    pos = accountData.find(' ', leftPos);
                    if (pos == lastSpace)
                    {
                        foundLastSpace = true;
                    }
                }
                else
                {
                    pos = accountData.length() - 1;
                }
                assert(("Bad data or bad search", pos != std::string::npos));
                std::string substring = accountData.substr(leftPos, pos - leftPos);

                switch(i)
                {
                    case 0:
                        name = substring;
                        break;
                    case 1:
                        balance = std::stod(substring);
                        break;
                    case 2:
                        checksThisMonth = std::stoul(substring);
                        break;
                    case 3:
                        interest = std::stod(substring);
                        break;
                    default:
                        assert(("Case has not been accounted for.", false));
                }

                leftPos = pos+1;
            }

            highInterestChecking acc(name, balance, checksThisMonth, interest);
            accountsHighInterestChecking.push_back(acc);
            return result (true, "success");
        }
        else if(accountType == "sav")
        {
            double interest = 0;
            for (int i = 0; i < 3; i++)
            {
                if (!foundLastSpace)
                {
                    pos = accountData.find(' ', leftPos);
                    if (pos == lastSpace)
                    {
                        foundLastSpace = true;
                    }
                }
                else
                {
                    pos = accountData.length() - 1;
                }
                assert(("Bad data or bad search", pos != std::string::npos));
                std::string substring = accountData.substr(leftPos, pos - leftPos);

                switch(i)
                {
                    case 0:
                        name = substring;
                        break;
                    case 1:
                        balance = std::stod(substring);
                        break;
                    case 2:
                        interest = std::stod(substring);
                        break;
                    default:
                        assert(("Case has not been accounted for.", false));
                }

                leftPos = pos+1;
            }

            savingsAccount acc = savingsAccount(name, balance, interest);
            accountsSavings.push_back(acc);
            return result (true, "success");
        }
        else if(accountType == "hisav")
        {
            double interest = 0;
            for (int i = 0; i < 3; i++)
            {
                if (!foundLastSpace)
                {
                    pos = accountData.find(' ', leftPos);
                    if (pos == lastSpace)
                    {
                        foundLastSpace = true;
                    }
                }
                else
                {
                    pos = accountData.length() - 1;
                }
                assert(("Bad data or bad search", pos != std::string::npos));
                std::string substring = accountData.substr(leftPos, pos - leftPos);

                switch(i)
                {
                    case 0:
                        name = substring;
                        break;
                    case 1:
                        balance = std::stod(substring);
                        break;
                    case 2:
                        interest = std::stod(substring );
                        break;
                    default:
                        assert(("Case has not been accounted for.", false));
                }

                leftPos = pos+1;
            }

            highInterestSavings acc = highInterestSavings(name, balance, interest);
            accountsHighInterestSavings.push_back(acc);
            return result (true, "success");
        }
        else if(accountType == "cd")
        {
            double interest = 0;
            for (int i = 0; i < 3; i++)
            {
                if (!foundLastSpace)
                {
                    pos = accountData.find(' ', leftPos);
                    if (pos == lastSpace)
                    {
                        foundLastSpace = true;
                    }
                }
                else
                {
                    pos = accountData.length() - 1;
                }
                assert(("Bad data or bad search", pos != std::string::npos));
                std::string substring = accountData.substr(leftPos, pos - leftPos);

                switch(i)
                {
                    case 0:
                        name = substring;
                        break;
                    case 1:
                        balance = std::stod(substring);
                        break;
                    case 2:
                        interest = std::stod(substring );
                        break;
                    default:
                        assert(("Case has not been accounted for.", false));
                }

                leftPos = pos+1;
            }

            highInterestSavings acc = highInterestSavings(name, balance, interest);
            accountsHighInterestSavings.push_back(acc);
            return result (true, "success");

            return result (true, "success");
        }

        return result (false, "Failed to interpret accountData");
   }



};

#endif // ACCOUNTMANAGER_H
