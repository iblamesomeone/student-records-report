#include<iostream>
using namespace std;

// Class B models a simple bank account with balance management capabilities.
class B {
    double balance = 0;
    double temp_amount = 0;

public:
    // Overloaded output operator to display the current balance
    friend basic_ostream<char, char_traits<char>>& operator<<(basic_ostream<char, char_traits<char>>& os, const B& obj) {
        os << "Balance: " << obj.balance << endl;
        return os;
    }

    // Display the current balance to the user
    void bal_check () {
        cout << "Your Current Balance Is : " << balance << endl << endl;
    }
    
    // Accept deposit amount from user and add it to balance
    void deposit () {
        cout << "Deposition Amount : ";
        cin >> temp_amount;
        balance += temp_amount;
        cout << "Current Balance Now Is : " << balance << endl << endl;
    }
    
    // Accept withdrawal amount from user and subtract it from balance
    void withdraw () {
        if (balance == 0) {
            cout << "Withdrawal not allowed. Your balance is zero." << endl << endl;
            return;
        }
        do {
            cout << "Withdrawal Amount (enter 0 to cancel): ";
            cin >> temp_amount;
            if (temp_amount == 0) {
                cout << "Withdrawal cancelled." << endl << endl;
                return;
            }
            if (temp_amount > balance) {
                cout << "Error: Insufficient balance for this withdrawal. Please enter a smaller amount." << endl << endl;
            } else if (temp_amount < 0) {
                cout << "Error: Withdrawal amount cannot be negative." << endl << endl;
            }
        } while (temp_amount > balance || temp_amount < 0);
        balance -= temp_amount;
        cout << "Current Balance Now Is : " << balance << endl << endl;
    }
};

// Class A inherits from B and provides a menu interface to perform banking operations.
class A : public B {
    // Removed int x;
    // Removed checkin() method as per instructions
};

int main () {
    A atm;
    int pin;
    int z;

    // Loop to verify user PIN until correct PIN (8302) is entered
    do {
        cout << "Enter Your Pin : ";
        cin >> pin;
        if (pin != 8302) {
            cout << "Invalid Pin. Please Retry." << endl;
        }
    } while (pin != 8302);

    cout << endl << "Welcome To Your Account" << endl;

    // Initial prompt for user to select a banking operation
    cout << endl << "1 for Balance Check" << endl << "2 for Deposit" << endl << "3 for Withdraw" << endl << "4 for Exit" << endl << endl << "Choose Your Option : ";
    cin >> z;

    // Main transaction loop allowing multiple operations until user chooses to exit
    while (true) {
        switch (z) {
            case 1: atm.bal_check(); break;
            case 2: atm.deposit(); break;
            case 3: atm.withdraw(); break;
            case 4: cout << "Thank you for using the ATM. Goodbye!" << endl; return 0;
            default: cout << "Error !!! Please Try Again." << endl;
        }

        cout << endl << "1 for Balance Check" << endl << "2 for Deposit" << endl << "3 for Withdraw" << endl << "4 for Exit" << endl << endl << "Choose Your Option : ";
        cin >> z;
    }
}
