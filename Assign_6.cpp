#include <iostream>
using namespace std;

class DB;

class DM {
    int meters;
    int centimeters;
public:
    DM() : meters(0), centimeters(0) {}
    DM(int m, int cm) : meters(m), centimeters(cm) {}

    void getInput() {
        cin >> meters >> centimeters;
    }

    void printDistance() {
        cout << "Distance: " << meters << " meters, " << centimeters << " centimeters" << endl;
    }

    friend DM convertAndAdd(DM, DB);
};

class DB {
    int feet;
    int inches;
public:
    DB() : feet(0), inches(0) {}
    DB(int f, int in) : feet(f), inches(in) {}

    void getInput() {
        cin >> feet >> inches;
    }

    void printDistance() {
        cout << "Distance: " << feet << " feet, " << inches << " inches" << endl;
    }

    friend DM convertAndAdd(DM, DB);
};

DM convertAndAdd(DM d1, DB d2) {
    float metricTotal = d1.meters + d1.centimeters / 100.0;
    float imperialTotal = d2.feet + d2.inches / 12.0;
    float convertedMeters = imperialTotal * 0.3048;
    float finalDistance = metricTotal + convertedMeters;

    int resMeters = static_cast<int>(finalDistance);
    int resCentimeters = static_cast<int>((finalDistance - resMeters) * 100);

    return DM(resMeters, resCentimeters);
}

int main() {
    DM distMetric;
    DB distImperial;

    cout << "Enter distance in meters and centimeters: ";
    distMetric.getInput();

    cout << "Enter distance in feet and inches: ";
    distImperial.getInput();

    DM totalDistance = convertAndAdd(distMetric, distImperial);
    totalDistance.printDistance();

    return 0;
}
