#include <iostream>
#include <string>
#include <vector>
#include <optional>
using namespace std;

class account {
private:
    int accountNumber;
    float balance;
public:
    account() : accountNumber(0), balance(0.0f) {}
    account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "You don't have enough balance for this withdrawal" << endl;
        }
    }

    float getBalance() const { return balance; }
    int getAccountNumber() const { return accountNumber; }

    void displayDetails() const {
        cout << "Account number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class customer {
private:
    string name;
    int userID;
    vector<account*> accounts;

public:
    customer(string name, int userID) : name(name), userID(userID) {}

    int getUserID() const { return userID; }

    void addAccount(account* account) {
        accounts.push_back(account);
    }

    vector<account*> getAccounts() const {
        return accounts;
    }

    optional<account*> getAccount(int accountNumber) const {
        for (account* account : accounts) {
            if (account->getAccountNumber() == accountNumber) {
                return account;
            }
        }
        cout << "This account was not found" << endl;
        return nullopt;
    }

    void displayDetails() const {
        cout << "Customer name: " << name << ", UserID: " << userID << endl;
        cout << "The customer owns these accounts:" << endl;
        for (account* account : accounts) {
            account->displayDetails();
        }
    }
};

class bank {
private:
    vector<customer*> customers;

public:
    void addCustomer(customer* customer) {
        customers.push_back(customer);
    }

    optional<customer*> getCustomer(int userID) {
        for (customer* customer : customers) {
            if (customer->getUserID() == userID) {
                return customer;
            }
        }
        cout << "Customer not found" << endl;
        return nullopt;
    }

    optional<account*> getAccount(int accountNumber) {
        for (customer* customer : customers) {
            for (account* account : customer->getAccounts()) {
                if (account->getAccountNumber() == accountNumber) {
                    return account;
                }
            }
        }
        cout << "Account not found" << endl;
        return nullopt;
    }

    void transferFunds(int fromAccountNumber, int toAccountNumber, float amount) {
        auto fromAccountOpt = getAccount(fromAccountNumber);
        auto toAccountOpt = getAccount(toAccountNumber);

        if (!fromAccountOpt || !toAccountOpt) {
            cout << "Transfer unsuccessful, account number(s) not found" << endl;
            return;
        }

        account* fromAccount = *fromAccountOpt;
        account* toAccount = *toAccountOpt;

        fromAccount->withdraw(amount);
        toAccount->deposit(amount);

        cout << "Transfer success!" << endl;
    }
};

int main() {
    account a(1, 100);
    account b(2, 0);

    a.displayDetails();
    b.displayDetails();

    customer c1("amine", 1);
    c1.addAccount(&a);
    c1.addAccount(&b);

    bank B;
    B.addCustomer(&c1);

    try {
        B.transferFunds(1, 2, 100);
    } catch (const exception &e) {
        cout << "An error occurred: " << e.what() << endl;
    }

    a.displayDetails();
    b.displayDetails();

    return 0;
}
