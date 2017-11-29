//
//  AssociativeArray.h
//  Data Course
//
//  Created by Inna Soboleva on 10/26/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#include "Queue.h"
using namespace std;

#ifndef AssociativeArray_h
#define AssociativeArray_h

template <typename K, typename V>
class AssociateArray
{
    struct Node
    {
        K key;
        V value;
        Node* next;
    };
    
    Node* firstNode; // the head pointer
    int siz; // tracking the number of nodes
    
    public:
    AssociateArray(); // constructor prototype
    int size() const { return siz; }
    void clear();
    
    V operator[](const K&) const; // getter
    V& operator[](const K&); // setter
    bool containsKey(const K&) const; // getter
    void deleteKey(const K&); // setter
    Queue<K> keys() const;
    
    ~AssociateArray(); // destructor
    AssociateArray(const AssociateArray<K, V>&); // copy constructor prototype
    AssociateArray<K, V>& operator=(const AssociateArray<K, V>&); // assignment operator prototype
    
};

template <typename K, typename V>
AssociateArray<K, V>::AssociateArray() // main constructor
{
    firstNode = 0;
    siz = 0;

};

template <typename K, typename V>
AssociateArray<K, V>::~AssociateArray()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
    }
}

template <typename K, typename V>
AssociateArray<K, V>::AssociateArray(const AssociateArray<K, V>& original) // copy constructor
{
    firstNode = 0;
    Node* lastNode = 0;
    siz = original.siz;
    for (Node* p = original.firstNode; p; p = p->next)
    {
        Node* temp = new Node;
        temp->key = p->key;
        temp->value = p->value;
        temp->next = 0;
        if (lastNode)
            lastNode->next = temp;
        else
            firstNode = temp;
        lastNode = temp;
    }
}

template <typename K, typename V>
AssociateArray<K, V>& AssociateArray<K, V>::operator=(const AssociateArray<K, V>& original) // Assignment Operator
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
        Node* lastNode = 0; // temporary tail
        for (Node* p = original.firstNode; p; p = p->next)
        {
            Node* temp = new Node;
            temp->key = p->key;
            temp->value = p->value;
            temp->next = 0;
            if (lastNode)
                lastNode->next = temp;
            else
                firstNode = temp;
            lastNode = temp;
        }
        siz = original.siz;
    }
    return *this;
}

template <typename K, typename V>
void AssociateArray<K, V>::clear()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}

template <typename K, typename V>
V AssociateArray<K, V>::operator[](const K& key) const
{
    for (Node* p = firstNode; p; p = p->next)
        if (p->key == key)
            return p->value;
    V dummy = V();
    return dummy;
}

template <typename K, typename V>
V& AssociateArray<K, V>::operator[](const K& key)
{
    for (Node* p = firstNode; p; p = p->next) {
        if (p->key == key)
        {
            return p->value;
        }
    }
    ++siz;
    Node* temp = new Node;
    temp->key = key;
    temp->value = V();
    temp->next = firstNode;
    firstNode = temp;
    return firstNode->value;
    
}

template <typename K, typename V>
bool AssociateArray<K, V>::containsKey(const K& key) const
{
    for (Node* p = firstNode; p; p = p->next)
        if (p->key == key)
            return true;
    return false;
}

template <typename K, typename V>
void AssociateArray<K, V>::deleteKey(const K& key)
{
    Node* p, *prev; // declare above loop so that it survives below the loop
    for (p = firstNode, prev = 0; p; prev =p, p = p->next)
        if (p->key == key)
            break;
    
    // if found (that is, p did not run off the end of the list)
    if (p)
    {
        --siz;
        if (prev)
            prev->next = p->next; // skips over the node at p
        else
            firstNode = p->next; // there's a new head, possibly zero
        delete p; // we're done with this node
    }
}

template <typename K, typename V>
Queue<K> AssociateArray<K, V>::keys() const
{
    Queue<K> *q = new Queue<K>;
    Node* p = firstNode;
    while (p)
    {
        q->push(p->key);
        p = p->next;
    }
    return *q;
}

#endif /* AssociativeArray_h */
