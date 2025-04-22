#include <iostream>
#include <string>
using namespace std;

class RBI {
public:
    double minInterestRate;
    double minBalance;
    double maxWithdrawalLimit;

    RBI() {
        minInterestRate = 4.0;  
        minBalance = 1000.0;    
        maxWithdrawalLimit = 50000.0;  
    }

    void displayGuidelines() {
        cout << "RBI Guidelines:" << endl;
        cout << "Minimum Interest Rate: " << minInterestRate << "%" << endl;
        cout << "Minimum Balance Required: Rs. " << minBalance << endl;
        cout << "Maximum Withdrawal Limit: Rs. " << maxWithdrawalLimit << endl;
    }
};

class Bank : public RBI {
public:
    string bankName;
    double interestRate;

    Bank(string name, double rate) {
        bankName = name;
        interestRate = (rate >= minInterestRate) ? rate : minInterestRate;
    }

    void displayBankDetails() {
        cout << "Bank Name: " << bankName << endl;
        cout << "Offered Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance Required: Rs. " << minBalance << endl;
        cout << "Maximum Withdrawal Limit: Rs. " << maxWithdrawalLimit << endl;
    }
};

int main() {
    RBI rbi;
    cout << "RBI Banking Guidelines:" << endl;
    rbi.displayGuidelines();

    Bank sbi("State Bank of India", 4.5);
    Bank hdfc("HDFC Bank", 5.0);
    Bank icici("ICICI Bank", 4.2);

    cout << "Bank Details:" << endl;
    sbi.displayBankDetails();
    hdfc.displayBankDetails();
    icici.displayBankDetails();

    return 0;
}
