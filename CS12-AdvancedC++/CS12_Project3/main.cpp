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

    AccountManager * man = AccountManager::getInstance();
    // load in account info from CSV.
    // create account records in account manager.
    std::string line;
    while(std::getline(accountsCSV, line))
    {
        result r = man->AddAccount(line);
        if (r.gSuccess() == false)
        {
            assert((r.gMessage(), r.gSuccess()));
        }
    }
    accountsCSV.close();



    // Test different functionality of accounts
        // Beginning
            // Get monthly statements
        // General
            // Withdrawal
            // Deposit
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
