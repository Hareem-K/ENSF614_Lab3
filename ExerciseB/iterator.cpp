// iterator.cpp - ENSF 614 Lab 3, Exercise B
// Generic Vector and circular iterator for int, Mystring, and C-string values.

#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring2.h"

using namespace std;

// Generic comparison. For ordinary types, their > operator is sufficient.
template <class T>
bool greater_value(const T& a, const T& b) {
    return a > b;
}

// Mystring does not define relational operators, so compare its C-string data.
inline bool greater_value(const Mystring& a, const Mystring& b) {
    return strcmp(a.c_str(), b.c_str()) > 0;
}

// Compare C strings by text, not by their memory addresses.
inline bool greater_value(const char* const& a, const char* const& b) {
    return strcmp(a, b) > 0;
}

template <class T> //T is a placeholder for a data type.
class Vector {
public:
    class VectIter {
        friend class Vector<T>;
    private:
        Vector<T>* v;
        int index;
    public:
        explicit VectIter(Vector<T>& x) : v(&x), index(0) {}

        // Prefix: advance first, then return the element at the new index.
        T operator++() {
            index = (index + 1) % v->size;
            return v->array[index];
        }

        // Postfix: return the current element, then advance.
        T operator++(int) {
            T current = v->array[index];
            index = (index + 1) % v->size;
            return current;
        }

        // Prefix: move backward first, then return the new current element.
        T operator--() {
            index = (index - 1 + v->size) % v->size;
            return v->array[index];
        }

        // Postfix: return the current element, then move backward.
        T operator--(int) {
            T current = v->array[index];
            index = (index - 1 + v->size) % v->size;
            return current;
        }

        // Dereference: return the element at the current iterator position.
        T operator*() const {
            return v->array[index];
        }
    };

    explicit Vector(int sz) : array(nullptr), size(sz) {
        assert(sz > 0);
        array = new T[size]();
    }

    ~Vector() {
        delete[] array;
    }

    // Prevent accidental shallow copies of an owning dynamic array.
    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;

    T& operator[](int i) {
        assert(i >= 0 && i < size);
        return array[i];
    }

    const T& operator[](int i) const {
        assert(i >= 0 && i < size);
        return array[i];
    }

    void ascending_sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (greater_value(array[i], array[j])) {
                    swap_values(array[i], array[j]);
                }
            }
        }
    }

private:
    T* array;
    int size;

    void swap_values(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
};

int main() {
    Vector<int> x(3);
    x[0] = 999;
    x[1] = -77;
    x[2] = 88;

    Vector<int>::VectIter iter(x);
    cout << "\n\nThe first element of vector x contains: " << *iter;

#if 1
    cout << "\nTesting an <int> Vector: " << endl;
    cout << "\n\nTesting sort";
    x.ascending_sort();
    for (int i = 0; i < 3; ++i) cout << endl << iter++;

    cout << "\n\nTesting Prefix --:";
    for (int i = 0; i < 3; ++i) cout << endl << --iter;

    cout << "\n\nTesting Prefix ++:";
    for (int i = 0; i < 3; ++i) cout << endl << ++iter;

    cout << "\n\nTesting Postfix --";
    for (int i = 0; i < 3; ++i) cout << endl << iter--;

    cout << endl << "Testing a <Mystring> Vector: " << endl;
    Vector<Mystring> y(3);
    y[0] = "Bar";
    y[1] = "Foo";
    y[2] = "All";
    Vector<Mystring>::VectIter iters(y);

    cout << "\n\nTesting sort";
    y.ascending_sort();
    for (int i = 0; i < 3; ++i) cout << endl << iters++;

    cout << "\n\nTesting Prefix --:";
    for (int i = 0; i < 3; ++i) cout << endl << --iters;

    cout << "\n\nTesting Prefix ++:";
    for (int i = 0; i < 3; ++i) cout << endl << ++iters;

    cout << "\n\nTesting Postfix --";
    for (int i = 0; i < 3; ++i) cout << endl << iters--;

    cout << endl << "Testing a <char *> Vector: " << endl;
    Vector<const char*> z(3);
    z[0] = "Orange";
    z[1] = "Pear";
    z[2] = "Apple";
    Vector<const char*>::VectIter iterchar(z);

    cout << "\n\nTesting sort";
    z.ascending_sort();
    for (int i = 0; i < 3; ++i) cout << endl << iterchar++;
#endif

    cout << "\nProgram Terminated Successfully." << endl;
    return 0;
}
