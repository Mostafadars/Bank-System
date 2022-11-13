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
    if(amount <= balance)
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

string BankAccount :: getAccountId()
{
    return accountID;
}

float BankAccount :: getBalance()
{
    return balance;
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
    cout << "Please Enter Choice =========>";
    cin >> choice;
    return choice;
}

BankingApplication ::BankingApplication()
{

}
void BankingApplication :: run()
{
    int choice;
    displayMenu();
    choice = get_choice();
    switch(choice)
    {
        case 1:
            CreateAccount();
            break;
        case 2:
            getClientData();
            break;
        case 3:
            Withdraw();
            break;
        case 4:
            Deposit();
            break;

        default:
            cout << "Invalid choice" << endl;
    }


}




void BankingApplication :: CreateAccount()
{
    string name, address, phone ,accountType , id;
    float balance ;

    cin.ignore();
    cout<<"Please Enter Client Name =========> ";
    getline(cin,name);

    cin.ignore();
    cout<< "Please Enter Client Address =======> ";
    getline(cin,address);


    cout<<"Please Enter Client Phone =======>";
    cin>>phone;

    while (true)
    {
        if(cli->isValidPhoneNumber(phone))
            break;
        else
        {
            cout<<"Please Enter Valid Phone =======>";
            cin>>phone;
        }
    }

    cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========>";
    cin>>accountType;

    cout<<"Please Enter the Starting Balance =========>";
    cin>>balance;

    id = "FCAI-";
    string get_last_id = to_string(number_lines());
    for (int i = 0; i < 3 - get_last_id.length() ; ++i)
    {
        id += '0';
    }

    id += get_last_id;


    cout<<"An account was created with ID "<< id << " and Starting Balance " << balance << " L.E.";


    ofstream file("tst.txt", ios :: app);
    BankAccount *ba = new BankAccount(id,balance);
    Client *c = new Client(name, address, phone);
    c->set_bank_account(ba);
    file << c->get_name() << "," << c->get_address() << "," << c->get_phone_number() << "," << c->get_bank_account()->getAccountId() << "," << c->get_bank_account()->getBalance() << endl;
    file.close();

}

void BankingApplication :: getClientData()
{
    ifstream file("tst.txt");
    string name, address, phone, acc_id;
    float bal;
    while(!file.eof())
    {
        getline(file,name,',');
        if (name == "")
            break;

        getline(file,address,',');
        getline(file,phone,',');
        getline(file,acc_id,',');
        file>>bal;


        BankAccount *ba = new BankAccount(acc_id,bal);
        Client *c = new Client(name, address, phone);
        c->set_bank_account(ba);
        string accountHeader = "-------------------- " + c->get_name() + " --------------------";
        cout << accountHeader << endl;
        cout << "Address: " << c->get_address() << endl;
        cout << "Phone Number: " << c->get_phone_number() << endl;
        cout << "Account ID: " << c->get_bank_account()->getAccountId() << endl;
        cout << "Balance: " << c->get_bank_account()->getBalance() << endl;

        delete c;
        delete ba;

        char new_line;
        file.get(new_line);

    }
    file.close();
}


void BankingApplication :: Withdraw()
{
    string acc_id;
    float amount;
    cout << "Enter Account ID:";
    cin >> acc_id;



    ifstream file("tst.txt");
    string name, address, phone, acc_id1;
    float bal;
    while(!file.eof())
    {
        getline(file,name,',');
        if (name == "")
            break;

        getline(file,address,',');
        getline(file,phone,',');
        getline(file,acc_id1,',');
        file>>bal;
        if(acc_id1 == acc_id)
        {
            cout << "Account ID: " << acc_id1 << endl;
            cout << "Account Type: " << endl;
            cout << "Balance: " << bal << endl;
            cout << "Please Enter The Amount to Withdraw:";
            cin >> amount;
            BankAccount *ba = new BankAccount(acc_id1,bal);
            Client *c = new Client(name, address, phone);
            c->set_bank_account(ba);


            if(c->get_bank_account()->withdraw(amount))
            {
                file.close();
                cout << "New Balance: " << c->get_bank_account()->getBalance() << endl;
                update_file(acc_id,c->get_bank_account()->getBalance());
            }
            else
                cout << "Sorry no enough Balance" << endl;
        }
    }
    if(file.is_open())
        file.close();
}


void BankingApplication :: Deposit()
{
    string acc_id;
    float amount;
    cout << "Enter Account ID:";
    cin >> acc_id;

    ifstream file("tst.txt");
    string name, address, phone, acc_id1;
    float bal;
    while(!file.eof())
    {
        getline(file,name,',');
        if (name == "")
            break;

        getline(file,address,',');
        getline(file,phone,',');
        getline(file,acc_id1,',');
        file>>bal;
        if(acc_id1 == acc_id)
        {
            cout << "Account ID: " << acc_id1 << endl;
            cout << "Account Type: " << endl;
            cout << "Balance: " << bal << endl;
            cout << "Please Enter The Amount to Deposit:";
            cin >> amount;
            BankAccount *ba = new BankAccount(acc_id1,bal);
            Client *c = new Client(name, address, phone);
            c->set_bank_account(ba);


            c->get_bank_account()->deposit(amount);
            cout << "New Balance: " << c->get_bank_account()->getBalance() << endl;
            file.close();
            update_file(acc_id,c->get_bank_account()->getBalance());


        }
    }
    if(file.is_open())
        file.close();
}




int number_lines()
{
    char ch;
    int lineNum = 0;
    fstream Target ("tst.txt");

    Target.get(ch);
    while (Target)
    {
        if (ch == '\n')
        {
            lineNum += 1;
        }
        Target.get(ch);
    }
    Target.close();
    return lineNum;

}


void update_file(string id ,float new_bal)
{
    ifstream file("tst.txt");
    ofstream target("new.txt");
    string name, address, phone, acc_id;
    float bal;
    while(!file.eof())
    {
        getline(file,name,',');
        if (name == "")
            break;

        getline(file,address,',');
        getline(file,phone,',');
        getline(file,acc_id,',');
        file>>bal;
        target << name << ',' << address << ',' << phone << ',' <<acc_id << ',';
        if(acc_id == id)
        {
            target << new_bal;
        }
        else
        {
            target << bal;
        }
    }
    file.close();
    target.close();
    remove("tst.txt");
    rename("new.txt","tst.txt");

}