#ifndef ASSIGNMENT2_OOP_BANK_SYSTEM_LIB_H
#define ASSIGNMENT2_OOP_BANK_SYSTEM_LIB_H

#include <iostream>
#include <regex>
using namespace std;

class BankAccount
{
    private:

    public:

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

class BankApplication
{
    public:

};

#endif //ASSIGNMENT2_OOP_BANK_SYSTEM_LIB_H
