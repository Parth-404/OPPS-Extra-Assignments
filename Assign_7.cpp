#include <iostream>
using namespace std;

class SimpleCircle {
public:
    int itsRadius;

    SimpleCircle() : itsRadius(5) {}

    SimpleCircle(int r) : itsRadius(r) {}

    ~SimpleCircle() {}

    int fetchRadius() const {
        return itsRadius;
    }

    void updateRadius(int r) {
        itsRadius = r;
    }

    SimpleCircle operator++() {
        SimpleCircle temp;
        temp.itsRadius = ++itsRadius;
        return temp;
    }

    SimpleCircle operator++(int) {
        SimpleCircle temp;
        temp.itsRadius = itsRadius;
        itsRadius++;
        return temp;
    }

    SimpleCircle(const SimpleCircle& obj) {
        itsRadius = obj.itsRadius;
    }

    SimpleCircle operator=(const SimpleCircle obj) {
        itsRadius = obj.itsRadius;
        SimpleCircle result;
        result.itsRadius = itsRadius;
        return result;
    }
};

int main() {
    SimpleCircle c1;
    SimpleCircle c2(9);

    ++c1;
    c2++;

    cout << "Radius of Circle 1: " << c1.fetchRadius() << endl;
    cout << "Radius of Circle 2: " << c2.fetchRadius() << endl;

    c1 = c2;

    cout << "Radius of Circle 1 after assignment: " << c1.fetchRadius() << endl;

    return 0;
}
