#include <iostream>
using namespace std;

class Staff {
private:
    int age;
    int yearsOfService;
    double salary;
public:
    Staff(int a, int y, double s) {
        age = a;
        yearsOfService = y;
        salary = s;
    }

    void setAge(int a) { age = a; }
    void setYearsOfService(int y) { yearsOfService = y; }
    void setSalary(double s) { salary = s; }

    int getAge() { return age; }
    int getYearsOfService() { return yearsOfService; }
    double getSalary() { return salary; }

    int salaryInThousands() {
        return static_cast<int>((salary + 500) / 1000);
    }
};

int main() {
    Staff staff1(30, 5, 55000);
    Staff staff2(45, 20, 98000);

    cout << "Staff 1:\n";
    cout << "Age = " << staff1.getAge() << "\n";
    cout << "Years of Service = " << staff1.getYearsOfService() << "\n";
    cout << "Salary = $" << staff1.getSalary() << "\n";
    cout << "Rounded Salary = $" << staff1.salaryInThousands() << ",000\n\n";

    cout << "Staff 2:\n";
    cout << "Age = " << staff2.getAge() << "\n";
    cout << "Years of Service = " << staff2.getYearsOfService() << "\n";
    cout << "Salary = $" << staff2.getSalary() << "\n";
    cout << "Rounded Salary = $" << staff2.salaryInThousands() << ",000\n";

    return 0;
}
