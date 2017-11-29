//
//  PriorityQueue.h
//  Data Course
//
//  Created by Inna Soboleva on 11/6/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#ifndef PriorityQueue_h
#define PriorityQueue_h

template <typename V>
class PriorityQueue
{
    V* values; // array
    int cap;
    int siz;
    
public:
    PriorityQueue(int = 2);
    ~PriorityQueue() {delete [] values;}
    PriorityQueue(const PriorityQueue<V>&); // copy constructor prototype
    PriorityQueue<V>& operator=(const PriorityQueue<V>&); // assignment operator prototype
    void capacity(int); // setter capacity prototype
    int size() const { return siz; }
    V top() const; // the "peek" implementation
    void pop();
    void push(const V&);
    void clear();
    bool empty() const;
};

template <typename V>
PriorityQueue<V>::PriorityQueue(int cap) // main constructor
{
    this->cap = cap;
    values = new V[cap];
}

template <typename V>
void PriorityQueue<V>::capacity(int cap)
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
V PriorityQueue<V>::top() const
{
    if(siz == 0)
    {
        V dummy = V();
        return dummy;
    }
    return values[0];
}

template <typename V>
void PriorityQueue<V>::push(const V& value)
{
    if (siz == cap)
    {
        capacity(2 * siz);
    }
    values[siz] = value;
    int index = siz;
    
    while(true)
    {
        int parentIndex = (index + 1)/2 - 1;
        if(index == 0)
        {
            break;
        }
        if(values[index] < values[parentIndex])
        {
            break; // (no more promotions)
        }
        V temp = values[parentIndex];
        values[parentIndex] = values[index];
        values[index] = temp; // swap values at the parent index and index -- promote and demote
        index = parentIndex; // set index equal to the parent index -- traversing up the tree
    }
    siz++;
}

template <typename V>
void PriorityQueue<V>::pop()
{
    if(siz != 0)
    {
        int index = 0;
        while(true)
        {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            
            bool leftChildNotExist = false;
            if (leftChildIndex >= siz)
                leftChildNotExist = true;
            
            bool rightChildNotExist = false;
            if (rightChildIndex >= siz)
                rightChildNotExist = true;
            
            if(leftChildNotExist)
            {
                break;
            }
            if(rightChildNotExist)
            {
                values[index] = values[leftChildIndex];
                index = leftChildIndex;
            }
            else if(values[rightChildIndex] < values[leftChildIndex])
            {
                values[index] = values[leftChildIndex];
                index = leftChildIndex;
            }
            else
            {
                values[index] = values[rightChildIndex];
                index = rightChildIndex;
            }
        }
        siz--;
        values[index] = values[siz];
        while(true)
        {
            if(index == siz)
            {
                break;
            }
            int parentIndex = (index + 1)/2 - 1;
            if(values[index] < values[parentIndex])
            {
                break; // (no more promotions)
            }
            V temp = values[parentIndex];
            values[parentIndex] = values[index];
            values[index] = temp; // swap values at the parent index and index -- promote and demote
            index = parentIndex; // set index equal to the parent index -- traversing up the tree
        }
    }
        
}

template <typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original) // copy constructor
{
    siz = original.siz;
    cap = original.cap;
    values = new V[cap];
    
    for (int i = 0; i < siz; i++)
    {
        values[i] = original.values[i];
    }
}

template <typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original) // Assignment Operator
{
    if (this != &original)
    {
        // deallocate existing list
        delete [] values;
        cap = original.cap;
        siz = original.siz;
        
        // build new queue
        values = new V[cap];
        for (int i = 0; i < siz; i++)
        {
            values[i] = original.values[i];
        }
    }
    return *this;
}

template <typename V>
void PriorityQueue<V>::clear()
{
    delete [] values;
    values = new V[cap];
    siz = 0;
}

template <typename V>
bool PriorityQueue<V>::empty() const
{
    if (siz == 0)
        return true;
    return false;
}

#endif /* PriorityQueue_h */
