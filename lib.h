#ifndef ASSIGNMENT2_OOP_BANK_SYSTEM_LIB_H
#define ASSIGNMENT2_OOP_BANK_SYSTEM_LIB_H

#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

class BankAccount{

protected:
    string accountID;
    float balance;

public:

    BankAccount(string acc);
    BankAccount(string acc,float bal);
    void CreateAccount();
    bool withdraw(float amount);
    void deposit(float amount);
    string getAccountId();
    float getBalance();
};


class SavingBankAccount : public BankAccount
{
    protected:
        double minimumBalance = 1000.0;

    public:
    SavingBankAccount(string acc,float bal,double min_bal);
    bool withdraw(float amount);
    void deposit(float amount);
};

class Client
{
    private:
        string name;
        string address;
        string phone_number;
        BankAccount *ba;

    public:
        Client(string c_name, string c_address, string c_phone_number);
        bool isValidPhoneNumber(string input);
        string get_name();
        string get_address();
        string get_phone_number();
        void set_bank_account(BankAccount *ba);
        BankAccount* get_bank_account();

};

class BankingApplication{

protected:

    void displayMenu();
    int get_choice();
    Client* cli;
    BankAccount* bAccount;

public:
    BankingApplication();
    void getClientData();
    void CreateAccount();
    void Withdraw();
    void Deposit();
    void run();
};
int number_lines();
void update_file(string id,float new_bal);


#endif //ASSIGNMENT2_OOP_BANK_SYSTEM_LIB_H
