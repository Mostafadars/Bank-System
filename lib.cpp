#include "lib.h"

/*      Functions Of BankAccount Class      */
BankAccount :: BankAccount(string acc)
{
    accountID = acc;
    balance = 0;
}

BankAccount :: BankAccount(string acc,float bal)
{
    accountID = acc;
    balance = bal;
}

bool BankAccount :: withdraw(float amount)
{
    if(amount >= balance)
    {
        balance -= amount;
        return true;
    }
    return false;
}

void BankAccount :: deposit(float amount)
{
    balance += amount;
}


/*      Functions Of SavingBankAccount Class      */


/*      Functions Of Client Class      */

Client :: Client(string c_name, string c_address, string c_phone_number)
{
    name = c_name;
    address = c_address;
    phone_number = c_phone_number;
}

bool Client :: isValidPhoneNumber(string input)
{
    regex valid_input("\\\\(\\\\d{3}\\\\) \\\\d{3}-\\\\d{4}");
    return regex_match(input, valid_input);
}

/*      Functions Of BankApplication Class      */


void BankingApplication :: displayMenu()
{
    cout << "Welcome to FCAI Banking Application \n"
            "1. Create a New Account \n"
            "2. List Clients and Accounts \n"
            "3. Withdraw Money \n"
            "4. Deposit Money"<<endl;
}

int BankingApplication :: get_choice()
{
    int choice ;
    cout << "Please Enter Choice =========> ";
    cin >> choice;
    return choice;
}

void BankingApplication :: run()
{
    displayMenu();
    switch (get_choice())
    {
        case 1:

            // Create a New Account

            break;

        case 2:

            // List Clients and Accounts

            break;

        case 3:

            // Withdraw Money

            break;

        case 4:

            // Deposit Money

            break;
    }
}