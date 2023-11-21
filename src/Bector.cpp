#include "../include/bector.h"

template class Bector<Route>;

// BECTOR IS A DYNAMIC ARRAY THAT CAN BE RESIZED MID-RUNTIME, COMPLETLY MADE BY MATTEITO (ME) AND INSPIRED BY THE VECTOR CLASS FROM THE STL
// IT'S A TEMPLATE CLASS, SO IT CAN BE USED WITH ANY TYPE OF DATA (IN THIS CASE, ROUTES)
// IT'S A VECTOR OF ROUTES, BASICALLY
// DOESNT HAVE A COPY CONSTRUCTOR BECAUSE IT'S NOT NEEDED FOR THIS PROJECT, BUT IT CAN BE ADDED IF NEEDED EASLY



// CONSTRUCTOR
template <typename T>
Bector<T>::Bector() : data(nullptr), current_size(0), capacity(0) {}

// HOMEMADE PUSH_BACK
template <typename T>
void Bector<T>::push_back(const T& value) { // CONST BECAUSE WE DON'T WANT TO MODIFY THE VALUE (MINI SECURITY)
    if (current_size == capacity) {
        resize(); // FIXED A MEMORY LEAK CAUSED BY NOT RESIZING THE VECTOR WHEN IT WAS FULL CONSIDERING THE CAPACITY
    }
    std::cout << "MIAU" << std::endl;
    std::cout << "CURRENT ROUTES HERMOSO VECTOR SIZE: " << current_size << std::endl;
    data[current_size++] = value;
}

// OPERATOR [] DEFINITION (BASICALLY A GETTER)
template <typename T>
T& Bector<T>::operator[](size_t index) { // BASICALLY DEFINES THE [] OPERATOR WHEN PUTTING A VALUE INSIDE
    return data[index];
}

// OPERATOR [] DEFINITION (BASICALLY A GETTER)
template <typename T>
size_t Bector<T>::size(){
    return current_size;
}

// HOMEMADE RESIZE
template <typename T>
void Bector<T>::resize() {
    size_t newCapacity;

    if (capacity == 0) {
        newCapacity = 1;
    }
    else {
        newCapacity = capacity * 2; // INCREASES THE CAPACITY BY 2
    }

    T* newData = new T[newCapacity];

    for (size_t i = 0; i < current_size; ++i) {
        newData[i] = data[i]; .// PENDING TO CHECK IF IN SOME RARE CASES IT DOESN'T WORK BY BUFFER OVERFLOW (ALTOUGH IT SHOULD)
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}


// HOMEMADE RESIZE
template <typename T>
void Bector<T>::erase(size_t index) {
    if (index < current_size) {
        for (size_t i = index; i < current_size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --current_size;
    }
}

// HOMEMADE RESIZE
template <typename T>
T* Bector<T>::begin() {
    return data;
}

// HOMEMADE IS EMPTY
template <typename T>
bool Bector<T>::is_empty() const {
    return current_size == 0;
}

// DESTRUCTOR
template <typename T>
Bector<T>::~Bector() {
    delete[] data;
}

