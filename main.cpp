#include "Hotel.h"

int main() {
    Hotel h;
    h.addRoom("suite", 200);
    h.addCustomer("Taha", "taha@gmail.com");
    h.bookRoom(1, 1, "01/04/2024", "04/04/2024");
    h.checkIn(1);
    h.checkOut(1);
    h.addCustomer("fz", "fe@gmail.com");
    h.bookRoom(2, 1, "05/04/2024", "10/04/2024");

    return 0;
}
