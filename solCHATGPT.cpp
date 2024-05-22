#include <iostream>
#include <vector>
#include <string>

// Book class
class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool isAvailable;

public:
    Book(std::string t, std::string a, std::string i)
        : title(t), author(a), ISBN(i), isAvailable(true) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return ISBN; }
    bool getAvailability() const { return isAvailable; }

    void setAvailability(bool availability) { isAvailable = availability; }

    void displayDetails() const {
        std::cout << "Title: " << title << ", Author: " << author
                  << ", ISBN: " << ISBN << ", Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }
};

// User class
class User {
private:
    std::string name;
    int userID;
    std::vector<Book*> borrowedBooks;

public:
    User(std::string n, int id) : name(n), userID(id) {}

    std::string getName() const { return name; }
    int getUserID() const { return userID; }

    void borrowBook(Book& book) {
        if (book.getAvailability()) {
            borrowedBooks.push_back(&book);
            book.setAvailability(false);
            std::cout << name << " borrowed " << book.getTitle() << std::endl;
        } else {
            std::cout << book.getTitle() << " is not available." << std::endl;
        }
    }

    void returnBook(Book& book) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if ((*it)->getISBN() == book.getISBN()) {
                borrowedBooks.erase(it);
                book.setAvailability(true);
                std::cout << name << " returned " << book.getTitle() << std::endl;
                return;
            }
        }
        std::cout << name << " does not have " << book.getTitle() << std::endl;
    }

    void displayDetails() const {
        std::cout << "User: " << name << ", UserID: " << userID << ", Borrowed Books: ";
        for (const auto& book : borrowedBooks) {
            std::cout << book->getTitle() << " ";
        }
        std::cout << std::endl;
    }
};

// Library class
class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void registerUser(const User& user) {
        users.push_back(user);
    }

    void borrowBook(int userID, const std::string& ISBN) {
        for (auto& user : users) {
            if (user.getUserID() == userID) {
                for (auto& book : books) {
                    if (book.getISBN() == ISBN) {
                        user.borrowBook(book);
                        return;
                    }
                }
                std::cout << "Book with ISBN " << ISBN << " not found." << std::endl;
                return;
            }
        }
        std::cout << "User with ID " << userID << " not found." << std::endl;
    }

    void returnBook(int userID, const std::string& ISBN) {
        for (auto& user : users) {
            if (user.getUserID() == userID) {
                for (auto& book : books) {
                    if (book.getISBN() == ISBN) {
                        user.returnBook(book);
                        return;
                    }
                }
                std::cout << "Book with ISBN " << ISBN << " not found." << std::endl;
                return;
            }
        }
        std::cout << "User with ID " << userID << " not found." << std::endl;
    }

    void displayAllBooks() const {
        for (const auto& book : books) {
            book.displayDetails();
        }
    }

    void displayAllUsers() const {
        for (const auto& user : users) {
            user.displayDetails();
        }
    }
};

// Main function to demonstrate the functionality
int main() {
    Library library;

    // Adding books to the library
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", "12345"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", "67890"));

    // Registering users
    library.registerUser(User("Alice", 1));
    library.registerUser(User("Bob", 2));

    // Displaying all books and users
    std::cout << "Books in the library:" << std::endl;
    library.displayAllBooks();
    std::cout << "Users in the library:" << std::endl;
    library.displayAllUsers();

    // Borrowing and returning books
    library.borrowBook(1, "12345");
    library.returnBook(1, "12345");

    // Displaying all books and users again to see the updates
    std::cout << "Books in the library after borrowing and returning:" << std::endl;
    library.displayAllBooks();
    std::cout << "Users in the library after borrowing and returning:" << std::endl;
    library.displayAllUsers();

    return 0;
}
