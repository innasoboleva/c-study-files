//
//  Queue.h
//  Data Course
//
//  Created by Inna Soboleva on 10/2/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

template <typename V>
class Queue             // implementing LIFO method
{
    struct Node
    {
        V value;
        Node* next;
    };
    
    Node* firstNode; // the head pointer
    Node* lastNode; // the tail pointer
    int siz; // tracking the number of nodes
    V dummy;
    
    
public:
    Queue(); // constructor prototype
    ~Queue(); // destructor
    Queue(const Queue<V>&); // copy constructor prototype
    Queue<V>& operator=(const Queue<V>&); // assignment operator prototype
    void pop();
    void clear();
    void push(const V&);
    V& front(); // return a mutable reference to the oldest node
    V& back(); // return a mutable reference to the newest node
    int size() const { return siz; }
    bool empty() const;
    
};

template <typename V>
Queue<V>::Queue() // main constructor
{
    firstNode = 0;
    lastNode = 0;
    siz = 0;
    dummy = V();
};

template <typename V>
Queue<V>::~Queue()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
    }
}

template <typename V>
Queue<V>::Queue(const Queue<V>& original) // copy constructor
{
    firstNode = 0;
    lastNode = 0;
    siz = original.siz;
    for (Node* p = original.firstNode; p; p = p->next)
    {
        Node* temp = new Node;
        temp->value = p->value;
        temp->next = 0;
        if (lastNode)
            lastNode->next = temp;
        else
            firstNode = temp;
        lastNode = temp;
    }
}

template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V>& original) // Assignment Operator
{
    if (this != &original)
    {
        // deallocate existing list
        while (firstNode)
        {
            Node* p = firstNode->next;
            delete firstNode;
            firstNode = p;
        }
        
        // build new queue
        lastNode = 0;
        for (Node* p = original.firstNode; p; p = p->next)
        {
            Node* temp = new Node;
            temp->value = p->value;
            temp->next = 0;
            if (lastNode) lastNode->next = temp;
            else firstNode = temp;
            lastNode = temp;
        }
        siz = original.siz;
    }
    return *this;
}

template <typename V>
void Queue<V>::clear()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
    lastNode = 0;
}

template <typename V>
void Queue<V>::pop()
{
    if (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
    if (siz == 0)
        lastNode = 0;
}

template <typename V>
void Queue<V>::push(const V& value)
{
    Node* temp = new Node;
    temp->value = value;
    temp->next = 0;
    if (lastNode)
        lastNode->next = temp;
    else
        firstNode = temp;
    lastNode = temp;
    ++siz;
}

template <typename V>
V& Queue<V>::front()
{
    if (firstNode == 0)
        return dummy;
    else
        return firstNode->value;
}

template <typename V>
V& Queue<V>::back()
{
    if (lastNode == 0)
        return dummy;
    else
        return lastNode->value;
}

template <typename V>
bool Queue<V>::empty() const
{
    if (siz == 0)
        return true;
    else
        return false;
}

#endif /* Queue_h */
