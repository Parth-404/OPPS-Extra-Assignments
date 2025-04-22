#include <iostream>
#include <string>
using namespace std;

class Show {
    string showTime;
    int capacity;
    int reserved;
public:
    Show(string t, int total) : showTime(t), capacity(total), reserved(0) {}

    bool reserveSeats(int seats) {
        if (reserved + seats <= capacity) {
            reserved += seats;
            return true;
        }
        return false;
    }

    int availableSeats() {
        return capacity - reserved;
    }

    void showDetails() {
        cout << "Show at " << showTime << ": " << availableSeats() << " seats available\n";
    }

    string getShowTime() {
        return showTime;
    }
};

int main() {
    Show s1("1:00 PM", 100);
    Show s2("5:00 PM", 100);
    Show s3("8:30 PM", 100);

    int option, seats;
    while (true) {
        cout << "\nMovie Reservation Panel\n";
        cout << "1. Reserve Seats\n";
        cout << "2. Check Seat Availability\n";
        cout << "3. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        if (option == 1) {
            cout << "Select a show:\n1. 1:00 PM\n2. 5:00 PM\n3. 8:30 PM\nEnter option: ";
            cin >> option;
            cout << "Enter number of seats: ";
            cin >> seats;

            bool booked = false;
            if (option == 1) booked = s1.reserveSeats(seats);
            else if (option == 2) booked = s2.reserveSeats(seats);
            else if (option == 3) booked = s3.reserveSeats(seats);

            if (booked) cout << "Seats booked successfully!\n";
            else cout << "Booking failed. Not enough seats.\n";
        }
        else if (option == 2) {
            s1.showDetails();
            s2.showDetails();
            s3.showDetails();
        }
        else if (option == 3) {
            cout << "Thank you for using the system.\n";
            break;
        }
        else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
