// Author: Santanu Mandal
// Title:  Simple terminal based bank management app
// Date:   23/09/2025
// Discp:  =======This is an simple terminal based bank management app once the file running ends all data will be lost======


// Header files
#include<iostream>   // standered input output
#include<string>     // string header
#include<cmath>      // math functions
#include<vector>     // cpp vector header
#include <random>

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
//next line adder for beautify the system and increase code readability
void next_line_adder()
{
    cout << endl << "=========================================================" << endl << endl;
}



// Initialize a global vector of accounts (data structure) named bank
vector<account> bank;



// banking operations
void add(){
    string name;
    string new_pass;
    string confirm_pass;
    double entry_balance;


    //random six digit number genaration
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(100000, 999999);

    int random_account_id = distrib(gen);

    for (int i = 1; i < bank.size(); i++)
    {
        if (bank[i].acc_num == random_account_id)
        {
            add();
        }
        
    }

    cout << "new account number is " << random_account_id << endl;

    cin.ignore();
    cout << "please enter account holder name: ";
    getline(cin, name);

    cout << "create password: ";
    cin >> new_pass;
    cout << "confirm password: ";
    cin >> confirm_pass;
    while (new_pass != confirm_pass)
    {
        cout << "Try again: " << endl;

        cout << "create new password: ";
        cin >> new_pass;
        cout << "confirm password: ";
        cin >> confirm_pass;
    }

    cout << "enter the opening balance: ";
    cin >> entry_balance;


    bank.push_back(account(name, random_account_id, new_pass, entry_balance));
    bank[bank.size()-1].history.push_back(entry_balance);    
}





// main function
int main()
{
    // pushing an admin account in the 0th position of the array
    bank.push_back(account("admin", 000000, "admin", 0));


    int user_type_selector;
    int id_input;
    string pass_input;
    int admin_work_choice;

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
        // user input taking if user selected to be an admin
        cout << "please enter your id and password" << endl;
        cout << "id: ";
        cin >> id_input;
        cout << "password: ";
        cin >> pass_input;

        // taking input until he is not an admin
        while (id_input != 000000 || pass_input != "admin")
        {
            invalid_input_handle(); cout << endl;
            cout << "id: ";
            cin >> id_input;
            cout << "password: ";
            cin >> pass_input;
        }

        //successful login massage
        cout << "You successfuly logged in as an admin" << endl;
        next_line_adder();

        //welcome and manual massage for an admin
        cout << "As you select Admin option you can do following operations on all the accounts :" << endl;
        cout << "1. Add account" << endl;
        cout << "2. Delete account" << endl;
        cout << "3. Change password" << endl;
        cout << "4. Diposit" << endl;
        cout << "5. Withdraw" << endl;
        cout << "6. Viwe account statement" << endl;
        cout << "7. log out" << endl;
        
        cout << "please select an option: ";
        cin >> admin_work_choice;

        while (!(admin_work_choice>=1 && admin_work_choice<=7))
        {
            invalid_input_handle();
            cin >> admin_work_choice;
        }



        switch (admin_work_choice)
        {
        case 1:
            add();
            break;
        
        default:
            break;
        }
        

        
    
    }
    
    
    


    

    return 0;
}