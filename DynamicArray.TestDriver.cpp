//
//  DynamicArray.TestDriver.cpp
//  Data Course
//
//  Created by Inna Soboleva on 8/21/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include <cassert>


#include "DynamicArray.h"
#include "DynamicArray.h" // ifndef test


int main()
{
    cout << "\n---TEST INT ARRAY---\n";
    // Checking template array of integers
    DynamicArray<int> a(100);
    // Capacity
    cout << "\nTesting Array::capacity\n";
    cout << "EXPECTED: 100 ";
    cout << "ACTUAL: " << a.capacity() << endl;
    assert(100 == a.capacity());
    a[100] = 0; // test for increasing capacity
    cout << "EXPECTED: 200 ";
    cout << "ACTUAL: " << a.capacity() << endl;
    assert(200 == a.capacity());
    
    // Array constructor
    cout << "\nTesting DynamicArray::DynamicArray\n";
    for (int i = 0; i < a.capacity(); i++)
        assert(a[i] == 0); // default value is 0
    
    // object copy test
    cout << "\nObject copy test\n";
    DynamicArray<int> d = a; // making a copy
    assert(a.capacity() == d.capacity());
    for (int i = 0; i < a.capacity(); i++)
        assert(a[i] == d[i]); // uses the setter version for both a and d
    
    // DynamicArray::operator[] getter
    cout << "\nTesting the DynamicArray::operator[ ] getter\n";
    const DynamicArray<int> b = a;
    for (int i = 0; i < 100; i++)
        assert(a[i] == b[i]);
    
    // DynamicArray::operator[] setter
    cout << "\nTesting the DynamicArray::operator[] setter\n";
    a[60] = 12356;
    a[70] = 7654321;
    cout << "\nTesting Array::operator[] setter\n";
    cout << "EXPECTED: 12356 for a[60]\n";
    cout << "ACTUAL: " << a[60] << endl;
    assert(12356 == a[60]);
    cout << "EXPECTED: 7654321 for a[70]\n";
    cout << "ACTUAL: " << a[70] << endl;
    assert(7654321 == a[70]);
    a[-1000] = 123123;
    cout << "EXPECTED: 123123 for a[-1000]\n";
    cout << "ACTUAL: " << a[-1000] << endl;
    assert(12356 == a[60]);
    assert(7654321 == a[70]);
    assert(123123 == a[-6]); // any out-of-range uses dummy
    assert(123123 != a[99]); // checks upper end of range
    assert(123123 != a[0]); // checks lower end of range
    
    // object assignment test
    cout << "\nObject assignment test\n";
    DynamicArray<int> i(100);
    i = a;
    assert(a.capacity() == i.capacity());
    for (int l = 0; l < a.capacity(); l++)
        assert(a[l] == i[l]);
    
    // const object test
    cout << "\nConst object test\n";
    const DynamicArray<int> c(100); // if this compiles, DynamicArray::DynamicArray main constructor exists
    assert(c.capacity()); // if this compiles, DynamicArray::capacity is a getter
    assert(c[0] == c[0]); // if this compiles, there is an DynamicArray::operator[ ] getter
    assert(c[-1] == c[-1]); // tests the getter's range checking
    
    cout << "\n---TEST DOUBLE ARRAY---\n";
    // Checking template array of integers
    DynamicArray<double> q(100);
    // Capacity
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "EXPECTED: 100 ";
    cout << "ACTUAL: " << q.capacity() << endl;
    assert(100 == q.capacity());
    q[100] = 0.0; // test for increasing capacity
    cout << "EXPECTED: 200 ";
    cout << "ACTUAL: " << q.capacity() << endl;
    assert(200 == q.capacity());
    
    // Array constructor
    cout << "\nTesting DynamicArray::DynamicArray\n";
    for (int i = 0; i < q.capacity(); i++)
        assert(q[i] == 0.0); // default value is 0.0
    
    // object copy test
    cout << "\nObject copy test\n";
    DynamicArray<double> w = q; // making a copy
    assert(q.capacity() == w.capacity());
    for (int i = 0; i < q.capacity(); i++)
        assert(q[i] == w[i]); // uses the setter version for both q and w
    
    // Array::operator[] getter
    cout << "\nTesting the DynamicArray::operator[] getter\n";
    const DynamicArray<double> p = q;
    for (int i = 0; i < 100; i++)
        assert(q[i] == p[i]);
    
    // Array::operator[ ] setter
    cout << "\nTesting the DynamicArray::operator[ ] setter\n";
    q[60] = 12356.10;
    q[70] = 321.2;
    cout << "\nTesting DynamicArray::operator[ ] setter\n";
    cout << "EXPECTED: 12356.1 for q[60]\n";
    cout << "ACTUAL: " << q[60] << endl;
    assert(12356.10 == q[60]);
    cout << "EXPECTED: 321.2 for q[70]\n";
    cout << "ACTUAL: " << q[70] << endl;
    assert(321.20 == q[70]);
    q[-1000] = 123123;
    cout << "EXPECTED: 123123 for q[-1000]\n";
    cout << "ACTUAL: " << q[-1000] << endl;
    assert(12356.10 == q[60]);
    assert(321.20 == q[70]);
    assert(123123 == q[-6]); // any out-of-range uses dummy
    assert(123123 != q[99]); // checks upper end of range
    assert(123123 != q[0]); // checks lower end of range
    
    // object assignment test
    cout << "\nObject assignment test\n";
    DynamicArray<double> o(100);
    o = q;
    assert(q.capacity() == o.capacity());
    for (int i = 0; i < q.capacity(); i++)
        assert(q[i] == o[i]);
    
    // const object test
    cout << "\nConst object test\n";
    const DynamicArray<double> u(100); // if this compiles, DynamicArray::DynamicArray main constructor exists
    assert(u.capacity()); // if this compiles, DynamicArray::capacity is a getter
    assert(u[0] == u[0]); // if this compiles, there is an DynamicArray::operator[ ] getter
    assert(u[-1] == u[-1]); // tests the getter's range checking
    
    cout << "\n---TEST CHARS ARRAY---\n";
    // Checking template array of chars
    DynamicArray<char> e(100);
    // Capacity
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "EXPECTED: 100 ";
    cout << "ACTUAL: " << e.capacity() << endl;
    assert(100 == e.capacity());
    e[100] = '\0'; // test for increasing capacity
    cout << "EXPECTED: 200 ";
    cout << "ACTUAL: " << e.capacity() << endl;
    assert(200 == e.capacity());
    
    // Array constructor
    cout << "\nTesting DynamicArray::DynamicArray\n";
    for (int i = 0; i < e.capacity(); i++)
        assert(e[i] == '\0'); // default value is a null terminator
    
    // object copy test
    cout << "\nObject copy test\n";
    DynamicArray<char> m = e; // making a copy
    assert(e.capacity() == m.capacity());
    for (int i = 0; i < e.capacity(); i++)
        assert(e[i] == m[i]); // uses the setter version for both e and m
    
    // Array::operator[] getter
    cout << "\nTesting the DynamicArray::operator[ ] getter\n";
    const DynamicArray<char> r = e;
    for (int i = 0; i < 100; i++)
        assert(e[i] == r[i]);
    
    // Array::operator[ ] setter
    cout << "\nTesting the DynamicArray::operator[ ] setter\n";
    e[60] = 'g';
    e[70] = 'h';
    cout << "\nTesting DynamicArray::operator[ ] setter\n";
    cout << "EXPECTED: g for e[60]\n";
    cout << "ACTUAL: " << e[60] << endl;
    assert('g' == e[60]);
    cout << "EXPECTED: h for e[70]\n";
    cout << "ACTUAL: " << e[70] << endl;
    assert('h' == e[70]);
    e[-1000] = 'j';
    cout << "EXPECTED: j for e[-1000]\n";
    cout << "ACTUAL: " << e[-1000] << endl;
    assert('g' == e[60]);
    assert('h' == e[70]);
    assert('j' == e[-6]); // any out-of-range uses dummy
    assert('j' != e[99]); // checks upper end of range
    assert('j' != e[0]); // checks lower end of range
    
    // object assignment test
    cout << "\nObject assignment test\n";
    DynamicArray<char> n(100);
    n = e;
    assert(e.capacity() == n.capacity());
    for (int i = 0; i < e.capacity(); i++)
        assert(e[i] == n[i]);
    
    // const object test
    cout << "\nConst object test\n";
    const DynamicArray<char> j(100); // if this compiles, DynamicArray::DynamicArray main constructor exists
    assert(j.capacity()); // if this compiles, DynamicArray::capacity is a getter
    assert(j[0] == j[0]); // if this compiles, there is an DynamicArray::operator[ ] getter
    assert(j[-1] == j[-1]); // tests the getter's range checking
    
    cout << "\n---TEST STRING ARRAY---\n";
    // Checking template array of strings
    
    DynamicArray<string> s(100);
    // Capacity
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "EXPECTED: 100";
    cout << "ACTUAL: " << s.capacity() << endl;
    assert(100 == s.capacity());
    s[100] = "\0"; // test for increasing capacity
    cout << "EXPECTED: 200 ";
    cout << "ACTUAL: " << s.capacity() << endl;
    assert(200 == s.capacity());
    
    // Array constructor
    cout << "\nTesting DynamicArray::DynamicArray\n";
    for (int i = 0; i < s.capacity(); i++)
        assert(s[i] == "\0"); //default value is null terminator
    
    // object copy test
    cout << "\nObject copy test\n";
    DynamicArray<string> v = s; // making a copy
    assert(s.capacity() == v.capacity());
    for (int i = 0; i < s.capacity(); i++)
        assert(s[i] == v[i]); // uses the setter version for both s and v
    
    // Array::operator[ ] getter
    cout << "\nTesting the DynamicArray::operator[ ] getter\n";
    const DynamicArray<string> l = s;
    for (int i = 0; i < 100; i++)
        assert(s[i] == l[i]);
    
    // Array::operator[ ] setter
    cout << "\nTesting the DynamicArray::operator[ ] setter\n";
    s[60] = "go";
    s[70] = "wait";
    cout << "\nTesting DynamicArray::operator[ ] setter\n";
    cout << "EXPECTED: \"go\" for s[60]\n";
    cout << "ACTUAL: " << s[60] << endl;
    assert("go" == s[60]);
    cout << "EXPECTED: \"wait\" for s[70]\n";
    cout << "ACTUAL: " << s[70] << endl;
    assert("wait" == s[70]);
    s[-1000] = "run";
    cout << "EXPECTED: \"run\" for s[-1000]\n";
    cout << "ACTUAL: " << s[-1000] << endl;
    assert("go" == s[60]);
    assert("wait" == s[70]);
    assert("run" == s[-6]); // any out-of-range uses dummy
    assert("run" != s[99]); // checks upper end of range
    assert("run" != s[0]); // checks lower end of range
    
    // object assignment test
    cout << "\nObject assignment test\n";
    DynamicArray<string> x(100);
    x = s;
    assert(s.capacity() == x.capacity());
    for (int i = 0; i < s.capacity(); i++)
        assert(s[i] == x[i]);
    
    // const object test
    cout << "\nConst object test\n";
    const DynamicArray<string> f(100); // if this compiles, DynamicArray::DynamicArray main constructor exists
    assert(f.capacity()); // if this compiles, DynamicArray::capacity is a getter
    assert(f[0] == f[0]); // if this compiles, there is an DynamicArray::operator[ ] getter
    assert(f[-1] == f[-1]); // tests the getter's range checking
    
    return 0;
    
}
