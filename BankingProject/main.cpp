//Author.....: Carlos Ortega
//Assignment.: Banking-System Project


#include <iostream>
#include <cassert>

using namespace std;

int main() {
    double balance = 0.0;
    int choice;
    bool running = true;

    while (running) {
        // Display menu
        cout << "\n=== Banking System Menu ===\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: { // Deposit Money
                double deposit;
                cout << "Enter amount to deposit: ";
                cin >> deposit;

                if (deposit > 0) {
                    balance += deposit;
                    cout << "Successfully deposited $" << deposit << ".\n";
                } else {
                    cout << "Invalid deposit amount. Please enter a positive value.\n";
                }
                break;
            }
            case 2: { // Withdraw Money
                double withdraw;
                cout << "Enter amount to withdraw: ";
                cin >> withdraw;

                if (withdraw > 0 && withdraw <= balance) {
                    balance -= withdraw;
                    cout << "Successfully withdrew $" << withdraw << ".\n";
                } else if (withdraw <= 0) {
                    cout << "Invalid withdrawal amount. Please enter a positive value.\n";
                } else {
                    cout << "Insufficient funds. Your current balance is $" << balance << ".\n";
                }
                break;
            }
            case 3: { // Check Balance
                cout << "Your current balance is $" << balance << ".\n";
                break;
            }
            case 4: { // Exit
                cout << "Thank you for using the Banking System. Goodbye!\n";
                running = false;
                break;
            }
            default: { // Invalid Option
                cout << "Invalid choice. Please select an option between 1 and 4.\n";
                break;
            }
        }

        // Assertion to ensure balance is never negative
        assert(balance >= 0 && "Balance should never be negative.");
    }

    return 0;
}