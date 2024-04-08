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

    AccountManager man;
    // load in account info from CSV.
    // create account records in account manager.
    std::string line;
    while(std::getline(accountsCSV, line))
    {
        result r = man.AddAccount(line);
        if (r.gSuccess() == false)
        {
            assert((r.gMessage(), r.gSuccess()));
        }
    }
    accountsCSV.close();

    std::cout << "========================================\n"
              << "========== Savings Accounts ============\n";
    std::vector<savingsAccount> * savingsAccounts = man.getSavingsAccounts();
    for (int i = 0; i < savingsAccounts->size(); i++)
    {
        std::cout << std::endl << savingsAccounts->at(i).getMonthlyStatement()
                  << std::endl;
        std::cout << '\n' << savingsAccounts->at(i).bankAccount::deposit(200).gMessage();
        std::cout << '\n' << savingsAccounts->at(i).bankAccount::withdraw(100).gMessage();
        std::cout << std::endl << savingsAccounts->at(i).getMonthlyStatement()
                  << std::endl;
    }

    std::cout << "========================================\n"
              << "==== High Interest Savings Accounts ====\n";
    std::vector<highInterestSavings> * highInterestSavings = man.getHighInterestSavingsAccounts();
    for (int i = 0; i < highInterestSavings->size(); i++)
    {
        std::cout << std::endl << highInterestSavings->at(i).getMonthlyStatement()
                  << std::endl;
        std::cout << '\n' << highInterestSavings->at(i).deposit(100).gMessage();
        std::cout << '\n' << highInterestSavings->at(i).withdraw(200).gMessage();
        std::cout << std::endl << highInterestSavings->at(i).getMonthlyStatement()
                  << std::endl;
    }

    std::cout << "========================================\n"
              << "================ CDs ===================\n";
    std::vector<certificateOfDeposit> * CDs = man.getCDAccounts();
    for (int i = 0; i < CDs->size(); i++)
    {
        std::cout << std::endl << CDs->at(i).getMonthlyStatement()
                  << std::endl;
        std::cout << '\n' << CDs->at(i).withdraw(300).gMessage();
        std::cout << std::endl << CDs->at(i).getMonthlyStatement()
                  << std::endl;
    }



    // Test different functionality of accounts
        // Beginning
            // Get monthly statements
        // General
            // Withdrawal
            // Deposit^
        // service charge Checking
            // write checks
            // receive (and validate) checks
        // no service charge checking
            // write checks
            // receive and validate checks
        // savings
            // Withdrawal
            // Deposit
        // Get monthly statements

     return 0;
}
