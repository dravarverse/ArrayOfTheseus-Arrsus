#ifndef ARRSUS_HPP
#define ARRSUS_HPP

#include <iostream>
#include <string>
#include <initializer_list>

template <typename T>
class Arrsus {
public:
    T* arr;
    int size;
    int capacity;

    Arrsus();
    Arrsus(int capacity);
    Arrsus(std::initializer_list<T> values);
    Arrsus(const Arrsus<T>& other);

    Arrsus<T>& operator=(std::initializer_list<T> values);
    Arrsus<T>& operator=(const Arrsus<T>& other);
    T& operator[](int index);
    
    int getSize();
    void add(T data);
    void insert(int index, T data);
    void pop();
    void erase(int index);
    void erase(int start_index, int end_index); 
    void resize(int newCapacity);
    void printArray();
    void clear();
    T at(int index);
    void printThis();

    ~Arrsus();
};

#endif