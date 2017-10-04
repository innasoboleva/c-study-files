//
//  DynamicArray.h
//  Data Course
//
//  Created by Inna Soboleva on 9/9/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#ifndef DynamicArray_h
#define DynamicArray_h

#include <algorithm>
using namespace std;

template <typename V>
class DynamicArray
{
    V* values;
    int cap;
    V dummy;
    
    
public:
    DynamicArray(int = 2); // constructor prototype
    ~DynamicArray() {delete [] values;} // destructor
    DynamicArray(const DynamicArray<V>&); // copy constructor prototype
    int capacity() const {return cap;}
    void capacity(int); // setter capacity prototype
    V operator[](int) const;
    V& operator[](int);
    DynamicArray<V>& operator=(const DynamicArray<V>&); // assignment operator prototype
    
};

template <typename V>
DynamicArray<V>::DynamicArray(int cap) // main constructor
{
    this->cap = cap;
    values = new V[cap];
    for (int i = 0; i < cap; i++) // copy the contents of the array from the original
        values[i] = V();
    dummy = V();
};

template <typename V>
DynamicArray<V>::DynamicArray(const DynamicArray<V>& original) // copy constructor
{
    cap = original.cap;
    values = new V[cap]; // not a copy - new object gets its own array
    
    for (int i = 0; i < cap; i++) // copy the contents of the array from the original
        values[i] = original.values[i];
    dummy = original.dummy;
}

template <typename V>
V DynamicArray<V>::operator[](int index) const
{
    if (index < 0)
        return dummy;
    if (index >= cap)
        return dummy;
    return values[index];
}

template <typename V>
V& DynamicArray<V>::operator[](int index)
{
    if (index < 0)
        return dummy;
    if (index >= cap)
        capacity(2 * index);
    return values[index];
}

template <typename V>
DynamicArray<V>& DynamicArray<V>::operator=(const DynamicArray<V>& original)
{
    if (this != &original) // if it's not a self copy
    {
        // do what the destructor does
        delete [] values;
        
        // do what the copy constructor does
        cap = original.cap; // just a copy
        values = new V[cap]; // not a copy - new object gets its own array
        for (int i = 0; i < cap; i++) // copy the contents of the array from the original
            values[i] = original.values[i];
        dummy = original.dummy;
    }
    
    return *this; // return a self reference
}

template <typename V>
void DynamicArray<V>::capacity(int cap)
{
    // allocate a new array with the new capacity
    V* temp = new V[cap];
    
    // get the lesser of the new and old capacities
    int limit = min(cap, this->cap);
    
    // copy the contents
    for (int i = 0; i < limit; i++)
        temp[i] = values[i];
    
    // set added values to their defaults
    for (int i = limit; i < cap; i++)
        temp[i] = V();
    
    // deallocate original array
    delete [] values;
    
    // switch newly allocated array into the object
    values = temp;
    
    //update the capacity
    this->cap = cap;
}

#endif /* DynamicArray_h */
