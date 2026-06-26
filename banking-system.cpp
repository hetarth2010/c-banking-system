#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    string accountType;
    double balance;
    int pin;

public:
    // Function to create a new bank account
    void createAccount(int accNum) {
        accountNumber = accNum;
        cin.ignore(); // Clear input buffer
        cout << "Enter Account Holder Name: ";
        getline(cin, accountHolderName);
        cout << "Enter Account Type (Savings/Current): ";
        cin >> accountType;
        cout << "Set a 4-Digit Security PIN: ";
        cin >> pin;
        cout << "Enter Initial Deposit Amount: $";
        cin >> balance;
        cout << "\n🎉 Account created successfully! Your Account Number is: " << accountNumber << "\n";
    }

    // Getter for account number validation
    int getAccountNumber() {
        return accountNumber;
    }

    // Verification method for secure operations
    bool verifyPin() {
        int enteredPin;
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPin;
        return (enteredPin == pin);
    }

    // Function to view details
    void showAccountDetails() {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name   : " << accountHolderName << endl;
        cout << "Account Type  : " << accountType << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << ". New Balance: $" << balance << "\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance! Transaction failed.\n";
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount!\n";
        } else {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << ". Remaining Balance: $" << balance << "\n";
        }
    }
};

int main() {
    vector<BankAccount> bank;
    int choice, accNumberCounter = 1001; // Auto-incrementing account numbers

    while (true) {
        cout << "\n========= BANKING SYSTEM MENU =========" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 5) {
            cout << "Thank you for banking with us! Goodbye.\n";
            break;
        }

        if (choice == 1) {
            BankAccount newAcc;
            newAcc.createAccount(accNumberCounter++);
            bank.push_back(newAcc);
            continue;
        }

        // Processing operations for existing accounts
        int targetAcc;
        cout << "Enter Account Number: ";
        cin >> targetAcc;

        bool found = false;
        for (size_t i = 0; i < bank.size(); i++) {
            if (bank[i].getAccountNumber() == targetAcc) {
                found = true;
                
                if (!bank[i].verifyPin()) {
                    cout << "❌ Incorrect PIN. Access Denied!\n";
                    break;
                }

                if (choice == 2) {
                    double amt;
                    cout << "Enter deposit amount: $";
                    cin >> amt;
                    bank[i].deposit(amt);
                } 
                else if (choice == 3) {
                    double amt;
                    cout << "Enter withdrawal amount: $";
                    cin >> amt;
                    bank[i].withdraw(amt);
                } 
                else if (choice == 4) {
                    bank[i].showAccountDetails();
                }
                break;
            }
        }

        if (!found) {
            cout << "❌ Account not found!\n";
        }
    }
    return 0;
}
