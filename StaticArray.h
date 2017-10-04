//
//  StaticArray.h
//  Data Course
//
//  Created by Inna Soboleva on 9/9/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#ifndef StaticArray_h
#define StaticArray_h

template <typename V, int CAP>
class StaticArray
{
    V values[CAP];
    V dummy;
    
    
public:
    StaticArray(); // constructor
    int capacity() const {return CAP;}
    V operator[](int) const;
    V& operator[](int);
};

template <typename V, int CAP>
StaticArray<V, CAP>::StaticArray()
{
    dummy = V();
    for (int i=0; i < CAP; i++)
        values[i] = V();
};

template <typename V, int CAP>
V StaticArray<V, CAP>::operator[](int index) const
{
    if (index < 0)
        return dummy;
    if (index >= CAP)
        return dummy;
    return values[index];
}

template <typename V, int CAP>
V& StaticArray<V, CAP>::operator[](int index)
{
    if (index < 0)
        return dummy;
    if (index >= CAP)
        return dummy;
    return values[index];
}

#endif /* StaticArray_h */
