//
//  MyRPNCalculator.cpp
//  Data Course
//
//  Created by Inna Soboleva on 8/21/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include <cctype>
#include "Stack.h"

bool isNumber (string, int);
string checkResult(string, string, string);
void errorPopValues(int, Stack<string>&);
bool processInput(string, Stack<string>&, Stack<string>&);


int main()
{
    Stack<string> a, b; // creating two Stacks, one for copy values
    cout << "This is RPN calculator" << endl;
    cout << "You need to enter two numbers and a plus (+), minus (-), multiply (*), or divide (/) operations separeted by space." << endl;
    cout << "EXAMPLE: 1 2 + 4 5 + /" << endl;
    cout << "OR: 1 [enter] 2 [enter] + [enter] 4 [enter] 5 [enter] + [enter] / [enter]" << endl;
    bool noStop = true; // if user wants to Stop
    do{ // loop goes until Q or q is entered
        string input;
        cout << "Enter operation: " << endl;
        getline(cin, input);
        noStop = processInput(input, a, b);
    }while(noStop); // noStop says if Quit was entered

    while(a.peek() != "\0") { // printing the Stack values
        cout << "----------" << endl;
        cout << "STACK contains: " << endl;
        cout << a.peek() << endl;
        a.pop();
    }
    b.clear();
    a.clear();
    
    return 0;
}


bool isNumber (string word, int length) { // checking input, it can contain '.' or digits
    bool isnum = false;
    if (length > 0) {
        isnum = true;
        for(int i = 0; i < length; i++) {
            if (!(isdigit(word[i])) && !(word[i] == '.')) { // if char does not contain '.' or digit
                isnum = false; // return false
                break;
            }
        }
    }
    return isnum;
}

string checkResult(string one, string two, string oper) { // takes operator and two values to compute
    double third = 0;
    double first = atof(one.c_str()); // it's been checked before if it's a digit, otherwise it would not get here
    double second = atof(two.c_str());
    cout << second;
    cout << oper;
    cout << first << " ";
    if (oper == "+")
    {
        third = second + first;
    }
    else if (oper == "-")
        third = second - first;
    else if (oper == "/") {
        third = second / first;
    }
    else if (oper == "*")
        third = second * first;
    else {
        third = 0;
        cout << "wrong operrator, results compromised" << endl;
    } // something went wrong
    string result = to_string(third);
    cout << "COMPUTED: " << result << endl;
    return result;
}

void errorPopValues(int count, Stack<string>& a) {
    for(int i = 0; i < count; i++)
        a.pop();
}

bool processInput(string input, Stack<string>& a, Stack<string>& b) { // processing input from user
    bool noQuit = true; // if Q or q was intered - program stops
    int pushCount = 0; // counting every push and pop for keeping older results in a stack and deleting only new computes which contain some mistake
    for(int i = 0; i < input.length(); i++) // checking input at first for quit, then computing
    {
        if(input[i] == 'Q' || input[i] == 'q')
        {
            noQuit = false;
            break;
        }
    }
    if(noQuit) // can continue
    {
        bool noStop = true; // bool checking if there was wrong input
        int lengthNum = 0; // letgth for substrings
        int indexStart = 0; // starting index for each substring
        int pos = input.find(" "); // finding first space
        while(pos != -1 && noStop) { // while there are spaces in input for making substrings & no mistakes (noStop)
            lengthNum = pos - indexStart; // length for the first string before first space
            string toCheck = input.substr(indexStart, lengthNum); // making substrings from input
            
            if ((lengthNum > 0) && !(isNumber(toCheck, lengthNum))
                && !(toCheck == "+") && !(toCheck == "-") && !(toCheck == "/")
                && !(toCheck == "*")) // checking for the right input
            {
                cout << "Invalid input! Please try again!" << endl;
                noStop = false; // breaking the loop if input is wrong
                errorPopValues(pushCount, a); // deleting computations and stack push-es if there were any
                break;
            }
            if (lengthNum > 0) { // not counting user's extra spacses between numbers
                a.push(toCheck);
                pushCount += 1;
            }
            if (toCheck == "*" || toCheck == "/" || toCheck == "+" || toCheck == "-") // if there is an operation -- compute
            {
                a.pop(); // poping the operator
                pushCount -= 1;
                string one = a.peek();
                if(one == "\0") { // if there is nothing on the Stack
                    noStop = false; // error occured
                    cout << "Invalid input! No argument to compute. Please try again!" << endl;
                    errorPopValues(pushCount, a); // deleting computations and stack push-es
                    break; // quiting the loop
                }
                a.pop(); // poping the first value
                pushCount -= 1;
                string two = a.peek();
                if(two == "\0") { // if there is nothing on the Stack
                    a.push(one); // return first pop-ed value before this computation
                    pushCount += 1;
                    noStop = false;
                    cout << "Invalid input! No second argument. Please try again!" << endl;
                    errorPopValues(pushCount, a); // deleting computations and stack push-es if there were any
                    break;
                }
                a.pop(); // poping the second value
                pushCount -= 1;
                string result = checkResult(one, two, toCheck);
                a.push(result); // adding the result to the Stack
                pushCount += 1;
            }
            
            indexStart = pos + 1; // incrementing for the next substring search
            pos = input.find(" ", indexStart); // next search and while loop break
        }
        if(noStop) { // processing last characters in user input after the last splitting space, behavior similar to the code above with the expetion that here are no loops, using bool values to Stop
            
            lengthNum = input.length() - indexStart;
            string toCheck = input.substr(indexStart, lengthNum);
            
            if ((lengthNum > 0) && !(isNumber(toCheck, lengthNum))
                && !(toCheck == "+") && !(toCheck == "-") && !(toCheck == "/")
                && !(toCheck == "*"))
            {
                cout << "Invalid input, cannot process! Please try again!" << endl;
                noStop = false;
                errorPopValues(pushCount, a);
            }
            
            if ((lengthNum > 0) && (noStop)) {
                a.push(toCheck);
                pushCount += 1;
            }
            if (toCheck == "*" || toCheck == "/" || toCheck == "+" || toCheck == "-")
            {
                a.pop(); // poping the operator
                pushCount -= 1;
                string one = a.peek();
                if(one == "\0") {
                    noStop = false;
                    cout << "Invalid input! Nothing to compute. Please try again!" << endl;
                    errorPopValues(pushCount, a);
                }
                if(noStop)
                {
                    a.pop(); // poping the first value
                    pushCount -= 1;
                    string two = a.peek();
                    if(two == "\0") {
                        a.push(one);
                        pushCount += 1;
                        noStop = false;
                        cout << "Invalid input! Nothing to compute as a second argument. Please try again!" << endl;
                        errorPopValues(pushCount, a);
                    }
                    if(noStop)
                    {
                        a.pop(); // poping the second value
                        pushCount -= 1;
                        string result = checkResult(one, two, toCheck);
                        a.push(result);
                        pushCount += 1;
                    }
                }
            }
        }
    }
    return noQuit;
}
