#include <bits/stdc++.h>
#include <string>
using namespace std;

class RBI {
protected:
    float minInterestRate;
    float maxWithdrawalLimit;
    float minBalance;
public:
    RBI() {
        minInterestRate = 4.0;
        maxWithdrawalLimit = 1000000;
        minBalance = 10000;
    }
   
    float getMinInterestRate() {
         return minInterestRate;
    }
    
    float getMaxWithdrawalLimit() {
         return maxWithdrawalLimit;
    }
    
    float getMinBalance() {
        return minBalance;
    }
};

class Customer {
private:
    string name;
    string address;
    string phone;
public:
    Customer() : name(""), address(""), phone("") {}
   
    Customer(string n, string addr, string ph) {
        this->name = n;
        this->address = addr;
        this->phone = ph;
    }

    string getName() { return name; }
    string getAddress() { return address; }
    string getPhone() { return phone; }
};

class Account {
protected:
    string accountNumber;
    Customer customer;
    float balance;
public:
    Account() : accountNumber(""), customer(), balance(0) {}
   
    Account(string accNo, Customer cust, float bal) {
        this->accountNumber = accNo;
        this->customer = cust;
        this->balance = bal;
    }
   
    void deposit(float amount) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }
   
    bool withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
            return true;
        }
        cout << "Insufficient balance!" << endl;
        return false;
    }
   
    float getBalance() {
        return balance;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    Customer getCustomer() {
        return customer;
    }
};

class SBI : public RBI {
private:
    Account account;
public:
    SBI() {
        minInterestRate = 4.5;
    }
   
    void createAccount(Customer customer, float initialBalance) {
        string accNo = "SBI123";
        account = Account(accNo, customer, initialBalance);
    }
   
    void displayAccount() {
        cout << "\nSBI Account Details:" << endl;
        cout << "Account Number: " << account.getAccountNumber()
             << " Balance: " << account.getBalance() << endl;
    }
   
    Account getAccount() { return account; }
};

class ICICI : public RBI {
private:
    Account account;
public:
    ICICI() {
        minInterestRate = 5.0;
    }
   
    void createAccount(Customer customer, float initialBalance) {
        string accNo = "ICICI123";
        account = Account(accNo, customer, initialBalance);
    }
   
    void displayAccount() {
        cout << "\nICICI Account Details:" << endl;
        cout << "Account Number: " << account.getAccountNumber()
             << " Balance: " << account.getBalance() << endl;
    }
   
    Account getAccount() { return account; }
};

int main() {
    Customer cust1("Ansh", "123 Main St", "9111");
   
    SBI sbi;
    ICICI icici;
   
    sbi.createAccount(cust1, 5000);
    icici.createAccount(cust1, 10000);
   
    Account sbiAcc = sbi.getAccount();
    Account iciciAcc = icici.getAccount();
   
    sbiAcc.deposit(2000);
    sbiAcc.withdraw(1000);
   
    iciciAcc.deposit(5000);
    iciciAcc.withdraw(2000);
   
    sbi.displayAccount();
    icici.displayAccount();
   
    return 0;
}
