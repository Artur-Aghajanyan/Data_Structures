#include <iostream>

template <class T>
class Queue {
    private:
        T* array;
        int size;
        int front;
    public:
        Queue();
        Queue(int size);
        ~Queue();
        void push(T data);
        void deleteFront();
        void print();
        bool isEmpty();
};


template <class T>
Queue<T>::Queue() {
    this->size = 5;
    this->array = new T[this->size];
    this->front = -1;
};

template <class T>
Queue<T>::Queue(int size) {
    this->size = size;
    this->array = new T[this->size];
    this->front = -1;
};

template <class T>
bool Queue<T>::isEmpty() {
    if(this->front == -1) {
        return true;
    }
    return false;
};

template <class T>
void Queue<T>::push(T data) {
    if(this->front == this->size - 1) {
        std::cout << "Queue is full\n";    
    }else {
        this->front++;
        this->array[this->front] = data;
    }
};

template <class T>
void Queue<T>::print() {
    if(this->isEmpty()) {
        std::cout << "Queue is empty\n";
    } else{
        std::cout << "Queue element is: " << this->array[this->front] << std::endl;
    }
};

template <class T>
void Queue<T>::deleteFront() {
    if(this->isEmpty()) {
        std::cout << "Queue is empty\n"; 
    }else {
        std::cout << "Deleted element: " << this->array[this->front] << std::endl;
        this->front--;
    }
};

template <class T>
Queue<T>::~Queue() {
    delete[] this->array;
}