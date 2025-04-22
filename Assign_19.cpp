#include <bits/stdc++.h>
using namespace std;

class Rectangle {
public:
    float rectLength;
    float rectBreadth;

    Rectangle() {
        rectLength = 0;
        rectBreadth = 0;
    }

    Rectangle(float length, float breadth) {
        rectLength = length;
        rectBreadth = breadth;
    }

    Rectangle(float side) {
        rectLength = side;
        rectBreadth = side;
    }

    void calculateArea() {
        cout << "Area of Rectangle is " << rectLength * rectBreadth << endl;
    }
};

int main() {
    Rectangle rectangle1;

    Rectangle rectangle2(11, 8);
    rectangle2.calculateArea();

    Rectangle rectangle3(10);
    rectangle3.calculateArea();

    return 0;
}
