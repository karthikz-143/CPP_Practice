#include "SavingsAccount.h"


double SavingsAccount::annualInterestRate = 0.0;

// Constructor
SavingsAccount::SavingsAccount(double initialBalance)
{
    if (initialBalance >= 0.0)
    {
        savingsBalance = initialBalance;
    }
    else
    {
        savingsBalance = 0.0;
        std::cout << "Invalid initial balance. Setting balance to 0." << std::endl;
    }
}

// Calculate monthly interest and update balance
void SavingsAccount::calculateMonthlyInterest()
{
    double monthlyInterest = (savingsBalance * annualInterestRate) / 12.0;
    savingsBalance += monthlyInterest;
}


void SavingsAccount::displayBalance() const
{
    std::cout << "Current Balance: $" << savingsBalance << std::endl;
}

// To change the interest rate for all accounts
void SavingsAccount::modifyInterestRate(double newRate)
{
    if (newRate >= 0.0)
    {
        annualInterestRate = newRate;
    }
    else
    {
        std::cout << "Invalid interest rate. Rate unchanged." << std::endl;
    }
}
