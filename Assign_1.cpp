#include <bits/stdc++.h>
using namespace std;

class BankAccount {
protected:
    string holderName;
    int accountNumber;
    string accountType;

public:
    void setDetails(string name, int number, string type) {
        holderName = name;
        accountNumber = number;
        accountType = type;
    }

    void showBalance(float &balance) {
        cout << fixed << setprecision(2);
        cout << "Current Balance: ₹" << balance << endl;
    }

    void addFunds(float &balance) {
        float depositAmount;
        cout << "Enter amount to deposit: ";
        cin >> depositAmount;
        balance += depositAmount;
        cout << "₹" << depositAmount << " deposited successfully.\n";
        cout << "Updated Balance: ₹" << balance << endl;
    }

    void withdrawFunds(float &balance) {
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

class SavingsAccount : public BankAccount {
public:
    void computeInterest(float &balance, float rate, int years) {
        float interest = balance * (pow(1 + rate / 100, years) - 1);
        cout << fixed << setprecision(2);
        cout << "Interest Earned: ₹" << interest << endl;
        balance += interest;
        cout << "Balance after interest: ₹" << balance << endl;
    }
};

class CurrentAccount : public BankAccount {
    const float minimumBalance = 1000.0;
    const float penalty = 100.0;

public:
    void enforceMinimum(float &balance) {
        if (balance < minimumBalance) {
            balance -= penalty;
            cout << "Minimum balance not maintained. ₹" << penalty << " penalty charged.\n";
            cout << "New Balance: ₹" << balance << endl;
        }
    }
};

int main() {
    float balance = 50000.0;

    SavingsAccount saver;
    saver.setDetails("Parth", 101, "Savings");
    saver.addFunds(balance);
    saver.withdrawFunds(balance);
    saver.showBalance(balance);
    saver.computeInterest(balance, 4.5, 2);

    cout << "\n----\n";

    CurrentAccount current;
    current.setDetails("Parth", 102, "Current");
    current.addFunds(balance);
    current.withdrawFunds(balance);
    current.showBalance(balance);
    current.enforceMinimum(balance);

    return 0;
}
