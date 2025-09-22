#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    // Constructor 
    Account(int initialBalance);

    // Add amount to balance
    void credit(int amount);

    // Withdraw amount from balance
    void debit(int amount);

    // Get the current balance
    int getBalance() const;

private:
    int balance;  // Account balance
};

#endif
