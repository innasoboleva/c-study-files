//
//  SortableArray.h
//  Data Course
//
//  Created by Inna Soboleva on 11/19/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#ifndef SortableArray_h
#define SortableArray_h

#include <algorithm>
#include <cstdlib>
using namespace std;

template <typename V>
class SortableArray
{
    V* values;
    int cap;
    V dummy;
    
    
public:
    SortableArray(int = 2); // constructor prototype
    ~SortableArray() {delete [] values;} // destructor
    SortableArray(const SortableArray<V>&); // copy constructor prototype
    int capacity() const {return cap;}
    void capacity(int); // setter capacity prototype
    V operator[](int) const;
    V& operator[](int);
    SortableArray<V>& operator=(const SortableArray<V>&); // assignment operator prototype
    void sort(int); // sort function (specifies how many elements to sort)
    
};

template <typename V>
SortableArray<V>::SortableArray(int cap) // main constructor
{
    this->cap = cap;
    values = new V[cap];
    for (int i = 0; i < cap; i++) // copy the contents of the array from the original
        values[i] = V();
    dummy = V();
};

template <typename V>
SortableArray<V>::SortableArray(const SortableArray<V>& original) // copy constructor
{
    cap = original.cap;
    values = new V[cap]; // not a copy - new object gets its own array
    
    for (int i = 0; i < cap; i++) // copy the contents of the array from the original
        values[i] = original.values[i];
    dummy = original.dummy;
}

template <typename V>
SortableArray<V>& SortableArray<V>::operator=(const SortableArray<V>& original)
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
void SortableArray<V>::capacity(int cap)
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

template <typename V>
V SortableArray<V>::operator[](int index) const
{
    if (index < 0)
        return dummy;
    if (index >= cap)
        return dummy;
    return values[index];
}

template <typename V>
V& SortableArray<V>::operator[](int index)
{
    if (index < 0)
        return dummy;
    if (index >= cap)
        capacity(2 * index);
    return values[index];
}

template <typename V>
void SortableArray<V>::sort(int number) // implementing merge sort
{
    V *temp = new V[number];
    for(int delta = 1; delta < number; delta *= 2)
    {
        int index = 0;
        for(int i = 0; i < number; i++)
        {
            temp[i] = values[i];
        }
        for(int i = 0; i < number; i+= 2*delta)
        {
            int left = i;
            int leftMax = min(left + delta, number);
            int right = leftMax;
            int rightMax = min(right + delta, number);
            while(true)
            {
                if(left == leftMax && right == rightMax)
                    break;
                if(left == leftMax)
                    values[index++] = temp[right++];
                else if(right == rightMax)
                    values[index++] = temp[left++];
                else if(temp[right] < temp[left])
                    values[index++] = temp[right++];
                else
                    values[index++] = temp[left++];
            }
        }
    }
    delete [] temp;
}

#endif /* SortableArray_h */
