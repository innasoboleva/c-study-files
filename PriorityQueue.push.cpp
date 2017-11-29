//  PriorityQueue.push.cpp
//  Data Course
//
//  Created by Inna Soboleva on 10/22/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#include <iostream>
using namespace std;

#include <cstring> // for strtok and strcpy
#include <cassert> // for assert
#include <cmath> // for log and pow
#include <cstdlib> // for srand and rand
#include <ctime> // for clock(), clock_t, time, and CLOCKS_PER_SEC

#include "PriorityQueue.h"

void check(const PriorityQueue<int>&, int);

int main()
{
    int n = 1000;
    int fill = n + (n*2) + (n*2*2) + (n*2*2*2) + (2*n);
    PriorityQueue<int> queue(fill); // 15000 values are going to be pushed in a queue
    for(int i = 0 ; i < n; i++) // priority queue to be tested has n values in it
    {
        int v = rand() % 100 + 1;
        queue.push(v);
    }
    assert(queue.size() == n); // confirmations that the priority queue to be tested has n values in it
    cout << "Actual queue size is " << queue.size() << ". Expected: " << n << endl;
    
    srand(time(0)); rand(); // seed the random number generator
    
    string bigOh = "O(log n)";
    
    cout.setf(ios::fixed);
    cout.precision(4);
    double elapsedSecondsNorm = 0;
    double expectedSeconds = 0;
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {
        clock_t startTime = clock();
        
        for(int i = 0 ; i < n; i++)
        {
            int v = rand() % 100 + 1;
            queue.push(v);
        }
        
        clock_t endTime = clock();
        
        double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        double factor = pow(2.0, double(cycle));
        if (cycle == 0)
            elapsedSecondsNorm = elapsedSeconds;
        else if (bigOh == "O(n)")
            expectedSeconds = factor * elapsedSecondsNorm;
        else if (bigOh == "O(n log n)")
            expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
        else if (bigOh == "O(n squared)")
            expectedSeconds = factor * factor * elapsedSecondsNorm;
        else if (bigOh == "O(log n)")
            expectedSeconds = log(double(n)) / log(n / factor) * elapsedSecondsNorm;
        // reporting block
        cout << elapsedSeconds;
        if (cycle == 0) cout << " (expected " << bigOh << ')';
        else cout << " (expected " << expectedSeconds << ')';
        cout << " for n=" << n << endl;
    }
    
    check(queue, 100); // confirmations that the priority queue is arranged in hi-to-lo order after the timing test ends
    
} //main

void check(const PriorityQueue<int> &a, int num)
{
    PriorityQueue<int> b = a;
    for (int i=0; i < num; i++) // no need to check all values
    {
        int temp = b.top();
        b.pop();
        assert(temp >= b.top());
        
    }
}
