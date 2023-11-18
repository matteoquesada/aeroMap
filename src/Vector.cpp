// vector.cpp
#include "../include/vector.h"

// Explicit instantiation for the types you use in your program
template class SimpleVector<Route>;

template <typename T>
SimpleVector<T>::SimpleVector() : data(nullptr), current_size(0), capacity(0) {}

template <typename T>
SimpleVector<T>::~SimpleVector() {
    delete[] data;
}

template <typename T>
void SimpleVector<T>::push_back(const T& value) {
    if (current_size == capacity) {
        resize();
    }
    std::cout << "push_back" << std::endl;
    std::cout << "current_size: " << current_size << std::endl;
    data[current_size++] = value;
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
size_t SimpleVector<T>::size() const {
    return current_size;
}

template <typename T>
void SimpleVector<T>::resize() {
    size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
    T* newData = new T[newCapacity];

    for (size_t i = 0; i < current_size; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
void SimpleVector<T>::erase(size_t index) {
    if (index < current_size) {
        for (size_t i = index; i < current_size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --current_size;
    }
}

template <typename T>
T* SimpleVector<T>::begin() {
    return data;
}

// Add more explicit instantiations if needed
