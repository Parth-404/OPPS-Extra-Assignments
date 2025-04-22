#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    void show() {
        cout << "This is a shape" << endl;
    }
};

class Polygon : public Shape {
public:
    void show() {
        cout << "Polygon is a shape" << endl;
    }
};

class Rectangle : public Polygon {
public:
    void show() {
        cout << "Rectangle is a polygon" << endl;
    }
};

class Triangle : public Polygon {
public:
    void show() {
        cout << "Triangle is a polygon" << endl;
    }
};

class Square : public Rectangle {
public:
    void show() {
        cout << "Square is a rectangle" << endl;
    }
};

int main() {
    Shape shapeObj;
    Polygon polygonObj;
    Rectangle rectangleObj;
    Triangle triangleObj;
    Square squareObj;
    
    shapeObj.show();
    polygonObj.show();
    rectangleObj.show();
    triangleObj.show();
    squareObj.show();

    return 0;
}
