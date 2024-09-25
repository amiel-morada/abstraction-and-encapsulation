#include <iostream>
using namespace std;

// Base Bank class with basic methods for deposit, withdrawal, and balance checking
class Bank {
public:
    float money = 0; // Account balance

    Bank() {}

    // Deposit function for adding money to the account
    float deposit(){
        float amount;
        cout << "Enter Deposit Amount: ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid deposit amount." << endl;
            return 0;
        }
        money += amount;
        cout << "Deposited: " << amount << endl;
        return amount;
    }

    // Virtual function for withdrawal, implemented by derived classes
    virtual float withdraw() = 0;

    // Function to check the current balance
    void checkBalance() const {
        cout << "Current Balance: " << money << endl;
    }
};

// Savings account class with withdrawal rules (maintaining a minimum balance)
class Savings: public Bank {
    const float MAINTAINING_BALANCE = 1000; // Minimum balance required for savings account

public:
    // Withdrawal function with balance check
    float withdraw() override {
        float amount;
        while (true) {
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Invalid amount." << endl;
                continue;
            }

            float futureBalance = money - amount;

            // Check if balance after withdrawal would fall below the required minimum
            if (futureBalance < MAINTAINING_BALANCE) {
                cout << "You must maintain a minimum of 1000 balance in the savings account." << endl;
                continue;
            }

            if (amount > money) {
                cout << "Insufficient Balance." << endl;
                continue;
            }

            break;
        }

        money -= amount;
        cout << "Withdrawn: " << amount << endl;
        return amount;
    }
};

// Current account class with no minimum balance restriction
class Current: public Bank {
public:
    // Withdrawal function for current account
    float withdraw() override {
        float amount;
        while (true) {
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Invalid amount." << endl;
                continue;
            }

            if (amount > money) {
                cout << "Insufficient Balance." << endl;
                continue;
            }

            break;
        }

        money -= amount;
        cout << "Withdrawn: " << amount << endl;
        return amount;
    }
};

// Menu for savings account operations
void savingsMenu(Savings &savings) {
    int choice;
    do {
        cout << "\nSAVINGS ACCOUNT MENU\n";
        cout << "1 - Deposit\n";
        cout << "2 - Withdraw\n";
        cout << "3 - Check Balance\n";
        cout << "4 - Back\n";
        cout << "Enter: ";
        cin >> choice;

        switch (choice) {
            case 1:
                savings.deposit();
                break;
            case 2:
                savings.withdraw();
                break;
            case 3:
                savings.checkBalance();
                break;
            case 4:
                cout << "Going back to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

// Menu for current account operations
void currentMenu(Current &current) {
    int choice;
    do {
        cout << "\nCURRENT ACCOUNT MENU\n";
        cout << "1 - Deposit\n";
        cout << "2 - Withdraw\n";
        cout << "3 - Check Balance\n";
        cout << "4 - Back\n";
        cout << "Enter: ";
        cin >> choice;

        switch (choice) {
            case 1:
                current.deposit();
                break;
            case 2:
                current.withdraw();
                break;
            case 3:
                current.checkBalance();
                break;
            case 4:
                cout << "Going back to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

// Main menu to choose between account types or exit
void mainMenu() {
    int choice;
    Savings savingsAccount;
    Current currentAccount;

    do {
        cout << "\nMAIN MENU\n";
        cout << "1 - Savings Account\n";
        cout << "2 - Current Account\n";
        cout << "3 - Exit\n";
        cout << "Enter: ";
        cin >> choice;

        switch (choice) {
            case 1:
                savingsMenu(savingsAccount);
                break;
            case 2:
                currentMenu(currentAccount);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

// Main function to initiate the banking system
int main() {
    mainMenu();
    return 0;
}
