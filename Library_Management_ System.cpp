#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable = true;
};

struct Borrower {
    string name;
    vector<string> borrowedBooks;
};

vector<Book> books;
vector<Borrower> borrowers;

const int FINE_PER_DAY = 1;

void addBook() {
    Book newBook;
    cout << "Enter the book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter the book author: ";
    getline(cin, newBook.author);
    cout << "Enter the book ISBN: ";
    getline(cin, newBook.ISBN);
    books.push_back(newBook);
    cout << "Book added to the library!" << endl;
}

void searchBook() {
    int choice;
    cout << "Search by: 1. Title 2. Author 3. ISBN\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    string query;
    cout << "Enter search query: ";
    getline(cin, query);

    bool found = false;
    for (const auto& book : books) {
        if ((choice == 1 && book.title == query) ||
            (choice == 2 && book.author == query) ||
            (choice == 3 && book.ISBN == query)) {
            cout << "Title: " << book.title << ", Author: " << book.author 
                 << ", ISBN: " << book.ISBN << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No books found matching the query." << endl;
    }
}

void addBorrower() {
    Borrower newBorrower;
    cout << "Enter borrower name: ";
    cin.ignore();
    getline(cin, newBorrower.name);
    borrowers.push_back(newBorrower);
    cout << "Borrower added!" << endl;
}

void checkoutBook() {
    string borrowerName, bookISBN;
    cout << "Enter borrower name: ";
    cin.ignore();
    getline(cin, borrowerName);
    
    bool borrowerFound = false;
    Borrower* borrower = nullptr;
    for (auto& b : borrowers) {
        if (b.name == borrowerName) {
            borrowerFound = true;
            borrower = &b;
            break;
        }
    }

    if (!borrowerFound) {
        cout << "Borrower not found!" << endl;
        return;
    }

    cout << "Enter book ISBN to checkout: ";
    getline(cin, bookISBN);
    
    bool bookFound = false;
    for (auto& book : books) {
        if (book.ISBN == bookISBN && book.isAvailable) {
            book.isAvailable = false;
            borrower->borrowedBooks.push_back(bookISBN);
            cout << "Book checked out successfully!" << endl;
            bookFound = true;
            break;
        }
    }

    if (!bookFound) {
        cout << "Book not available for checkout!" << endl;
    }
}

void returnBook() {
    string borrowerName, bookISBN;
    cout << "Enter borrower name: ";
    cin.ignore();
    getline(cin, borrowerName);

    bool borrowerFound = false;
    Borrower* borrower = nullptr;
    for (auto& b : borrowers) {
        if (b.name == borrowerName) {
            borrowerFound = true;
            borrower = &b;
            break;
        }
    }

    if (!borrowerFound) {
        cout << "Borrower not found!" << endl;
        return;
    }

    cout << "Enter book ISBN to return: ";
    getline(cin, bookISBN);

    auto it = find(borrower->borrowedBooks.begin(), borrower->borrowedBooks.end(), bookISBN);
    if (it != borrower->borrowedBooks.end()) {
        borrower->borrowedBooks.erase(it);

        for (auto& book : books) {
            if (book.ISBN == bookISBN) {
                book.isAvailable = true;
                cout << "Book returned successfully!" << endl;
                break;
            }
        }
    } else {
        cout << "Book not found in borrower's record!" << endl;
    }
}

int calculateFine(int daysOverdue) {
    return daysOverdue * FINE_PER_DAY;
}

void displayMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book\n";
    cout << "3. Register Borrower\n";
    cout << "4. Checkout Book\n";
    cout << "5. Return Book\n";
    cout << "6. Calculate Fine\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                addBorrower();
                break;
            case 4:
                checkoutBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                int daysOverdue;
                cout << "Enter days overdue: ";
                cin >> daysOverdue;
                cout << "Fine: $" << calculateFine(daysOverdue) << endl;
                break;
            case 7:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
