#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <iostream>

class SavingsAccount
{
private:
    double savingsBalance;                     // The current balance for this saver
    static double annualInterestRate;          // Common interest rate for all accounts

public:
    // Constructor
    SavingsAccount(double initialBalance);

    // Calculate and add monthly interest to savingsBalance
    void calculateMonthlyInterest();
    void displayBalance() const;
    static void modifyInterestRate(double newRate);
};

#endif // SAVINGS_ACCOUNT_H
