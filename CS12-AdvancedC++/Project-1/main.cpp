#include <QCoreApplication>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

#ifdef linux
    #include <unistd.h>
#endif

#ifdef _WIN64
    #include <windows.h>
#endif

void roundToHundredth(std::string * str) {
    size_t pos = str->find('.') + 3;
    if (pos!= std::string::npos)
    {
        str->erase(pos, str->length() - pos);
    }
}

struct result {
private:
    bool success;
    std::string message;
public:
    bool gSuccess() { return success; }
    std::string gMessage() { return message; }
    result() {};
    result(bool _success, std::string _message) {
        success = _success;
        message = _message;
    }
    ~result() {};
};

class bankAccount {
private:
    std::string accountHolder = "";
    unsigned int accountNumber = 0;

    std::string accountType = "saving";
    double balance = 0;
    double interestRate = 1.01;

    void assignAccountNumber() {
        static int number = 0;
        accountNumber = number;
        number++;
    }

public:

    std::string gAccountHolder() { return accountHolder; }
    unsigned int gAccountNumber() { return accountNumber; }
    std::string gAccountType() { return accountType; }
    double gBalance() { return  balance; }
    double gInterestRate() { return interestRate; }

    void setupAccount(std::string holder) {
        accountHolder = holder;
        assignAccountNumber();
    }
    void setAccountType(std::string type) {
        accountType = type;
    }

    result addToBalance(const double add) {
        if (add <= 0) {
            return result(false, "Attempting to add 0 or negative amount to balance.");
        }
        balance += add;

        std::string str = std::to_string(add);
        roundToHundredth(&str);
        return result(true, "Added $" + str + " to account balance.");
    }
    result withdrawBalance(const double amount) {
        std::string str = std::to_string(amount);
        roundToHundredth(&str);

        if (balance - amount < 0) {
            return result(false, "Withdraw amount of $" + str + " exceeds account balance.");
        }
        return result(true, "Withdrew $" + str + ".");
    }
    double compoundInterestYears(const unsigned int years) {
        return balance * (1.0 + std::pow(interestRate, years));
    }

    bankAccount() {};
    ~bankAccount() {};
};

int main() {
    bankAccount accounts[10];
    for (int i = 0; i < 10; i++) {
        std::string input = "";

        std::cout << "What is the account holder's name: ";
        std::cin >> input;
        accounts[i].setupAccount(input);

        std::cout << "Which account type would you like? Type in savings or checking: ";
        std::cin >> input;
        accounts[i].setAccountType(input);

        int rand;
        std::cout << "Generating balance ";
        for (int i = 0; i < 10; i++) {
            std::cout << ". ";
            std::srand(std::time(nullptr));
            rand = std::rand() % 10000;
            #ifdef _WIN64
            Sleep(50);
            #endif
            #ifdef linux
            sleep(50);
            #endif
        }

        result r;

        if (i % 2 == 0) {
            r = accounts[i].addToBalance((rand % i) * rand * 0.01);
            std::cout << '\n' << r.gMessage() << std::endl;
        }
        else {
            r = accounts[i].addToBalance(std::pow((rand % i) * i, i));
            std::cout << '\n' << r.gMessage() << std::endl;
        }

        if (i % 4 == 0) {
            r = accounts[i].withdrawBalance((4 + i) * 1000);
            std::cout << '\n' << r.gMessage() << std::endl;
        }

        std::string rounded = std::to_string(accounts[i].gBalance());
        roundToHundredth(&rounded);
        std::cout << "\nThe balance for account number '"
            << accounts[i].gAccountNumber() << "' is $"
            << rounded;
        std::string interestRounded = std::to_string(accounts[i].gInterestRate());
        roundToHundredth(&interestRounded);
        rounded = std::to_string(accounts[i].compoundInterestYears(5));
        roundToHundredth(&rounded);
        std::cout << "\nThe projected amount for " << accounts[i].gAccountHolder()
            << "'s account after 5 years at a compound interest rate of "
            << interestRounded << "% once per year is $" << rounded << std::endl;

        std::cout << "\n------------------------------------------" << std::endl;
    }
    return 0;
}
