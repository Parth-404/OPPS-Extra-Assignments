#include <iostream>
#include <unordered_map>
using namespace std;

enum BookStatus { AVAILABLE, ON_LOAN, RESERVED };

class LibraryBook {
    int id;
    BookStatus status;
public:
    LibraryBook(int bookId) : id(bookId), status(AVAILABLE) {}

    int getId() const {
        return id;
    }

    BookStatus getStatus() const {
        return status;
    }

    bool checkOutBook() {
        if (status == AVAILABLE) {
            status = ON_LOAN;
            return true;
        }
        return false;
    }

    bool reserveBook() {
        if (status == ON_LOAN) {
            status = RESERVED;
            return true;
        }
        return false;
    }

    string getStatusString() const {
        switch (status) {
            case AVAILABLE: return "Available";
            case ON_LOAN: return "On Loan";
            case RESERVED: return "Reserved";
        }
        return "Unknown";
    }
};

class LibrarySystem {
    unordered_map<int, LibraryBook> bookCollection;
public:
    void addBook(int bookId) {
        bookCollection[bookId] = LibraryBook(bookId);
    }

    void checkOutBook(int bookId) {
        if (bookCollection.count(bookId)) {
            if (bookCollection[bookId].checkOutBook())
                cout << "Book " << bookId << " checked out.\n";
            else
                cout << "Book " << bookId << " is not available for checkout.\n";
        } else {
            cout << "Book not found.\n";
        }
    }

    void reserveBook(int bookId) {
        if (bookCollection.count(bookId)) {
            if (bookCollection[bookId].reserveBook())
                cout << "Book " << bookId << " reserved.\n";
            else
                cout << "Book " << bookId << " cannot be reserved.\n";
        } else {
            cout << "Book not found.\n";
        }
    }

    void inquireBookStatus(int bookId) {
        if (bookCollection.count(bookId)) {
            cout << "Book " << bookId << " status: " << bookCollection[bookId].getStatusString() << endl;
        } else {
            cout << "Book not found.\n";
        }
    }

    void printLibrarySummary() {
        int total = bookCollection.size(), loan = 0, reserved = 0, available = 0;
        for (const auto& pair : bookCollection) {
            BookStatus s = pair.second.getStatus();
            if (s == ON_LOAN) loan++;
            else if (s == RESERVED) reserved++;
            else if (s == AVAILABLE) available++;
        }
        cout << "Total books in library = " << total << endl;
        cout << "Books on loan = " << loan << endl;
        cout << "Books reserved = " << reserved << endl;
        cout << "Books available = " << available << endl;
    }
};

int main() {
    LibrarySystem library;

    // Adding 100 books to the library
    for (int i = 1; i <= 100; ++i)
        library.addBook(i);

    int choice, bookId;
    while (true) {
        cout << "\nLibrary Menu\n";
        cout << "1. Check out a book\n2. Reserve a book\n3. Inquire book status\n4. Library summary\n5. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter ID of book to check out: ";
            cin >> bookId;
            library.checkOutBook(bookId);
        } else if (choice == 2) {
            cout << "Enter ID of book to reserve: ";
            cin >> bookId;
            library.reserveBook(bookId);
        } else if (choice == 3) {
            cout << "Enter ID of book to inquire: ";
            cin >> bookId;
            library.inquireBookStatus(bookId);
        } else if (choice == 4) {
            library.printLibrarySummary();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
