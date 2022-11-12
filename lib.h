#ifndef ASSIGNMENT2_OOP_BANK_SYSTEM_LIB_H
#define ASSIGNMENT2_OOP_BANK_SYSTEM_LIB_H

#include <iostream>
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
        Client();
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
    void add_to_file();
    Client *cptr;
    BankAccount *bptr;

public:
    BankingApplication();
    void run();

    void CreateAccount();
    void Get_client_data();
};


#endif //ASSIGNMENT2_OOP_BANK_SYSTEM_LIB_H
