//
//  Stack.Test.cpp
//  Data Course
//
//  Created by Inna Soboleva on 10/3/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "Stack.h"


int main()
{
    cout << "\n---TEST INT STACK---\n";
    // Checking template array of integers
    Stack<int> a;
    
    // Array constructor
    cout << "\nTesting Stack::Stack\n";
    assert(a.peek() == 0); // default value is 0
    
    // Stack::push()
    cout << "\nTesting Stack::push() and Stack::pop() and Stack::peek()\n";
    Stack<int> b = a;
    b.push(1);
    b.push(2);
    b.push(3);
    cout << "EXPECTED: 3 \n";
    cout << "ACTUAL: " << b.peek() << endl;
    b.pop();
    assert(b.peek() == 2);
    b.pop();
    assert(b.peek() == 1);
    
    a.pop(); // nothing should happen, "a" is empty
    
    // object copy test
    cout << "\nObject copy test\n";
    Stack<int> d = b; // making a copy, "a" contains 1 element
    assert(b.peek() == d.peek());
    cout << "EXPECTED: 1 twice \n";
    cout << "ACTUAL: " << b.peek() << endl;
    cout << "ACTUAL: " << d.peek() << endl;
    
    // Stack::peek()
    Stack<int> c;
    assert(c.peek() == 0); // should return Int dummy value
    
    // object assignment test
    cout << "\nObject assignment test\n";
    Stack<int> e;
    e = b; // "b" has 1 element
    assert(b.peek() == e.peek());
    e.pop();
    
    // const object test
    cout << "\nConst object test\n";
    const Stack<int> f; // if this compiles, Stack::Stack main constructor exists
    
    
    cout << "\n---TEST STRING STACK---\n";
    // Checking template array of strings
    Stack<string> g;
    
    // Array constructor
    cout << "\nTesting Stack::Stack\n";
    assert(g.peek() == "");
    
    // Stack::push()
    cout << "\nTesting Stack::push() and Stack::pop() and Stack::peek()\n";
    Stack<string> h = g;
    h.push("cars");
    h.push("bears");
    h.push("cartoon");
    cout << "EXPECTED: cartoon \n";
    cout << "ACTUAL: " << h.peek() << endl;
    h.pop();
    assert(h.peek() == "bears");
    h.pop();
    assert(h.peek() == "cars");
    
    g.pop(); // nothing should happen, "g" is empty
    
    // object copy test
    cout << "\nObject copy test\n";
    Stack<string> i = h; // making a copy, "h" contains 1 element
    assert(i.peek() == h.peek());
    cout << "EXPECTED: cars twice \n";
    cout << "ACTUAL: " << i.peek() << endl;
    cout << "ACTUAL: " << h.peek() << endl;
    
    // Stack::peek()
    Stack<string> j;
    assert(j.peek() == ""); // should return String dummy value
    
    // object assignment test
    cout << "\nObject assignment test\n";
    Stack<string> k;
    k = h; // "h" has 1 element
    assert(k.peek() == h.peek());
    
    // const object test
    cout << "\nConst object test\n";
    const Stack<string> l; // if this compiles, Stack::Stack main constructor exists
    
    cout << "\n---TEST DOUBLE STACK---\n";
    // Checking template array of doubles
    Stack<double> m;
    
    // Array constructor
    cout << "\nTesting Stack::Stack\n";
    assert(m.peek() == 0.0);
    
    // Stack::push()
    cout << "\nTesting Stack::push() and Stack::pop() and Stack::peek()\n";
    Stack<double> n = m;
    n.push(1.11);
    n.push(2.12);
    n.push(3.13);
    cout << "EXPECTED: 3.13 \n";
    cout << "ACTUAL: " << n.peek() << endl;
    n.pop();
    assert(n.peek() == 2.12);
    n.pop();
    assert(n.peek() == 1.11);
    
    m.pop(); // nothing should happen, "m" is empty
    
    // object copy test
    cout << "\nObject copy test\n";
    Stack<double> o = n; // making a copy, "n" contains 1 element
    assert(o.peek() == n.peek());
    cout << "EXPECTED: 1.11 twice \n";
    cout << "ACTUAL: " << o.peek() << endl;
    cout << "ACTUAL: " << n.peek() << endl;
    
    // Stack::peek()
    Stack<double> p;
    assert(p.peek() == 0.0); // should return Double dummy value
    
    // object assignment test
    cout << "\nObject assignment test\n";
    Stack<double> r;
    r = n; // "n" has 1 element
    assert(r.peek() == n.peek());
    
    // const object test
    cout << "\nConst object test\n";
    const Stack<double> s; // if this compiles, Stack::Stack main constructor exists
    
    cout << "\n---TEST CHAR STACK---\n";
    // Checking template array of chars
    Stack<char> t;
    
    // Array constructor
    cout << "\nTesting Stack::Stack\n";
    assert(t.peek() == '\0');
    
    // Stack::push()
    cout << "\nTesting Stack::push() and Stack::pop() and Stack::peek()\n";
    Stack<char> u = t;
    u.push('a');
    u.push('b');
    u.push('c');
    cout << "EXPECTED: c \n";
    cout << "ACTUAL: " << u.peek() << endl;
    u.pop();
    assert(u.peek() == 'b');
    u.pop();
    assert(u.peek() == 'a');
    
    t.pop(); // nothing should happen, "t" is empty
    
    // object copy test
    cout << "\nObject copy test\n";
    Stack<char> v = u; // making a copy, "u" contains 1 element
    assert(v.peek() == u.peek());
    cout << "EXPECTED: a twice \n";
    cout << "ACTUAL: " << v.peek() << endl;
    cout << "ACTUAL: " << u.peek() << endl;
    
    // Stack::peek()
    Stack<char> w;
    assert(w.peek() == 0.0); // should return Char dummy value
    
    // object assignment test
    cout << "\nObject assignment test\n";
    Stack<char> x;
    x = u; // "u" has 1 element
    assert(x.peek() == u.peek());
    
    // const object test
    cout << "\nConst object test\n";
    const Stack<char> z; // if this compiles, Stack::Stack main constructor exists
    
}


