//
//  Queue.TestDriver.cpp
//  Data Course
//
//  Created by Inna Soboleva on 10/3/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "Queue.h"


int main()
{
    cout << "\n---TEST INT QUEUE---\n";
    // Checking template queue of integers
    Queue<int> a;
    
    // Queue constructor
    cout << "\nTesting Queue::Queue\n";
    assert(a.front() == 0); // default value is 0
    assert(a.back() == 0);
    
    // Queue::push()
    cout << "\nTesting Queue::push() and Queue::pop() and Queue::front() and Queue::back()\n";
    Queue<int> b = a;
    b.push(1);
    b.push(2);
    b.push(3);
    cout << "EXPECTED: 1 \n";
    cout << "ACTUAL: " << b.front() << endl;
    cout << "EXPECTED: 3 \n";
    cout << "ACTUAL: " << b.back() << endl;
    b.pop();
    cout << "EXPECTED: 2 \n";
    cout << "ACTUAL: " << b.front() << endl;
    assert(b.front() == 2);
    b.pop();
    assert(b.front() == 3);
    
    a.pop(); // nothing should happen, "a" is empty
    assert(a.front() == 0);
    assert(a.back() == 0);
    
    // object copy test
    cout << "\nObject copy test\n";
    Queue<int> d = b; // making a copy, "a" contains 1 element
    assert(b.front() == d.front());
    cout << "EXPECTED: 3 twice \n";
    cout << "ACTUAL: " << b.front() << endl;
    cout << "ACTUAL: " << d.front() << endl;
    cout << "EXPECTED: 3 twice more \n";
    cout << "ACTUAL: " << b.back() << endl;
    cout << "ACTUAL: " << d.back() << endl;
    
    // Queue::font() and Queue::back()
    Queue<int> c;
    assert(c.front() == 0); // should return Int dummy value
    assert(c.back() == 0);
    
    // object assignment test
    cout << "\nObject assignment test\n";
    Queue<int> e;
    e = b; // "b" has 1 element
    assert(b.front() == e.front());
    assert(b.back() == e.back());
    e.pop();
    
    // const object test
    cout << "\nConst object test\n";
    const Queue<int> f; // if this compiles, Queue::Queue main constructor exists
    
    
    cout << "\n---TEST STRING QUEUE---\n";
    // Checking template queue of strings
    Queue<string> g;
    
    // Queue constructor
    cout << "\nTesting Queue::Queue\n";
    assert(g.front() == "");
    assert(g.back() == "");
    
    // Queue::push()
    cout << "\nTesting Queue::push() and Queue::pop() and Queue::front() and Queue::back()\n";
    Queue<string> h = g;
    h.push("cars");
    h.push("bears");
    h.push("cartoon");
    cout << "EXPECTED: cars \n";
    cout << "ACTUAL: " << h.front() << endl;
    cout << "EXPECTED: cartoon \n";
    cout << "ACTUAL: " << h.back() << endl;
    h.pop();
    assert(h.front() == "bears");
    h.pop();
    assert(h.front() == "cartoon");
    assert(h.back() == "cartoon");
    
    g.pop(); // nothing should happen, "g" is empty
    assert(g.front() == "");
    assert(g.back() == "");
    
    // object copy test
    cout << "\nObject copy test\n";
    Queue<string> i = h; // making a copy, "h" contains 1 element
    assert(i.front() == h.front());
    cout << "EXPECTED: cartoon twice \n";
    cout << "ACTUAL: " << i.front() << endl;
    cout << "ACTUAL: " << h.front() << endl;
    cout << "EXPECTED: cartoon twice more \n";
    cout << "ACTUAL: " << i.back() << endl;
    cout << "ACTUAL: " << h.back() << endl;
    
    // Queue::front() and Queue::back()
    Queue<string> j;
    assert(j.front() == ""); // should return String dummy value
    assert(j.back() == "");
    
    // object assignment test
    cout << "\nObject assignment test\n";
    Queue<string> k;
    k = h; // "h" has 1 element
    assert(k.front() == h.front());
    assert(k.back() == h.back());
    
    // const object test
    cout << "\nConst object test\n";
    const Queue<string> l; // if this compiles, Queue::Queue main constructor exists
    
    cout << "\n---TEST DOUBLE QUEUE---\n";
    // Checking template queue of doubles
    Queue<double> m;
    
    // Queue constructor
    cout << "\nTesting Queue::Queue\n";
    assert(m.front() == 0.0);
    assert(m.back() == 0.0);
    
    // Queue::push()
    cout << "\nTesting Queue::push() and Queue::pop() and Queue::front() and Queue::back()\n";
    Queue<double> n = m;
    n.push(1.11);
    n.push(2.12);
    n.push(3.13);
    cout << "EXPECTED: 1.11 \n";
    cout << "ACTUAL: " << n.front() << endl;
    cout << "EXPECTED: 3.13 \n";
    cout << "ACTUAL: " << n.back() << endl;
    n.pop();
    assert(n.front() == 2.12);
    n.pop();
    assert(n.front() == 3.13);
    assert(n.back() == 3.13);
    
    m.pop(); // nothing should happen, "m" is empty
    assert(m.front() == 0.0);
    assert(m.back() == 0.0);
    
    // object copy test
    cout << "\nObject copy test\n";
    Queue<double> o = n; // making a copy, "n" contains 1 element
    assert(o.front() == n.front());
    assert(o.back() == n.back());
    cout << "EXPECTED: 3.13 twice \n";
    cout << "ACTUAL: " << o.front() << endl;
    cout << "ACTUAL: " << n.front() << endl;
    cout << "EXPECTED: 3.13 twice more \n";
    cout << "ACTUAL: " << o.back() << endl;
    cout << "ACTUAL: " << n.back() << endl;
    
    // Queue::front() and Queue::back()
    Queue<double> p;
    assert(p.front() == 0.0); // should return Double dummy value
    assert(p.back() == 0.0);
    
    // object assignment test
    cout << "\nObject assignment test\n";
    Queue<double> r;
    r = n; // "n" has 1 element
    assert(r.front() == n.front());
    assert(r.back() == n.back());
    
    // const object test
    cout << "\nConst object test\n";
    const Queue<double> s; // if this compiles, Queue::Queue main constructor exists
    
    cout << "\n---TEST CHAR QUEUE---\n";
    // Checking template queue of chars
    Queue<char> t;
    
    // Queue constructor
    cout << "\nTesting Queue::Queue\n";
    assert(t.front() == '\0');
    assert(t.back() == '\0');
    
    // Queue::push()
    cout << "\nTesting Queue::push() and Queue::pop() and Queue::front() and Queue::back()\n";
    Queue<char> u = t;
    u.push('a');
    u.push('b');
    u.push('c');
    cout << "EXPECTED: a \n";
    cout << "ACTUAL: " << u.front() << endl;
    cout << "EXPECTED: c \n";
    cout << "ACTUAL: " << u.back() << endl;
    u.pop();
    assert(u.front() == 'b');
    u.pop();
    assert(u.front() == 'c');
    assert(u.back() == 'c');
    
    t.pop(); // nothing should happen, "t" is empty
    assert(t.front() == t.back());
    
    // object copy test
    cout << "\nObject copy test\n";
    Queue<char> v = u; // making a copy, "u" contains 1 element
    assert(v.front() == u.front());
    assert(v.back() == u.back());
    cout << "EXPECTED: c twice \n";
    cout << "ACTUAL: " << v.front() << endl;
    cout << "ACTUAL: " << u.front() << endl;
    cout << "EXPECTED: c twice more \n";
    cout << "ACTUAL: " << v.back() << endl;
    cout << "ACTUAL: " << u.back() << endl;
    
    // Queue::front() and Queue::back()
    Queue<char> w;
    assert(w.front() == 0.0); // should return Char dummy value
    assert(w.back() == 0.0);
    
    // object assignment test
    cout << "\nObject assignment test\n";
    Queue<char> x;
    x = u; // "u" has 1 element
    assert(x.front() == u.front());
    assert(x.back() == u.back());
    
    // const object test
    cout << "\nConst object test\n";
    const Queue<char> z; // if this compiles, Queue::Queue main constructor exists
    
}
