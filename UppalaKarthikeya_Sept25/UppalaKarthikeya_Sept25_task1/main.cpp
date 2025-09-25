#include "SavingsAccount.h"

int main()
{
    
    SavingsAccount saver1(2000.0);
    SavingsAccount saver2(3000.0);

    
    SavingsAccount::modifyInterestRate(0.03);

    std::cout << "Balances after applying 3% annual interest (1 month):" << std::endl;
    saver1.calculateMonthlyInterest();
    saver1.displayBalance();

    saver2.calculateMonthlyInterest();
    saver2.displayBalance();

    std::cout << std::endl;

    
    SavingsAccount::modifyInterestRate(0.04);

    std::cout << "Balances after applying 4% annual interest (next month):" << std::endl;
    saver1.calculateMonthlyInterest();
    saver1.displayBalance();

    saver2.calculateMonthlyInterest();
    saver2.displayBalance();

    return 0;
}
