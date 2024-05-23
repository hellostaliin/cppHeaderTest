#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <functional>
using namespace std;


class room{
private:
int roomNumber;
string roomType;
bool isAvailable = true;
float pricePerNight;
public:
room(int roomNumber,string roomType,bool isAvailable,float pricePerNight) : roomNumber(roomNumber),roomType(roomType),isAvailable(isAvailable),
pricePerNight(pricePerNight){}
int getRoomNumber()const {return roomNumber;}
bool getAvailability(){return isAvailable;}
void displayDetails() const{
    cout<<"room number: "<<roomNumber<<"\n"<<"room type: "<<roomType<<"\n"<<"availability: "<<(isAvailable?"available":"not available")<<endl;
    cout<<"price per night: "<<pricePerNight<<endl;
}
void markAsBooked(){
    if(isAvailable){
        isAvailable=0;
    }else{
        cout<<"room already booked"<<endl;
    }
}
void markAsAvailable(){
    if(!isAvailable){
        isAvailable=1;
    }else{
        cout<<"room already available"<<endl;
    }
}
};
class booking{
private:
int bookingID,roomNumber,customerID;
string checkInDate,checkOutDate;
public:
//constructor
booking(int bookingID,int roomNumber, int customerID,string checkInDate,string checkOutDate):bookingID(bookingID),
roomNumber(roomNumber),customerID(customerID),checkInDate(checkInDate),checkOutDate(checkOutDate){}
booking(int bookingID):bookingID(bookingID){}
//methods
int getBookingID()const {return bookingID;}
int getCustomerID()const {return customerID;}
int getRoomNumber()const{return roomNumber;}

void displayDetails() const{
     cout<<"bookingID: "<<bookingID<<"\n"<<"room number: "<<roomNumber<<"\n"<<"customer ID: "<<customerID<<"\n"<<"check in date: "<<checkInDate<<endl;
     cout<<"check out date: "<<checkOutDate<<endl;
}
};

class customer{
    private:
    int customerID;
    string name,contactInfo;
    vector<int> bookings;
    public:
    customer(int customerID,string name,string contactInfo):customerID(customerID),name(name),contactInfo(contactInfo){}
    int getCustomerID() const{return customerID;}
    void displayDetails()const{
        cout<<"customer identification: "<<customerID<<"\n"<<"customer name: "<<name<<"\n"<<"customer contact info: "<<contactInfo<<endl;
        cout<<"customer bookings are: "<<endl;
        for (int booking : bookings){
            cout<<"booking ID: "<<booking<<endl;
        }
    }
    void addBooking(int bookingID){
        bookings.push_back(bookingID);
    }
    void removeBooking(int bookingID){
        for (auto it=bookings.begin();it!=bookings.end();++it){
            if ((*it)== bookingID){
                bookings.erase(it);
                return;
            }
        }
        cout<<"cant find the booking to remove !"<<endl;
    }

};
class Hotel{
    private:
    vector<room> rooms;
    vector<customer> customers;
    vector<booking> bookings;
    int nextRoomNumber=1;
    int nextCustomerID=0;
    int nextBookingID=0;
    public:
    int getNextCustomerID(){return nextCustomerID;}
    int getNextRoomNumber(){return nextRoomNumber;}
    int getNextBookingID(){return nextBookingID;}
    void addRoom(const string& roomType,float pricePerNight){
        room r = (room(nextRoomNumber,roomType,true,pricePerNight));
        // cout<<nextRoomNumber<<endl;
        rooms.push_back(r);
        nextRoomNumber++;
    }
    void addCustomer(const string& name,const string& contactInfo){
        customer c = customer(nextCustomerID,name,contactInfo);
        customers.push_back(c);
        nextCustomerID++;
    }
    void bookRoom(int customerID,int roomNumber,const string& checkInDate,const string& checkOutDate){
        for (auto& room : rooms){
            // cout<<"rooms.size()"<<room.getRoomNumber()<<endl;
            if (room.getRoomNumber()==roomNumber){
                // cout<<room.getAvailability()<<endl;
                if (room.getAvailability() ==1){
                    for (auto& customer : customers){
                        // cout<<customer.getCustomerID()<<endl;
                        if (customer.getCustomerID() == customerID){
                            customer.addBooking(nextBookingID);
                            room.markAsBooked();
                            booking b(nextBookingID, roomNumber, customerID, checkInDate, checkOutDate);
                            bookings.push_back(b);
                            nextBookingID++;
                            cout<<"booking done"<<endl;
                            return;
                        }
                    }    
                   cout<<"customer not found"<<endl;
                   return;
            }
            cout<<"room not available"<<endl;
            return;
            }
        }
        cout<<"room not found"<<endl;
        return;
    }
     void displayAllRooms() const {
        for (const auto& room : rooms) {
            room.displayDetails();
        }
    }

