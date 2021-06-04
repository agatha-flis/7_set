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

template<typename T>
int Set<T>::size() const
{
    return element;
}

template<typename T>
bool Set<T>::empty() const
{
    return element == 0;
}

template<typename T>
void Set<T>::clear()
{
    delete[] data;
    capacity = 1;
    element = 0;
    T* temp = new T[capacity];
    data = temp;

}

template<typename T>
void Set<T>::insert(const T& value)
{
    if (isDuplicate(value) == true)
        return;
    else {
        if (isFull() == true)
            grow();

        data[element] = value;
        element++;
    }
}

template<typename T>
bool Set<T>::isDuplicate(const T& value)
{
    for (int i = 0; i < element; i++)
       { if (data[i] == value)
            return true; }
    return false;
}

template<typename T>
bool Set<T>::isFull()
{
    return capacity == element;
}

template<typename T>
void Set<T>::grow()
{
    capacity *= 2;
    T* dataTemp = new T[capacity];
    for (int i = 0; i < element; ++i)
        dataTemp[i] = data[i];
    delete[] data;
    data = dataTemp;
}

template<typename T>
void Set<T>::show()
{
    for (int i = 0; i < element; i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

#endif