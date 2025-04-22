#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string studentName;

    Student(string name = "Unknown") {
        studentName = name;
    }

    void displayStudentName() {
        cout << "Student name: " << studentName << endl;
    }
};

int main() {
    Student student1;
    Student student2("Ansh");

    student1.displayStudentName();
    student2.displayStudentName();

    return 0;
}
