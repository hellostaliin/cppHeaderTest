#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title, author;
    long long ISBN; // international standard book number
    bool availability;

public:
    Book(string title, string author, long long ISBN, bool availability)
        : title(title), author(author), ISBN(ISBN), availability(availability) {};

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    long long getISBN() const { return ISBN; }
    bool getAvailability() const { return availability; }

    void setAvailability(bool a) { availability = a; }

    void displayDetails() const {
        cout << "Book title: " << title << endl;
        cout << "Book author: " << author << endl;
        cout << "Book ISBN: " << ISBN << endl;
        cout << "Book availability: " << (availability ? "available" : "not available") << endl;
    }
};

class User {
private:
    string name;
    int userID;
    vector<Book*> borrowedBooks;

public:
    User(string name, int userID) : name(name), userID(userID) {};

    string getName() const { return name; }
    int getUserID() const { return userID; }

    void borrowBook(Book* book) {
        if (book->getAvailability()) {
            borrowedBooks.push_back(book);
            book->setAvailability(false);
            cout << name << " borrowed " << book->getTitle() << endl;
        } else {
            cout << book->getTitle() << " isn't available" << endl;
        }
    }

    void returnBook(Book* book) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if ((*it)->getISBN() == book->getISBN()) {
                borrowedBooks.erase(it);
                book->setAvailability(true);
                cout << name << " returned " << book->getTitle() << endl;
                return;
            }
        }
        cout << name << " does not have " << book->getTitle() << endl;
    }

    void displayDetails() const{
        cout << "User name: " << name << endl;
        cout << "User ID: " << userID << endl;
        cout << "Borrowed book ISBN" << (borrowedBooks.size() == 1 ? " is: " : "s are: ") << endl;
        int counter = 1;
        for (Book* book : borrowedBooks) {
            cout << "N°" << counter << " : " << book->getISBN() << endl;
            counter++;
        }
    }
};

class Library {
private:
    vector<User*> users;
    vector<Book*> books;

public:
    void addBook(Book* book) {
        books.push_back(book);
    }

    void registerUser(User* user) {
        users.push_back(user);
    }

    void borrowBook(int userID, long long ISBN) {
        for (User* user : users) {
            if (user->getUserID() == userID) {
                for (Book* book : books) {
                    if (book->getISBN() == ISBN) {
                        user->borrowBook(book);
                        return;
                    }
                }
                cout << "Book not found" << endl;
                return;
            }
        }
        cout << "User not found" << endl;
    }
    void returnBook(int userID, Book* book){
        for (User* user : users) {
            if (user->getUserID() == userID) {
                user->returnBook(book);
                return;
                }
            }
            cout<<"user not found"<<endl;
        }
    };


int main() {
    Library library;
    Book b1("title", "amin", 1234567890, true);
    Book b2("title", "amin", 1234567899, true);
    User u1("amine", 1);

    library.addBook(&b1);
    library.addBook(&b2);

    library.registerUser(&u1);

    library.borrowBook(1, 1234567890);
    library.borrowBook(1, 1234567899);  // Amine borrows the book
    library.returnBook(1, &b2);

    b1.displayDetails();
    b2.displayDetails();
    u1.displayDetails();

    return 0;
}