    void displayAllCustomers() const {
        for (const auto& customer : customers) {
            customer.displayDetails();
        }
    }

    void displayAllBookings() const {
        for (const auto& booking : bookings) {
            booking.displayDetails();
        }
    }
    void checkIn(int bookingID){ //1 find if booking exist 2 see if room exist and isavailable 
        auto booking = findBooking(bookingID);
        if (booking){
            int roomNumber = booking->get().getRoomNumber();
            auto room = findRoom(roomNumber);
            if (!room->get().getAvailability()){
                auto customer = findCustomer(booking->get().getCustomerID());
            if (customer){
                cout<<"welcome! you checked in succefully."<<endl;
                return;
            }else{
            cout<<"we didnt find you in our customers list. sorry"<<endl;
            return;
            }
            }
            cout<<"sorry room unavailable"<<endl;
            return;
        }else{
            cout<<"booking not found in our list"<<endl;
            return;
        }
    }
    void checkOut(int bookingID){
        auto booking = findBooking(bookingID);
        if (booking){
            int roomNumber = booking->get().getRoomNumber();
            auto room = findRoom(roomNumber);
            room->get().markAsAvailable();
            cout<<"check out success! room "<<roomNumber<<" now available"<<endl;
        }else{
            cout<<"sorry this booking doesnt exist"<<endl;
        }
    }
    optional<reference_wrapper<room>> findRoom (int roomNumber){
        for ( auto& room : rooms){
            if (room.getRoomNumber()==roomNumber){
                return room;
            }
        }
        cout<<"funct findRoom-----> room not found !"<<endl;
        return nullopt;
    }
    optional<reference_wrapper<customer>> findCustomer (int customerID) {
        for (auto& customer:customers){
            if (customer.getCustomerID()==customerID){
                return customer;
            }
        }
        cout<<"funct findCustomer-----> customer not found !"<<endl;
        return nullopt;
    }
    optional<reference_wrapper<booking>> findBooking (int bookingID) {
        for ( auto& booking:bookings){
            if (booking.getBookingID()==bookingID){
                return booking;
            }
        }
        cout<<"funct findBooking-----> booking not found !"<<endl;
        return nullopt;
    }

};



int main(){
    Hotel h;
    h.addRoom("suite", 200);
    h.addCustomer("Taha", "taha@gmail.com");
    // h.displayAllRooms();
    h.bookRoom(h.getNextCustomerID() - 1, h.getNextRoomNumber() - 1, "01/04/2024", "04/04/2024");
    // h.displayAllRooms();
    h.checkIn(0);
    // h.displayAllRooms();
    h.checkOut(0);
    // h.displayAllRooms();
    h.addCustomer("fz","fe@gmail.com");
    h.bookRoom(1, 1, "05/04/2024", "10/04/2024");


    // h.checkOut(0);
    // h.addCustomer("fz","fe@gmail.com");
    // h.bookRoom(h.getNextCustomerID() - 1, 1, "05/04/2024", "10/04/2024");
    // cout << "All Rooms:" << endl;
    // h.displayAllRooms();
    // cout << "\nAll Customers:" << endl;
    // h.displayAllCustomers();
    // cout << "\nAll Bookings:" << endl;
    // h.displayAllBookings();
    
    return 0;
}