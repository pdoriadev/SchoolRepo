// Programming Exercise 5, from pages 897-899,]

#include <fstream>
#include "AccountManager.h"

int main(int argc, char *argv[])
{
    std::ifstream accountsCSV;
    accountsCSV.open("Project3_accounts.txt");
    if (accountsCSV.is_open() == false)
    {
        assert(("Failed to open file", false));
    }

    AccountManager manager;
    // load in account info from CSV.
    // create account records in account manager.
    std::string line;
    while(std::getline(accountsCSV, line))
    {
        result r = manager.AddAccount(line);
        if (r.gSuccess() == false)
        {
            assert((r.gMessage(), r.gSuccess()));
        }
    }
    accountsCSV.close();

    std::cout << "========================================\n"
              << "================ Tests =================\n"
              << "========================================\n\n";


    // Savings
        // Output Account info before operations
        // Withdrawal functionality
        // Deposit functionality
        // Output Account info after operations
    std::cout << "========================================\n"
              << "========== Savings Accounts ============\n";
    std::vector<savingsAccount> * savingsAccounts = manager.getSavingsAccounts();
    for (int i = 0; i < savingsAccounts->size(); i++)
    {
        std::cout << "\n======== " << savingsAccounts->at(i).gName() << "'s Account ";
        std::cout << std::endl << savingsAccounts->at(i).getMonthlyStatement()
                  << std::endl;

        std::cout << '\n' << savingsAccounts->at(i).bankAccount::deposit(200).gMessage();
        std::cout << '\n' << savingsAccounts->at(i).bankAccount::withdraw(100).gMessage();

        std::cout << '\n' << std::endl << savingsAccounts->at(i).getMonthlyStatement()
                  << std::endl;
    }

    // High Interest Savings
        // Output Account info before operations
        // Get monthly statements before using account and after using account.
        // Withdrawal functionality
        // Deposit functionality
        // Output Account info after operations
    std::cout << "========================================\n"
              << "==== High Interest Savings Accounts ====\n";
    std::vector<highInterestSavings> * highInterestSavings = manager.getHighInterestSavingsAccounts();
    for (int i = 0; i < highInterestSavings->size(); i++)
    {
        std::cout << "\n======== " << highInterestSavings->at(i).gName() << "'s Account ";
        std::cout << std::endl << highInterestSavings->at(i).getMonthlyStatement()
                  << std::endl;

        std::cout << '\n' << highInterestSavings->at(i).deposit(100).gMessage();
        std::cout << '\n' << highInterestSavings->at(i).withdraw(200).gMessage();

        std::cout << '\n' << std::endl << highInterestSavings->at(i).getMonthlyStatement()
                  << std::endl;
    }

    // CD
        // Output Account info after operations
        // Check to see if CD is matured. Withdraw if matured.
        // Output Account info after operations
    std::cout << "========================================\n"
              << "================ CDs ===================\n";
    std::vector<certificateOfDeposit> * CDs = manager.getCDAccounts();
    for (int i = 0; i < CDs->size(); i++)
    {
        std::cout << "\n======== " << CDs->at(i).gName() << "'s Account ";
        std::cout << std::endl << CDs->at(i).getMonthlyStatement()
                  << std::endl;

        // test withdraw functionality. Will only withdraw if matured.
        std::cout << '\n' << CDs->at(i).withdraw(300).gMessage();

        std::cout << '\n' << std::endl << CDs->at(i).getMonthlyStatement()
                  << std::endl;
    }



    // Checks are held here before being deposited in the appropriate account.
    std::vector<digitalCheck> checks;


    // Service Charge Checking
        // Output Account info before operations
        // Pay service charge - locks if fails
        // write checks
        // receive checks
        // Withdrawal functionality
        // Deposit functionality
        // output check info
        // Output Account info after operations
    std::cout << "========================================\n"
              << "======= Service Charge Checking ========\n";
    std::vector<serviceChargeChecking> * serviceChargeCheckingAccounts = manager.getServiceChargeCheckingAccounts();
    for (int i = 0; i < serviceChargeCheckingAccounts->size(); i++)
    {
        serviceChargeChecking * checking = &(serviceChargeCheckingAccounts->at(i));

        std::cout << "\n======== " << checking->gName() << "'s Account";
        std::cout << std::endl << checking->getMonthlyStatement()
                  << std::endl;

        // test service charge functionality. If account fails to pay service
            // charge, then account is considered locked. That account cannot
            // withdraw funds or write checks.
        std::cout << '\n' << checking->payServiceCharge().gMessage();

        // test writing check functionality
        if (checking->gName() == "Alfred")
        {
            digitalCheck * c = checking->writeCheck("Amir", checking->gBalance());
            if (c != NULL)
            {
                checks.push_back(*c);
            }
            else std::cout << "\nFailed to write check to Amir for $"
                              + roundToLeastSignificantOrHundredth(std::to_string(checking->gBalance())) + ".";
        }
        else if (checking->gName() == "Ira")
        {
            digitalCheck * c = checking->writeCheck("Bernice", checking->gBalance());
            if (c != NULL)
            {
                checks.push_back(*c);
            }
            else std::cout << "\nFailed to write check to Bernice for $"
                              + roundToLeastSignificantOrHundredth(std::to_string(checking->gBalance())) + ".";
        }
        else if (checking->gName() == "Amir")
        {
            digitalCheck * c = checking->writeCheck("Helios", 1024);
            if (c != NULL)
            {
                checks.push_back(*c);
            }
            else std::cout << "\nFailed to write check to Helios for $1024." << std::endl;

            c = NULL;
            c = checking->writeCheck("Bilbo", 2048);
            if (c != NULL)
            {
                checks.push_back(*c);
            }
            else std::cout << "\nFailed to write check to Bilbo for $2048."  << std::endl;

        }

        // test receive check functionality
        for (int i = 0; i < checks.size(); i++)
        {
            result r = checking->receiveCheck(checks[i]);
            std::cout << '\n' << r.gMessage() << std::endl;
            if (r.gSuccess())
            {
                checks.erase(checks.begin() + i);
            }
        }

        std::cout << '\n' << checking->withdraw(512).gMessage();
        std::cout << '\n' << checking->deposit(1024).gMessage();

        std::cout << '\n' << std::endl << serviceChargeCheckingAccounts->at(i).getMonthlyStatement()
                  << std::endl;
    }


    // No Service Charge Checking
        // Output Account info before operations
        // write checks
        // receive checks
        // Withdrawal functionality
        // Deposit functionality
        // output check info
        // Output Account info after operations
    std::cout << "========================================\n"
              << "====== No Service Charge Checking ======\n";
    std::vector<noServiceChargeChecking> * noServiceChargeCheckingAccounts = manager.getNoServiceChargeCheckingAccounts();
    for (int i = 0; i < noServiceChargeCheckingAccounts->size(); i++)
    {
        noServiceChargeChecking * checking = &(noServiceChargeCheckingAccounts->at(i));

        std::cout << "\n======== " << checking->gName() << "'s Account";
        std::cout << std::endl << checking->getMonthlyStatement()
                  << std::endl;

        // test writing check functionality
        if (checking->gName() == "Bernice")
        {
            digitalCheck * c = checking->writeCheck("Bernice", 512);
            if (c != NULL)
            {
                checks.push_back(*c);
            }
            else std::cout << "\nFailed to write check to Bernice for $512.";
        }
        else if (checking->gName() == "Helios")
        {
            digitalCheck * c = checking->writeCheck("Frodo", 5096);
            if (c != NULL)
            {
                checks.push_back(*c);
            }
            else std::cout << "\nFailed to write check to Frodo for $5096.";
        }

        // test receive check functionality
        for (int i = 0; i < checks.size(); i++)
        {
            result r = checking->receiveCheck(checks[i]);
            std::cout << '\n' << r.gMessage() << std::endl;
            if (r.gSuccess())
            {
                checks.erase(checks.begin() + i);
            }
        }

        std::cout << '\n' << checking->withdraw(512).gMessage();
        std::cout << '\n' << checking->deposit(1024).gMessage();

        std::cout << '\n' << std::endl << noServiceChargeCheckingAccounts->at(i).getMonthlyStatement()
                  << std::endl;
    }


    // High Interest Checking
        // Output Account info before operations
        // write checks
        // receive checks
        // Withdrawal functionality
        // Deposit functionality
        // output check info
        // Output Account info after operations
    std::cout << "========================================\n"
              << "======== High Interest Checking ========\n";
    std::vector<highInterestChecking> * highInterestCheckingAccounts = manager.getHighInterestCheckingAccounts();
    for (int i = 0; i < highInterestCheckingAccounts->size(); i++)
    {
        highInterestChecking * checking = &(highInterestCheckingAccounts->at(i));

        std::cout << "\n======== " << checking->gName() << "'s Account";
        std::cout << std::endl << checking->getMonthlyStatement()
                  << std::endl;

        // test writing check functionality
        if (checking->gName() == "Frodo")
        {
            digitalCheck * c = checking->writeCheck("Bilbo", 512);
            if (c != NULL)
            {
                checks.push_back(*c);
                c->outputCheckContents();
            }
            else std::cout << "\nFailed to write check to Bilbo for $512.";
        }

        // test receive check functionality
        for (int i = 0; i < checks.size(); i++)
        {
            result r = checking->receiveCheck(checks[i]);
            std::cout << '\n' << r.gMessage() << std::endl;
            if (r.gSuccess())
            {
                checks.erase(checks.begin() + i);
            }
        }

        std::cout << '\n' << checking->withdraw(512).gMessage();
        std::cout << '\n' << checking->deposit(1024).gMessage();
        std::cout << '\n' << checking->withdraw(512).gMessage();


        std::cout << '\n' << std::endl << highInterestCheckingAccounts->at(i).getMonthlyStatement()
                  << std::endl;
    }


    if (checks.size() > 0)
    {
        assert(false && "Failed to deposit all checks");
    }


    std::cout << "===========================\n"
              << "====== Test Complete ======\n"
              << "===========================";

     return 0;
}
