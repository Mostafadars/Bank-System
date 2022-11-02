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
    private:

    public:

};

class Client
{
    private:
        string name;
        string address;
        string phone_number;

    public:
        Client(string c_name, string c_address, string c_phone_number);
        bool isValidPhoneNumber(string input);
};

class BankingApplication{

protected:

    void displayMenu();
    int get_choice();
    Client cli;
    BankAccount bAccount;

public:

    void run();

    void CreateAccount();
};


#endif //ASSIGNMENT2_OOP_BANK_SYSTEM_LIB_H
