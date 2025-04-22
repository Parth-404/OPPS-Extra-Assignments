#include <bits/stdc++.h>
using namespace std;

class PiggieBank {
public:
    double currentAmount;

    PiggieBank() {
        currentAmount = 50.0;
    }

    PiggieBank(double additionalAmount) {
        currentAmount = 50.0 + additionalAmount;
    }

    void showAmount() {
        cout << "Final amount in Piggie Bank: $" << currentAmount << endl;
    }
};

int main() {
    PiggieBank bank1;
    cout << "Piggie Bank 1 (no additional amount):" << endl;
    bank1.showAmount();

    double additionalAmount = 25.0;
    PiggieBank bank2(additionalAmount);
    cout << "\nPiggie Bank 2 (with additional $" << additionalAmount << "):" << endl;
    bank2.showAmount();

    return 0;
}
