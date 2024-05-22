#include <iostream>
#include "Node.h"
#include "Node.cpp"

int main()
{
    // Create Node objects
    Node node1;
    node1.tag = 1;
    node1.x = 10.5;
    node1.y = 20.7;
    node1.boundarynode = true;

    Node node2;
    node2.tag = 2;
    node2.x = 15.2;
    node2.y = 25.9;
    node2.boundarynode = false;

    // Print Node information
    std::cout << "Node 1: " << node1 << std::endl;
    std::cout << "Node 2: " << node2 << std::endl;

    return 0;
}
