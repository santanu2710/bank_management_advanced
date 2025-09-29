// Author: Santanu Mandal
// Title:  Simple terminal based bank management app
// Date:   23/09/2025
// Discp:  =======This is an simple terminal based bank management app once the file running ends all data will be lost======

#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

// making class named account to use it as a combination of data
class account {
    // classify the data as public to use it in main function
    public:
    string acc_holder_name;            // string type data :name of the account holder
    int acc_num;                       // taking account number as an integer (6 digit value)
    string password;                   // stored password of the user
    double balance;                    // balance of the user
    vector<double> history;            // transaction history of our user

    //constructor
    account(string name, int num, string pass, double bal)
    {
        acc_holder_name = name;
        acc_num = num;
        password = pass;
        balance = bal;
    }
};

// making an massage function to maintain code readability
void invalid_input_handle()
{
    cout << "sorry invalid input try again: ";
}

void next_line_adder()
{
    cout << endl << "=========================================================" << endl << endl;
}


// main function
int main()
{
    // Initialize a vector of accounts (data structure) named bank
    vector<account> bank;

    // pushing an admin account in the 0th position of the array
    bank.push_back(account("admin", 000000, "admin", 0));


    int user_type_selector;
    int id_input;
    string pass_input;

    // asking about user type according to diffrent user type there will be diffrent funcionalities
    cout << "Welcome, plese choose which type of user you are" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Customer" << endl;

    // taking input from user to find out user type
    cout << "choose 1 or 2: ";
    cin >> user_type_selector;


    // handeling wrong case
    // taking user input unless the value is correct
    while (!(user_type_selector == 1 || user_type_selector == 2))   // if input is true then full expression will true and it's "!"" will breake the loop
    {
        // "massage function" call
        invalid_input_handle();
        // taking input again
        cin >> user_type_selector;
    }





    if (user_type_selector == 1)
    {
        cout << "please enter your id and password" << endl;
        cout << "id: ";
        cin >> id_input;
        cout << "password: ";
        cin >> pass_input;

        while (id_input != 000000 || pass_input != "admin")
        {
            invalid_input_handle(); cout << endl;
            cout << "id: ";
            cin >> id_input;
            cout << "password: ";
            cin >> pass_input;
        }
        
        next_line_adder();

        cout << "As you select Admin option you can do following operations on all the accounts :" << endl;
        cout << "Add account" << endl;
        cout << "Delete account" << endl;
        cout << "Change password" << endl;
        cout << "Diposit" << endl;
        cout << "Withdraw" << endl;
        cout << "Viwe account statement" << endl;
    
    }
    
    
    


    

    return 0;
}