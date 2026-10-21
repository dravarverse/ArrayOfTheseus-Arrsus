#include "arrsus.h"


template <typename T>
Arrsus<T>::Arrsus() : size(0), capacity(0), arr(nullptr) {}

template <typename T>
Arrsus<T>::Arrsus(int capacity) : size(0), capacity(capacity){
    arr = new T[capacity]{};
}

template <typename T>
int Arrsus<T>::getSize(){
    return this->size;
}

template <typename T>
T& Arrsus<T>::operator[](int index)
    {
        if (index >= capacity)
        {
            throw std::out_of_range("Index out of size range.");
            // return;
        }
        else if (index < capacity && index >= size){
            size++;
        }
        return arr[index];
    }

template <typename T>
void Arrsus<T>::add(T data)
    {
        if (size == capacity)
        {
            int newCapacity = (capacity == 0 ? 1 : capacity * 2);
            resize(newCapacity);
            this->capacity = newCapacity;
        }

        arr[size] = data;
        size++;
    }

template <typename T>
void Arrsus<T>::insert(int index, T data)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index Out of Bounds error");
            return;
        }

        if (size == capacity)
        {
            int newCapacity = (capacity == 0 ? 1 : capacity * 2);
            resize(newCapacity);
            this->capacity = newCapacity;
        }

        T temp[size];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }

        arr[index] = data;
        for (int i = index; i < size; i++)
        {
            arr[i + 1] = temp[i];
        }
        size++;
    }

template <typename T>
void Arrsus<T>::pop()
    {
        if (size == 0)
        {
            throw std::out_of_range("pop on empty array.");
            return;
        }

        arr[size - 1] = T{};
        size--;
        if (size <= capacity / 2)
        {
            int newCapacity = (capacity == 0 ? 1 : capacity / 2);
            resize(newCapacity);
            this->capacity = newCapacity;
        }
    }

template <typename T>
void Arrsus<T>::resize(int newCapacity)
    {
        T *newArray = new T[newCapacity]{};
        for (int i = 0; i < size; i++)
        {
            newArray[i] = arr[i];
        }
        delete[] arr;
        this->arr = newArray;
        this->capacity = newCapacity;
    }

template <typename T>
void Arrsus<T>::printArray()
    {
        std::cout << "{";
        for (int i = 0; i < this->size; i++)
        {
            if (i == this->size - 1)
            {
                std::cout << arr[i];
                break;
            }
            std::cout << arr[i] << ",";
        }
        std::cout << "}\n";
    }

template <typename T>
void Arrsus<T>::clear(){
        T* emptyArr = new T[capacity]{};
        delete[] arr;
        arr = emptyArr;
        this->size = 0;
    }

template <typename T>
T Arrsus<T>::at(int index){
    if (index >= size)
    {
        return T{};
    }
    
    return arr[index];
}

template <typename T>
Arrsus<T>::~Arrsus()
    {
        delete[] arr;
        arr = nullptr;
    }



template class Arrsus<int>;
template class Arrsus<char>;
template class Arrsus<double>;
template class Arrsus<std::string>;
