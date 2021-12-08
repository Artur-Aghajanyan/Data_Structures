#include <iostream>
#include "queue.h"

int main() {
    Queue<int> queue;
    queue.push(4);
    queue.push(14);
    queue.push(24);
    queue.push(34);
    queue.push(44);
    queue.push(54);
    queue.deleteFront();
    queue.print();
    return 0;
}