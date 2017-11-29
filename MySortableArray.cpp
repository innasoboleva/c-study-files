//
//  MySortableArray.cpp
//  Data Course
//
//  Created by Inna Soboleva on 11/19/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cstdlib>

#include "SortableArray.h"


int main()
{
    bool quit = false;
    SortableArray<double> numbers(100); // defining origin array
    SortableArray<bool> check(100); // defining bool array for used indexes check

    while (quit != true) // included bool statement so no invalid zeros from invalid input would get into array
    {
        string buf, buf2;
        cout << "Input an index and a value [Q to quit]: ";
        cin >> buf >> buf2;
        if (buf =="Q" || buf == "q" || buf2 =="Q" || buf2 == "q") // Quit option
            break;
        int position = atoi(buf.c_str()); // If no valid conversion could be performed, a zero value is returned
        double val = atof(buf2.c_str()); // If no valid conversion could be performed, a zero value is returned
        
        if (quit == false) // if user wants to quit, do not store zero values in array
        {
            numbers[position] = val; // placing the value into the origin array
            check[position] = true; // second array stores the position of the stored value in origin array
        }

    }

    int numvalues = 0, numSort = 0;
    for(int i = 0; i < check.capacity(); i++) // checks how many values stored in array
    {
        if(check[i] == true)
            numvalues += 1;
    }
    cout << "\nYou stored this many values: " << numvalues;
    cout << "\nThe index-value pairs are: \n\n";
    for(int i = 0; i < check.capacity(); i++)
    {
        if(check[i] == true)
            cout << "\t" << setw(2) << i << " => " << numbers[i] << " ";
    }

    cout << endl << endl;
    
    cout << "How many values to include in the sorting (values shoud exist up to the \"fill-line\")? ";
    cin >> numSort;
    numbers.sort(numSort); // all indexes are inUse till the fill-line, no need to rearrange checking array (all values are going to return true)
    
    cout << "\nThe index-value pairs are: \n\n";
    for(int i = 0; i < check.capacity(); i++)
    {
        if(check[i] == true)
            cout << "\t" << setw(2) << i << " => " << numbers[i] << " ";
    }
    
    cout << endl << endl;

    while (true) // a while-true-if-break loop
    {
        string buf;
        cout << "Input an index for me to look up [Q to quit]: ";
        cin >> buf;
        if (buf =="Q" || buf == "q")
            break;
        int position = atoi(buf.c_str()); // If no valid conversion could be performed, a zero value is returned
        

        if(check[position] == true)
            cout << "Found it -- the value stored at " << position << " is " << numbers[position] << endl;
        else
            cout << "I didn't find it" << endl;
    }
    
    return 0;
    
}
