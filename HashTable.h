//
//  HashTable.h
//  Data Course
//
//  Created by Inna Soboleva on 11/4/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#include <list>
#include "Queue.h"
using namespace std;

#ifndef HashTable_h
#define HashTable_h

template <typename K, typename V, int CAP>
class HashTable
{
    struct Node
    {
        K key;
        V value;
    };
    
    list<Node> data[CAP];
    int(*hashCode)(const K&); // alias for hash code function
    int siz;
    V dummy;
    
    
    public:
    HashTable();
    HashTable(int(*func)(const K&)); // constructor prototype
    V& operator[](const K&); // setter
    V operator[](const K&) const; // getter
    bool containsKey(const K&) const;
    int size() const { return siz; }
    void clear();
    void deleteKey(const K&); // setter
    Queue<K> keys() const;
    ~HashTable(); // destructor
    HashTable(const HashTable<K, V, CAP>&); // copy constructor prototype
    HashTable<K, V, CAP>& operator=(const HashTable<K, V, CAP>&); // assignment operator prototype
};

template <typename K, typename V, int CAP>
HashTable<K, V, CAP>::HashTable()
{
    dummy = V();
    siz = 0;
}

template <typename K, typename V, int CAP>
HashTable<K, V, CAP>::~HashTable()
{
    
}

template <typename K, typename V, int CAP>
HashTable<K, V, CAP>::HashTable(const HashTable<K, V, CAP>& original) // copy constructor
{
    dummy = original.dummy;
    hashCode = original.hashCode;
    siz = original.siz;

    typename list<Node>::const_iterator it;
    
    for(int i=0; i < CAP; i++)
    {
        for (it = original.data[i].begin(); it != original.data[i].end(); it++)
        {
            Node *node = new Node();
            node->key = it->key;
            node->value = it->value;
            data[i].push_back(*node);
        }
    }
}

template <typename K, typename V, int CAP>
HashTable<K, V, CAP>& HashTable<K, V, CAP>::operator=(const HashTable<K, V, CAP>& original) // Assignment Operator
{
    if (this != &original)
    {
        this->clear();
        
        typename list<Node>::const_iterator it;
        for(int i=0; i < CAP; i++)
        {
            for (it = original.data[i].begin(); it != original.data[i].end(); it++)
            {
                Node *node = new Node();
                node->key = it->key;
                node->value = it->value;
                data[i].push_back(*node);
            }
        }
        
        dummy = original.dummy;
        hashCode = original.hashCode;
        siz = original.siz;
    }
    return *this;
}

template <typename K, typename V, int CAP>
HashTable<K, V, CAP>::HashTable(int(*func)(const K&))
{
    hashCode = func;
    dummy = V();
    siz = 0;
}

template <typename K, typename V, int CAP>
bool HashTable<K,V,CAP>::containsKey(const K& key) const
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::const_iterator it; // getters need to use const_iterator
    for (it = data[index].begin(); it != data[index].end(); it++)
        if (it->key == key)
            break;
    if (it == data[index].end())
        return false;
    return true;
}

template <typename K, typename V, int CAP>
V& HashTable<K,V,CAP>::operator[](const K& key)
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++) {
        if (it->key == key) {
            return it->value;
        }
    }

    Node *node = new Node();
    node->key = key;
    node->value = V();
    it = data[index].insert(it, *node); //Iterator that points to newly inserted Node
    siz++;
    return it->value;
}

template <typename K, typename V, int CAP>
V HashTable<K,V,CAP>::operator[](const K& key) const
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::const_iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
    break;
    if (it == data[index].end()) // not found
    return dummy;
    if (it != data[index].end()) // found
    return it->value; // is the value
}

template <typename K, typename V, int CAP>
Queue<K> HashTable<K, V, CAP>::keys() const
{
    Queue<K> *q = new Queue<K>;
    typename list<Node>::const_iterator it;
    for(int i=0; i < CAP; i++)
    {
        for (it = data[i].begin(); it != data[i].end(); it++)
        {
            q->push(it->key);
        }
    }
    return *q;
}

template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::deleteKey(const K& key)
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::iterator it; // getters need to use const_iterator
    for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
        break;
    if (it != data[index].end())
    {
        data[index].erase(it);
        --siz;
    }   // removes the key-value pair
}

template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::clear()
{
    siz = 0;
    for(int i=0; i < CAP; i++)
    {
        data[i].clear();
    }
}


#endif /* HashTable_h */
