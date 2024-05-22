#include <iostream>
#include <string>
#include <vector>
#include <optional>
using namespace std;

class account{
    private:
    int accountNumber;
    float balance;
    public:
    account() : accountNumber(0),balance(0.0f) {};
    account(int accountNumber, float balance) : accountNumber(accountNumber),balance(balance){}
    void deposit(float amount){
        balance += amount;
    }
    void withdraw(float amount){
        if (amount<= balance){
            balance -= amount;
        }else{
            cout<<"you dont have enough balance for this withdrawal"<<endl;
        }
    }
    float getBalance() const{ return balance; }
    float getAccountNumber() const{ return accountNumber; }
    void displayDetails() const{
        cout<<"account number is: "<<accountNumber<<" and balance is: "<< balance<<endl;
    }

};
class customer{
    private:    
    string name;
    int userID;
    vector<account*> accounts;

    public:
    customer(string name,int userID) : name(name), userID(userID){}
    int getUserID(){return userID;}
    void addAccount(account* account){
        accounts.push_back(account);
    }
    vector<account*> getAccounts() const{
        return accounts;
    }
    optional<account*> getAccount(int accountNumber) const{
        for (account* account : accounts){
            if (account->getAccountNumber() == accountNumber){
                return account;
            }
        }
        cout<<"this account not found"<<endl;
        //TODO 
        return nullopt;
    }
    void displayDetails() const{
        cout<<"customer name is: "<<name<<" and userID is: "<< userID<<endl;
        cout<<"the customer owns this/ these accounts: "<<endl;
        for (account* account : accounts){
            account->displayDetails();
        }
    }
};    

class bank{
    private:
    vector<customer*> customers;
    public:
    void addCustomer(customer* customer){
        customers.push_back(customer);
    }
    optional<customer*> getCustomer(int userID){
        for (customer* customer : customers){
            if (customer->getUserID() == userID){
                return customer;
            }
        }
        cout<<"customer not found"<<endl;
        return nullopt;
    }
    optional<account*> getAccount(int accountNumber){
        for (customer* customer : customers){
            for (account* account : customer->getAccounts()){
                if (account->getAccountNumber() == accountNumber){
                    return account;
                }
            }
        }
        return nullopt;
    }
    void transferFunds(int fromAccountNumber,int toAccountNumber,float amount){
        //TODO add when account doesnt exist later

        auto fromAccountOpt = getAccount(fromAccountNumber);
        auto toAccountOpt = getAccount(toAccountNumber);
        if (!fromAccountOpt || !toAccountOpt){
            throw runtime_error ();
            // cout<<"Transfer unsuccessful, try other valid account numbers"<<endl;
        }else{
            account* fromAccount = *fromAccountOpt;
            account* toAccount = *toAccountOpt;
            fromAccount->withdraw(amount);
            toAccount->deposit(amount);
            cout<<"Transfer success !"<<endl;
        }
    }
    void displayCustomers(){
        for (customer* customer : customers){
            customer->displayDetails();
        }
    }
};



int main(){
    account a(1,100);
    account b(2,0);
    
    a.displayDetails();
    b.displayDetails();
    customer c1("amine",1);
    c1.addAccount(&a);
    c1.addAccount(&b);
    // auto accoutOptionnal = c1.getAccount(2);
    // if (accoutOptionnal){
    //     account* a1 = *accoutOptionnal;
    //     a1->displayDetails();
    // }else{
    //     cout<<"Account not found"<<endl;
    // };
    bank B;
    B.addCustomer(&c1);
    try{
        B.transferFunds(0,2,100);
    }catch (const exception &e){
        cerr<<" account number not found "<<e.what()<<endl;
    }
    
    B.displayCustomers();

    
    
    return 0;
}