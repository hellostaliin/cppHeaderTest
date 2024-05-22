#include <iostream>

using namespace std;

struct MyStruct {
    int value;
};

int main() {
    MyStruct s;
    MyStruct* ptr = &s;
    ptr->value = 30;     // Access member variable via pointer
    cout << "Value ptr: " << ptr->value << endl;
    cout << "Value s: " <<s.value << endl;
    return 0;
}
