#ifndef ARRSUS_H
#define ARRSUS_H

#include <iostream>
#include <string>

template <typename T>
class Arrsus {
public:
    int size;
    int capacity;
    T* arr;

    Arrsus();
    Arrsus(int capacity);
    
    T& operator[](int index);
    int getSize();
    void add(T data);
    void insert(int index, T data);
    void pop();
    void resize(int newCapacity);
    void printArray();
    void clear();
    T at(int index);

    ~Arrsus();
};

#endif