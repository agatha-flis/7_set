#ifndef SET_H
#define SET_H

#include <iostream>

template<typename T>
class Set {
private:

    int element;
    int capacity;
    T* data;

public:

    Set() { element = 0; capacity = 1; data = new T[capacity]; }
    Set(const Set& copy) {
        data = new T[copy.capacity];

        for (int i = 0; i < copy.element; ++i)
            data[i] = copy.data[i];

        element = copy.element;
        capacity = copy.capacity;
    };
    ~Set() { delete[] data; }

    int size() const;
    bool empty() const;
    void clear();
    void insert(const T& value);
    bool isDuplicate(const T& value);
    bool isFull();
    void grow();
    void show();
};

#endif