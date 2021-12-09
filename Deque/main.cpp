#include <iostream>
#include "deque.h"

int main() {
    Deque<int> deque;
    deque.pushBack(15);
    deque.printBack();
    deque.pushBack(25);
    deque.printFront();
    deque.pushBack(35);
    deque.printBack();
    deque.pushBack(55);
    deque.printFront();
    deque.pushBack(45);
    deque.printBack();
    deque.pushBack(65);
    std::cout << deque.getBack() << std::endl;
    std::cout << deque.isFull() << std::endl;
    deque.deleteFront();
    deque.deleteBack();
    return 0;
}