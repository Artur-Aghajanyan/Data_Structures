#include <iostream>

using namespace std;
template <class T>
class Vector {
	private:
		int index;
        int capacity;
		T* array;	
	public:
		Vector();
		Vector(int count);
		Vector(const Vector& vector);
		void insert(int index, T value);
		int size();
		bool isEmpty();
		void pushBack(T value);
		void popBack();
		T &operator[](int index);
		~Vector();
};

template <class T>
Vector<T>::Vector() {
    this->index = 0;
    this->capacity = 0;
    this->array = nullptr;
};

template <class T>
Vector<T>::Vector(int capacity) {
    this->index = 0;
    this->capacity = capacity;
    this->array = new T[this->capacity];
};

template <class T>
Vector<T>::Vector(const Vector& vector){
    this->index = vector.index;
    this->capacity = vector.capacity;
    std::copy(this->array, this->array + this->capacity, vector.array);
};

template <class T>
int Vector<T>::size() {
    return this->capacity;
};

template <class T>
bool Vector<T>::isEmpty(){
    if(this->index <= 0)
        return true;
    return false;
};

template <class T>
void Vector<T>::pushBack(T data) {
    if(this->capacity == this->index) {
        this->capacity += 5;
        T* newArray = new T[this->capacity];
        std::copy(this->array, this->array + this->capacity, newArray);
        newArray[this->index] = data;
        this->index++;
        delete[] this->array;
        this->array = newArray;
    }else{
        this->array[this->index] = data;
        this->index++;
    }
};

template <class T>
T &Vector<T>::operator[](int index){
	if(index > this->capacity)
		return this->array[this->capacity-1];
	if(index <= 0)
		return this->array[0];
	return this->array[index];
};

template <class T>
void Vector<T>::popBack() {
    this->capacity--;
	T* newArray = new T[this->capacity];
	if(this->index > 0)
		copy(this->array, this->array+this->capacity, newArray);

    this->index--;
	delete[] this->array;
	this->array = newArray;
};

template <class T>
void Vector<T>::insert(int index, T value) {
    this->capacity++;
	T* newArray = new T[this->capacity];
	if(this->index > 0) {
		copy(this->array, this->array + index, newArray);
		copy(this->array + index + 1, this->array + this->capacity-1, newArray + index);
	}
    this->index++;
	newArray[index] = value;
	delete[] array;
	this->array = newArray;
};

template <class T>
Vector<T>::~Vector() {
	delete[] this->array;
}
