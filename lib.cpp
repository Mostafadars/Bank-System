#include <fstream>
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

SavingBankAccount ::SavingBankAccount(string acc, float bal, double min_bal) : BankAccount(acc, bal)
{
    minimumBalance = min_bal;
}

bool SavingBankAccount :: withdraw(float amount)
{
    if(amount <= balance && amount > minimumBalance)
    {
        balance -= amount;
        return true;
    }
    return false;
}

void SavingBankAccount :: deposit(float amount)
{
    if(amount >= 100)
    {
        balance += amount;
    }
}

/*      Functions Of Client Class      */

Client :: Client(string c_name, string c_address, string c_phone_number)
{
    name = c_name;
    address = c_address;
    phone_number = c_phone_number;
}

bool Client :: isValidPhoneNumber(string input)
{
    regex valid_input("^01[0125][0-9]{8}$");
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

void Client :: set_bank_account(BankAccount *ba)
{
    this->ba = ba;
}
Client ::Client()
{

}

BankAccount* Client :: get_bank_account()
{
    return ba;
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

BankingApplication ::BankingApplication()
{

}


void BankingApplication :: run()
{
    displayMenu();
    switch (get_choice())
    {
        case 1:
            // Create a New Account
            CreateAccount();
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
    string name, address, phone ,id ;
    char accountType;
    float balance ;
    bool valid_phone = false;
    Client c ;

    cout<<"Please Enter Client Name =========>";
    getline(cin,name);
    cin.ignore();

    cout<< "Please Enter Client Address =======>";
    getline(cin,address);
    cin.ignore();

    while (!valid_phone)
    {
        cout<<"Please Enter Client Phone =======>";
        cin>>phone;
        valid_phone = c.isValidPhoneNumber(phone);
        if (valid_phone)
            break;
    }

    cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========> ";
    cin>>accountType;

    cout<<"Please Enter the Starting Balance =========> ";
    cin>>balance;

    id = "FCAI-001";
    switch (accountType)
    {
        case '1':
        {
            BankAccount b (id ,balance);
            bptr = &b;

            cptr->set_bank_account(bptr);
        }
            break;

        case '2':
        {
            SavingBankAccount sb (id ,balance);
            bptr = &b;

            cptr->set_bank_account(bptr);
        }


            break;

    }





    cout<<"An account was created with ID "<< id << "and Starting Balance " << balance << " L.E.";

    Client cli (name ,address , phone);
    cptr = &cli;




}

//void BankingApplication :: add_to_file()
//{
//    fstream dataFile;
//    dataFile.open
//}
//void BankingApplication ::Get_client_data()
//{
//
//}