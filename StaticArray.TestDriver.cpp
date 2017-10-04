//
//  StaticArray.TestDriver.cpp
//  Data Course
//
//  Created by Inna Soboleva on 8/21/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "StaticArray.h"
#include "StaticArray.h" // ifndef test


int main()
{
    cout << "---TEST INT ARRAY---\n";
    // Checking template array of integers
    StaticArray<int, 100> a;
    // Capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 100 ";
    cout << "ACTUAL: " << a.capacity() << endl;
    assert(100 == a.capacity());
    
    // StaticArray constructor
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int i = 0; i < a.capacity(); i++)
        assert(a[i] == 0); // default value is 0
    
    // StaticArray::operator[ ] getter
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray<int, 100> b = a;
    for (int i = 0; i < 100; i++)
        assert(a[i] == b[i]);
    
    // StaticArray::operator[ ] setter
    cout << "\nTesting the StaticArray::operator[ ] setter\n";
    a[60] = 12356;
    a[70] = 7654321;
    cout << "\nTesting StaticArray::operator[ ] setter\n";
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
    assert(123123 == a[100]); // checks upper end of range
    assert(123123 != a[99]); // checks upper end of range
    assert(123123 != a[0]); // checks lower end of range
    
    // const object test
    cout << "\nConst object test\n";
    const StaticArray<int, 100> c; // if this compiles, StaticArray::StaticArray main constructor exists
    assert(c.capacity()); // if this compiles, StaticArray::capacity is a getter
    assert(c[0] == c[0]); // if this compiles, there is an StaticArray::operator[ ] getter
    assert(c[-1] == c[-1]); // tests the getter's range checking
    
    cout << "---TEST DOUBLE ARRAY---\n";
    // Checking template array of integers
    StaticArray<double, 100> n;
    // Capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 100 ";
    cout << "ACTUAL: " << n.capacity() << endl;
    assert(100 == n.capacity());
    
    // StaticArray constructor
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int i = 0; i < n.capacity(); i++)
        assert(n[i] == 0.0); // default value is 0.0
    
    // StaticArray::operator[ ] getter
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray<double, 100> m = n;
    for (int i = 0; i < 100; i++)
        assert(n[i] == m[i]);
    
    // StaticArray::operator[ ] setter
    cout << "\nTesting the StaticArray::operator[ ] setter\n";
    n[60] = 12356.1;
    n[70] = 4321.2;
    cout << "\nTesting StaticArray::operator[ ] setter\n";
    cout << "EXPECTED: 12356.1 for n[60]\n";
    cout << "ACTUAL: " << n[60] << endl;
    assert(12356.1 == n[60]);
    cout << "EXPECTED: 4321.2 for n[70]\n";
    cout << "ACTUAL: " << n[70] << endl;
    assert(4321.2 == n[70]);
    n[-1000] = 123123;
    cout << "EXPECTED: 123123 for n[-1000]\n";
    cout << "ACTUAL: " << n[-1000] << endl;
    assert(12356.1 == n[60]);
    assert(4321.2 == n[70]);
    assert(123123 == n[-6]); // any out-of-range uses dummy
    assert(123123 == n[100]); // checks upper end of range
    assert(123123 != n[99]); // checks upper end of range
    assert(123123 != n[0]); // checks lower end of range
    
    // const object test
    cout << "\nConst object test\n";
    const StaticArray<double, 100> v; // if this compiles, StaticArray::StaticArray main constructor exists
    assert(v.capacity()); // if this compiles, StaticArray::capacity is a getter
    assert(v[0] == v[0]); // if this compiles, there is an StaticArray::operator[ ] getter
    assert(v[-1] == v[-1]); // tests the getter's range checking
    
    cout << "---TEST CHARS ARRAY---\n";
    // Checking template array of chars
    StaticArray<char, 100> e;
    // Capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 100 ";
    cout << "ACTUAL: " << e.capacity() << endl;
    assert(100 == e.capacity());
    
    // StaticArray constructor
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int i = 0; i < e.capacity(); i++)
        assert(e[i] == '\0'); // default value is null terminator
    
    // StaticArray::operator[ ] getter
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray<char, 100> r = e;
    for (int i = 0; i < 100; i++)
        assert(e[i] == r[i]);
    
    // StaticArray::operator[ ] setter
    cout << "\nTesting the StaticArray::operator[ ] setter\n";
    e[60] = 'g';
    e[70] = 'h';
    cout << "\nTesting StaticArray::operator[ ] setter\n";
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
    assert('j' == e[100]); // checks upper end of range
    assert('j' != e[99]); // checks upper end of range
    assert('j' != e[0]); // checks lower end of range
    
    // const object test
    cout << "\nConst object test\n";
    const StaticArray<char, 100> j; // if this compiles, StaticArray::StaticArray main constructor exists
    assert(j.capacity()); // if this compiles, StaticArray::capacity is a getter
    assert(j[0] == j[0]); // if this compiles, there is an StaticArray::operator[ ] getter
    assert(j[-1] == j[-1]); // tests the getter's range checking
    
    cout << "---TEST STRING ARRAY---\n";
    // Checking template array of strings
    
    StaticArray<string, 100> s;
    // Capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 100 ";
    cout << "ACTUAL: " << s.capacity() << endl;
    assert(100 == s.capacity());
    
    // StaticArray constructor
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int i = 0; i < s.capacity(); i++)
        assert(s[i] == "\0"); //default value is null terminator
    
    // StaticArray::operator[ ] getter
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray<string, 100> l = s;
    for (int i = 0; i < 100; i++)
        assert(s[i] == l[i]);
    
    // StaticArray::operator[ ] setter
    cout << "\nTesting the StaticArray::operator[ ] setter\n";
    s[60] = "go";
    s[70] = "wait";
    cout << "\nTesting StaticArray::operator[ ] setter\n";
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
    assert("run" == s[100]); // checks upper end of range
    assert("run" != s[99]); // checks upper end of range
    assert("run" != s[0]); // checks lower end of range
    
    // const object test
    cout << "\nConst object test\n";
    const StaticArray<string, 100> p; // if this compiles, StaticArray::StaticArray main constructor exists
    assert(p.capacity()); // if this compiles, StaticArray::capacity is a getter
    assert(p[0] == p[0]); // if this compiles, there is an StaticArray::operator[ ] getter
    assert(p[-1] == p[-1]); // tests the getter's range checking
    
    return 0;
    
}
