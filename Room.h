#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

class Room {
private:
    int roomNumber;
    std::string roomType;
    bool isAvailable;
    float pricePerNight;

public:
    Room(int roomNumber, const std::string& roomType, bool isAvailable, float pricePerNight);
    
    int getRoomNumber() const;
    bool getAvailability() const;
    void displayDetails() const;
    void markAsBooked();
    void markAsAvailable();
};

#endif // ROOM_H
