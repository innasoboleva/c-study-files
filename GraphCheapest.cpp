//
//  GraphCheapest.cpp
//  Data Course
//
//  Created by Inna Soboleva on 11/27/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Node
{
    string name;

    bool isVisited;
    list<pair<int, double> > neighbors;
    int prev;
    double cost;
};

struct Terminus // the path to a node and the cost of that path
{
    int index; // the node's index in the database array
    int prev; // the index of the preceding node in the path
    double cost; // the cost of getting to index's node from prev's node
};
bool operator<(const Terminus& a, const Terminus& b)
{
    return b.cost < a.cost; // reverse logic for lo-to-hi
}

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Node>& database)
{
    pair<stack<int>, double> result;
    list<pair<int, double> >::iterator it; // to iterate over neighbors
    priority_queue<Terminus> toDo;
    
    //for all nodes: set cost to zero, prev=-1, and mark all as not visited
    for(vector<Node>::iterator it = database.begin(); it != database.end(); ++it)
    {
        it->cost = 0;
        it->prev = -1;
        it->isVisited = false;
    }
    // create a Terminus object for the start node with prev=-1, cost=0
    Terminus *p = new Terminus;
    p->cost = 0;
    p->prev = -1;
    p->index = iStart;
    // push the start node's Terminus object onto the priority queue to-do list
    toDo.push(*p);
    // while the priority queue to-do list is not empty
    while(!toDo.empty())
    {
        // peek/pop a Terminus object from the priority queue to-do list
        Terminus *t = new Terminus;
        *t = toDo.top();
        toDo.pop();
        
        if(database.at(t->index).isVisited) // if contained object's been visited, "continue;"
            continue;
        
        database.at(t->index).isVisited = true; // mark contained object as visited
        // set its cost and prev to that of its Terminus
        database.at(t->index).cost = t->cost;
        database.at(t->index).prev = t->prev;
        
        // if Terminus' node is the end node, exit while-loop
        if(t->index == iEnd)
            break;
        // for each of that node's unvisited neighbors
        for(it = database.at(t->index).neighbors.begin(); it != database.at(t->index).neighbors.end(); ++it)
        {
            Terminus *w = new Terminus;
            w->index = it->first;
            w->cost = t->cost + it->second;
            w->prev = t->index;
            toDo.push(*w);
        }
    }
    
    // build a stack of entries, starting from the end node, back towards the start
    int i = iEnd;
    while(i != -1)
    {
        result.first.push(i);
        i = database.at(i).prev;
    }
    
    pair<stack<int>, double> copy = result;
    double resultCost = 0;
    for (; !copy.first.empty(); copy.first.pop()) // iterating over the copy of result to get the cost
    {
        int nodeIndex = copy.first.top();
        resultCost = database[nodeIndex].cost; // in last cycle gets the cost
    }
    result.second = resultCost; // updating cost in result pair
    
    return result;
}

int main()
{
    ifstream fin;
    fin.open("cities.txt");
    if (!fin.good()) throw "I/O error";
    
    // process the input file
    vector<Node> database;
    while (fin.good()) // EOF loop
    {
        string fromCity, toCity, cost;
        
        // read one edge
        getline(fin, fromCity);
        getline(fin, toCity);
        getline(fin, cost);
        fin.ignore(1000, 10); // skip the separator
        
        // add nodes for new cities included in the edge
        int iToNode = -1, iFromNode = -1, i;
        for (i = 0; i < database.size(); i++) // seek "to" city
            if (database[i].name == fromCity)
                break;
        if (i == database.size()) // not in database yet
        {
            // store the node if it is new
            Node fromNode = {fromCity};
            database.push_back(fromNode);
        }
        iFromNode = i;
        
        for (i = 0; i < database.size(); i++) // seek "from" city
            if (database[i].name == toCity)
                break;
        if (i == database.size()) // not in vector yet
        {
            // store the node if it is new
            Node toNode = {toCity};
            database.push_back(toNode);
        }
        iToNode = i;
        
        // store bi-directional edges
        double edgeCost = atof(cost.c_str());
        database[iFromNode].neighbors.push_back(pair<int, double>(iToNode, edgeCost));
        database[iToNode].neighbors.push_back(pair<int, double>(iFromNode, edgeCost));
    }
    fin.close();
    cout << "Input file processed\n\n";
    
    while (true)
    {
        string fromCity, toCity;
        cout << "\nEnter the source city [blank to exit]: ";
        getline(cin, fromCity);
        if (fromCity.length() == 0) break;
        
        // find the from city
        int iFrom;
        for (iFrom = 0; iFrom < database.size(); iFrom++)
            if (database[iFrom].name == fromCity)
                break;
        
        cout << "Enter the destination city [blank to exit]: ";
        getline(cin, toCity);
        if (toCity.length() == 0) break;
        
        // find the destination city
        int iTo;
        for (iTo = 0; iTo < database.size(); iTo++)
            if (database[iTo].name == toCity)
                break;
        
        cout << "Route";
        pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
        for (; !result.first.empty(); result.first.pop())
            cout << '-' << database[result.first.top()].name;
        cout << "\nTotal edges: " << result.second;
        cout << endl;
    }
    cout << "Done!" << endl;
}
