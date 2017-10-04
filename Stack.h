//
//  Stack.h
//  Data Course
//
//  Created by Inna Soboleva on 10/2/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

template <typename V>
class Stack             // implementing LIFO method
{
    struct Node
    {
        V value;
        Node* next;
    };
    
    Node* firstNode; // the head pointer
    int siz; // tracking the number of nodes
    V dummy;
    
    
public:
    Stack(); // constructor prototype
    ~Stack(); // destructor
    Stack(const Stack<V>&); // copy constructor prototype
    Stack<V>& operator=(const Stack<V>&); // assignment operator prototype
    void pop();
    void clear();
    V& peek();
    void push(const V&);
    
};

template <typename V>
Stack<V>::Stack() // main constructor
{
    firstNode = 0;
    siz = 0;
    dummy = V();
};

template <typename V>
Stack<V>::~Stack()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
    }
}

template <typename V>
Stack<V>::Stack(const Stack<V>& original) // copy constructor
{
    firstNode = 0;
    Node* lastNode = 0; // temporary tail
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
Stack<V>& Stack<V>::operator=(const Stack<V>& original) // Assignment Operator
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
void Stack<V>::clear()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}

template <typename V>
void Stack<V>::pop()
{
    if (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}

template <typename V>
void Stack<V>::push(const V& value)
{
    Node* temp = new Node;
    temp->value = value;
    
    if (firstNode)
    {
        temp->next = firstNode;
    }
    else {
        temp->next = 0;
    }
    firstNode = temp;
    ++siz;
}

template <typename V>
V& Stack<V>::peek()
{
    if (firstNode == 0)
        return dummy;
    else
        return firstNode->value;
}


#endif /* Stack_h */
