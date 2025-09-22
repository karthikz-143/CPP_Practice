#include <iostream>
#include "Account.h"

// Constructor
Account::Account(int initialBalance) {
    if (initialBalance >= 0) {
        balance = initialBalance;
    } else {
        balance = 0;
        std::cout << "Error: Initial balance was invalid. Balance set to 0." << std::endl;
    }
}

// Add amount to balance
void Account::credit(int amount) {
    balance += amount;
}

// Withdraw amount from balance
void Account::debit(int amount) {
    if (amount > balance) {
        std::cout << "Debit amount exceeded account balance." << std::endl;
    } else {
        balance -= amount;
    }
}

// Get the current balance
int Account::getBalance() const {
    return balance;
}
