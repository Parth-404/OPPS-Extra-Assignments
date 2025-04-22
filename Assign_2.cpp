#include <bits/stdc++.h>
using namespace std;

class BankProfile {
public:
    string holderName;
    int accountNumber;
    string accountType;
    float balance;

    BankProfile(string name, int num, string type, float initialBalance)
        : holderName(name), accountNumber(num), accountType(type), balance(initialBalance) {}

    void displayBalance() {
        cout << fixed << setprecision(2);
        cout << "Current Balance: ₹" << balance << endl;
    }

    void addFunds() {
        float depositAmount;
        cout << "Enter amount to deposit: ";
        cin >> depositAmount;

        balance += depositAmount;
        cout << "₹" << depositAmount << " deposited successfully.\n";
        cout << "Updated Balance: ₹" << balance << endl;
    }

    void addFunds(float interestAmount) {
        balance += interestAmount;
        cout << "₹" << interestAmount << " interest added.\n";
        cout << "Updated Balance: ₹" << balance << endl;
    }

    void withdrawFunds() {
        float withdrawAmount;
        cout << "Enter amount to withdraw: ";
        cin >> withdrawAmount;

        if (withdrawAmount > balance) {
            cout << "Error: Insufficient balance.\n";
        } else {
            balance -= withdrawAmount;
            cout << "₹" << withdrawAmount << " withdrawn successfully.\n";
            cout << "Remaining Balance: ₹" << balance << endl;
        }
    }
};

class SmartSaver : public BankProfile {
public:
    SmartSaver(string name, int num, string type, float initialBalance)
        : BankProfile(name, num, type, initialBalance) {}

    void calculateInterest(float rate, int timeYears) {
        float interest = balance * pow((1 + rate / 100), timeYears) - balance;
        cout << fixed << setprecision(2);
        cout << "Interest Calculated: ₹" << interest << endl;
        addFunds(interest);
    }
};

class QuickCurrent : public BankProfile {
    const float minimumRequired = 1000.0;
    const float serviceFee = 100.0;

public:
    QuickCurrent(string name, int num, string type, float initialBalance)
        : BankProfile(name, num, type, initialBalance) {}

    void validateMinimumBalance() {
        if (balance < minimumRequired) {
            balance -= serviceFee;
            cout << "Service charge of ₹" << serviceFee << " applied for low balance.\n";
            cout << "New Balance: ₹" << balance << endl;
        }
    }
};

int main() {
    float startingBalance = 100000.0;

    cout << "--- Savings Account Operations ---\n";
    SmartSaver saver("Parth", 1001, "Savings", startingBalance);
    saver.addFunds();
    saver.withdrawFunds();
    saver.displayBalance();
    saver.calculateInterest(5.0, 3);

    cout << "\n--- Current Account Operations ---\n";
    QuickCurrent current("Parth", 1002, "Current", startingBalance);
    current.addFunds();
    current.withdrawFunds();
    current.displayBalance();
    current.validateMinimumBalance();

    return 0;
}
