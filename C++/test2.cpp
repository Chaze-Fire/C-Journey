#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sqlite3.h>

// Account types
enum class AccountType {
    SAVINGS,
    CHECKING
};

// Account class
class Account {
protected:
    std::string account_num;
    std::string customer_name;
    std::string customer_address;
    double balance;
    double interest_rate;
    AccountType account_type;
    std::time_t date_created;
    
public:
    Account(std::string num, std::string name, std::string addr, double bal, double rate, AccountType type) : account_num(num), customer_name(name), customer_address(addr), balance(bal), interest_rate(rate), account_type(type) {
        date_created = std::time(nullptr);
    }
    
    virtual ~Account() {
        std::cout << "Account destroyed!\n";
    }
    
    virtual void deposit(double amount) {
        balance += amount;
    }
    
    virtual void withdraw(double amount) {
        if (amount > balance) {
            throw std::invalid_argument("Insufficient funds!");
        }
        
        balance -= amount;
    }
    
    virtual void addInterest() {
        double interest = balance * interest_rate;
        deposit(interest);
    }
    
    virtual void displayInfo() const {
        std::cout << "Account number: " << account_num << "\n";
        std::cout << "Customer name: " << customer_name << "\n";
        std::cout << "Customer address: " << customer_address << "\n";
        std::cout << "Balance: " << balance << "\n";
        std::cout << "Interest rate: " << interest_rate << "\n";
        std::cout << "Date created: " << std::asctime(std::localtime(&date_created)) << "\n";
    }
    
    std::string getAccountNum() const {
        return account_num;
    }
    
    double getBalance() const {
        return balance;
    }
    
    AccountType getAccountType() const {
        return account_type;
    }
};

// Savings account class
class SavingsAccount : public Account {
public:
    SavingsAccount(std::string num, std::string name, std::string addr);
};