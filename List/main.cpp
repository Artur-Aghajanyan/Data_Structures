#include <iostream>
#include "list.h"

int main() {
    List<int> l;
	l.push(0);
	l.push(1);
	l.push(2);
	l.push(3);
	l.push(4);
	std::cout << "*************\n";
	l.print();
	l.erase(0);
	std::cout << "*------------*\n";
	l.insert(2, 11);
	l.print();
    return 0;
}