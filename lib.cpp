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

string Client :: get_name()
{
    return name;
}

string Client :: get_address()
{
    return address;
}

string Client ::get_phone_number()
{
    return phone_number;
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

void BankingApplication :: CreateAccount()
{
    string name, address, phone ,accountType , id ;
    float balance ;

    cout<<"Please Enter Client Name =========> ";
    getline(cin,name);

    cout<< "Please Enter Client Address =======> ";
    getline(cin,address);

    cout<<"Please Enter Client Phone =======> ";
    cin>>phone;

    cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========> ";
    cin>>accountType;

    cout<<"Please Enter the Starting Balance =========> ";
    cin>>balance;

    id = "FCAI-001";

    cout<<"An account was created with ID "<< id << "and Starting Balance " << balance << " L.E.";

    Client c (name ,address , phone);
    BankAccount b (id ,balance);

}