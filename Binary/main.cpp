#include <iostream>
#include "binary.h"

int main() {
	BinaryTree *tree = new BinaryTree();

	tree->insert(92);
	tree->insert(7);
    tree->insert(76);
	tree->insert(3);
    tree->insert(4);
	tree->insert(0);
	tree->insert(51);
    tree->insert(523);
	tree->insert(2);
	tree->insert(8);

    std::cout << "\nPreorder Tree \n";
	tree->preorder_print();
    std::cout << "\nInorder Tree \n";
	tree->inorder_print();
    std::cout << "\nPostorder Tree \n";
	tree->postorder_print();
    return 0;
}