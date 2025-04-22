#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void setPersonInfo(string personName, int personAge) {
        name = personName;
        age = personAge;
    }

    void showPersonInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Account : virtual public Person {
protected:
    string accountNumber;
    double balance;
public:
    void setAccountInfo(string accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
    }

    void showAccountInfo() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class Admin : virtual public Person {
protected:
    string adminID;
    string role;
public:
    void setAdminInfo(string id, string r) {
        adminID = id;
        role = r;
    }

    void showAdminInfo() {
        cout << "Admin ID: " << adminID << ", Role: " << role << endl;
    }
};

class Master : public Account, public Admin {
public:
    void initializeMaster(string n, int a, string accNum, double bal, string id, string r) {
        setPersonInfo(n, a);
        setAccountInfo(accNum, bal);
        setAdminInfo(id, r);
    }

    void displayMaster() {
        cout << "Master Information:" << endl;
        showPersonInfo();
        showAccountInfo();
        showAdminInfo();
    }
};

int main() {
    Master master;
    master.initializeMaster("Rohan Mehta", 27, "ACC891", 3290.50, "ADM305", "Supervisor");
    master.displayMaster();
    return 0;
}
