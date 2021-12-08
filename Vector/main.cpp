#include <iostream>
#include "vector.h"

int main() {
    Vector<int> vector(15);
	vector.pushBack(150);
	vector.popBack();
	vector.insert(14, 20);
	for(int i = 0; i < vector.size()-1; ++i){
        vector[i] = i*2;
		std::cout << i << " - " << vector[i] << "\n";
    }
    return 0;
}