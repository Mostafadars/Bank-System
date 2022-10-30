#include "lib.h"

/*      Functions Of BankAccount Class      */


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

