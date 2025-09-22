#include <iostream>
#include "Account.h"

int main() {
    // Create two Account objects
    // valid initial balance
    Account account1(50);   
    // invalid initial balance
    Account account2(-7);   

    std::cout << "account1 balance: " << account1.getBalance() << std::endl;
    std::cout << "account2 balance: " << account2.getBalance() << std::endl;

    // Credit account1
    std::cout << "\nAdding 25 to account1 balance." << std::endl;
    account1.credit(25);
    std::cout << "account1 balance: " << account1.getBalance() << std::endl;

    // Debit account1 with a valid amount
    std::cout << "\nWithdrawing 30 from account1 balance." << std::endl;
    account1.debit(30);
    std::cout << "account1 balance: " << account1.getBalance() << std::endl;

    // Debit account1 with an invalid amount
    std::cout << "\nAttempting to withdraw 100 from account1 balance." << std::endl;
    account1.debit(100);
    std::cout << "account1 balance: " << account1.getBalance() << std::endl;

    return 0;
}
