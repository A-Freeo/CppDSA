#pragma once

#include <cstddef>
#include <utility>
#include <stdexcept>


// Dynamic array (like std::vector): a raw T[] that doubles when it fills up.
//   size = how many slots are used, capacity = how big the array actually is.
template<typename T>
class Vector{
    private:
        T* elements;
        size_t capacity;
        size_t size;


    public:
        Vector(){
            capacity = 10;
            size = 0;
            elements = new T[capacity];
        }

        // --- Rule of Three ---
        // We own a raw array, so free it on death and deep-copy (never share it).

        ~Vector(){
            delete[] elements;
        }

        // Copy constructor: give the new vector its own array and copy the values in.
        Vector(const Vector<T>& other){
            capacity = other.capacity;
            size = other.size;
            elements = new T[capacity];
            for(size_t i = 0; i < size; i++){
                elements[i] = other.elements[i];
            }

        }

        // Copy assignment: self-guard, free our old array, then deep-copy.
        Vector<T>& operator=(const Vector<T>& other){
            if(this == &other) return *this;
            delete[] elements;

            capacity = other.capacity;
            size = other.size;
            elements = new T[capacity];
            for(size_t i = 0; i < size; i++){
                elements[i] = other.elements[i];
            }
            return *this;
        }

        // --- Core operations ---

        // Logically empty the vector (keeps the allocated capacity), like std::vector::clear.
        void clear(){
            size = 0;
        }

        // Append to the end; grow first if the array is full. Amortized O(1).
        void push_back(T value){
            if(size >= capacity){
                resize();
            }
            elements[size] = value;
            size++;
        }

        // Double the capacity: allocate a bigger array, move the elements over, swap.
        void resize(){
            capacity *= 2;
            T* newElements = new T[capacity];
            for(size_t i = 0; i < size; i++){
                newElements[i] = std::move(elements[i]);
            }

            delete[] elements;
            elements = newElements;
        }

        // Remove and return the last element.
        T pop(){
            if (size == 0) {
                throw std::runtime_error("vector is empty");
            }
            size--;
            return elements[size];
        }

        // Access by index, returns a reference so v[i] = x works.
        // Unchecked, like std::vector::operator[] (use at() for bounds-checking).
        T& operator[](size_t index){
            return elements[index];
        }


        size_t getSize() const { return size; }
        size_t getCapacity() const { return capacity; }
};