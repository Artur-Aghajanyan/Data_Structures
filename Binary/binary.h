#include <iostream>

using namespace std;

struct Binary_node{
	int data;
	Binary_node *left;
	Binary_node *right;
};

class BinaryTree{
    private:
	    Binary_node *root;
        void insert(int key, Binary_node *node);
        void destroy_tree(Binary_node *node);
        void inorder_print(Binary_node *node);
        void postorder_print(Binary_node *node);
        void preorder_print(Binary_node *node);
    public:
        BinaryTree();
        ~BinaryTree();
        void insert(int data);
        void destroy_tree();
        void inorder_print();
        void postorder_print();
        void preorder_print();
        bool isEmpty();

};

BinaryTree::BinaryTree(){
    this->root = nullptr;
};

bool BinaryTree::isEmpty(){
    return (this->root == nullptr);
};

void BinaryTree::insert(int data, Binary_node *node) {
    if(data < node->data){
        if(node->left != nullptr){
            insert(data, node->left);
        }else{
            node->left = new Binary_node;
            node->left->data = data;
            node->left->left = nullptr;
            node->left->right = nullptr;
        }
    }else if(data >= node->data){
        if(node->right != nullptr){
            insert(data, node->right);
        }else{
            node->right = new Binary_node;
            node->right->data = data;
            node->right->right = nullptr;
            node->right->left = nullptr;
        }
    }
};

void BinaryTree::insert(int data){
	if(root != nullptr){
		insert(data, root);
	}else{
		root = new Binary_node;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
	}
};

void BinaryTree::destroy_tree(Binary_node *node){
	if(node != nullptr){
		destroy_tree(node->left);
		destroy_tree(node->right);
		delete node;
	}
};

void BinaryTree::destroy_tree(){
	destroy_tree(root);
};

void BinaryTree::inorder_print(Binary_node *node){
	if(node != nullptr){
		inorder_print(node->left);
		cout << node->data << ", ";
		inorder_print(node->right);
	}
};

void BinaryTree::inorder_print(){
	inorder_print(root);
	cout << "\n";
};

void BinaryTree::postorder_print(Binary_node *node) {
    if(node != NULL){
		inorder_print(node->left);
		inorder_print(node->right);
		cout << node->data << ", ";
	}
};

void BinaryTree::postorder_print(){
	postorder_print(root);
	cout << "\n";
};

void BinaryTree::preorder_print(Binary_node *node) {
    if(node != NULL){
		inorder_print(node->left);
		inorder_print(node->right);
		cout << node->data << ", ";
	}
};

void BinaryTree::preorder_print(){
	preorder_print(root);
	cout << "\n";
};

BinaryTree::~BinaryTree() {
    this->destroy_tree();
}