#pragma once

#include <cstddef>
#include <utility>
#include <stdexcept>


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

        ~Vector(){
            delete[] elements;
        }

        Vector(const Vector<T>& other){
            capacity = other.capacity;
            size = other.size;
            elements = new T[capacity];
            for(size_t i = 0; i < size; i++){
                elements[i] = other.elements[i];
            }

        }

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

        // Logically empty the vector (keeps the allocated capacity), like std::vector::clear.
        void clear(){
            size = 0;
        }

        void push_back(T value){
            if(size >= capacity){
                resize();
            }
            elements[size] = value;
            size++;
        }
        void resize(){
            capacity *= 2;
            T* newElements = new T[capacity];
            for(size_t i = 0; i < size; i++){
                newElements[i] = std::move(elements[i]);
            }

            delete[] elements;
            elements = newElements;
        }

        T pop(){
            if (size == 0) {
                throw std::runtime_error("vector is empty"); 
            }
            size--;
            return elements[size]; 
        }

        T& operator[](size_t index){
            // at is bounds checked not [] if(index >= size) throw std::out_of_range("index out of bounds");
            return elements[index];
        }





        size_t getSize() const { return size; }
        size_t getCapacity() const { return capacity; }
};