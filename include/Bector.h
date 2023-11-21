// vector.h
#pragma once
#include <iostream>
#include "Route.h"
#include "Node.h"

template <typename T>
class Bector {

    T* data;
    size_t current_size;
    size_t capacity;

public:

    // CONSTRUCTOR
    Bector();

    // HOMEMADE PUSH_BACK FUNCTION
    void push_back(const T& value); // CONST BECAUSE WE DON'T WANT TO MODIFY THE VALUE (MINI SECURITY)

    // OPERATOR [] GET
    T& operator[](size_t index); // BASICALLY DEFINES THE [] OPERATOR WHEN PUTTING A VALUE INSIDE

    // GET SIZE
    size_t size();

    // ERASE
    void erase(size_t index);

    // BEGIN
    T* begin();

    // RESIZE
    void resize();

    // IS EMPTY
    bool is_empty() const;

    // DESTRUCTOR
    ~Bector();

};
