// vector.h
#pragma once
#include <iostream>
#include "Route.h"
#include "Node.h"

template <typename T>
class SimpleVector {

public:
    SimpleVector();
    ~SimpleVector();

    void push_back(const T& value);
    T& operator[](size_t index); // BASICALLY DEFINES THE [] OPERATOR WHEN PUTTING A VALUE INSIDE
    size_t size() const;
    void erase(size_t index);
    T* begin();
    void resize();

private:

    T* data;
    size_t current_size;
    size_t capacity;
};
