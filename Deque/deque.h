#include <iostream>

template <class T>
class Deque{
    private:
        T* array;
        int size;
        int front;
        int back;
    public:
        Deque();
        Deque(int size);
        ~Deque();
        void pushBack(T data);
        void pushFront(T data);
        void printFront();
        void printBack();
        bool isFull();
        void deleteFront();
        void deleteBack();
        T getFront();
        T getBack();
};

template <class T>
Deque<T>::Deque() {
    this->size = 5;
    this->array = new T[this->size];
    this->front = -1;
    this->back = 0;
};

template <class T>
Deque<T>::Deque(int size) {
    this->size = size;
    this->array = new T[this->size];
    this->front = -1;
    this->back = 0;
};

template <class T>
Deque<T>::~Deque() {
    delete[] this->array;
};

template <class T>
bool Deque<T>::isFull() {
    if((this->front==0 && this->back == size-1) || this->front == this->size+1) {
        return true;
    }
    return false;
};

template <class T>
void Deque<T>::pushFront(T data) {
    if(this->isFull()) {
        std::cout << "Deque is full\n";
    }else{
        if(this->front == -1) {
            this->front = 0;
            this->back = 0;
        }else if(this->front == 0){
            this->front = this->size-1;
        }else{
            this->front-=1;
        }

        this->array[this->front] = data;
    }
};

template <class T>
void Deque<T>::pushBack(T data) {
    if(this->isFull()) {
        std::cout << "Deque is full\n";
    }else{
        if(this->back == size-1) {
            this->back = 0;
        }else if(this->front == -1) {
            this->front = 0;
            this->back = 0;
        }else{
            this->back++;
        }
        this->array[this->back] = data;
    }
};

template <class T>
void Deque<T>::printFront() {
    std::cout << this->array[this->front] << std::endl;
};

template <class T>
void Deque<T>::printBack() {
    std::cout << this->array[this->back] << std::endl;
};

template <class T>
void Deque<T>::deleteFront() {
    if(this->front == -1) {
        std::cout << "Deque is empty\n";
    }else{
        if(this->front == this->back) {
            this->front -= 1;
            this->back -= 1;
        }else if(this->back == this->size-1) {
            this->back = 0;
        }else{
            this->front += 1;
        }
    }
};

template <class T>
void Deque<T>::deleteBack() {
    if(this->front == -1) {
        std::cout << "Deque is empty\n";
    }else{
        if(this->front == this->back) {
            this->front -= 1;
            this->back -= 1;
        }else if(this->back == 0) {
            this->back = this->size-1;
        }else{
            this->front -= 1;
        }
    }
};

template <class T>
T Deque<T>::getFront() {
    if(this->front == -1) {
        std::cout << "this->front" << std::endl;
        std::cout << "Deque is empty\n";
        return false;
    }
    return this->array[this->front];
};

template <class T>
T Deque<T>::getBack() {
    if(this->front == -1) {
        std::cout << "this->front" << std::endl;
        std::cout << "Deque is empty\n";
        return false;
    }else{
        return this->array[this->back];
    }
}