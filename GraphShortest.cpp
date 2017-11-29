//
//  GraphShortest.cpp
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

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Node>& database)
{
    pair<stack<int>, double> result;
    list<pair<int, double> >::iterator it; // to iterate over neighbors
    queue<int> toDo;
    //for all nodes: set cost to zero, prev=-1, and mark all as not visited
    for(vector<Node>::iterator it = database.begin(); it != database.end(); ++it)
    {
        it->cost = 0;
        it->prev = -1;
        it->isVisited = false;
    }
    // mark start node as "visited" and push it onto the "to-do" list
    database.at(iStart).isVisited = true;
    toDo.push(iStart);
    
    while(!toDo.empty()) // while the "to-do" list is not empty
    {
        int underConsideration = toDo.front(); // peek/pop a node's index from the "to-do" list -- call it the "node under consideration"
        toDo.pop();
        // for each of that node's neighbors
        for(it = database.at(underConsideration).neighbors.begin(); it != database.at(underConsideration).neighbors.end(); ++it)
        {
            if(database.at(it->first).isVisited)
                continue; // if neighbor has been visited, "continue;"
            // set neighbor's cost to 1+cost of node under consideration
            database.at(it->first).cost = 1 + database.at(underConsideration).cost;
            // set neighbor's prev to the index of the node under consideration
            database.at(it->first).prev = underConsideration;
            // push neighbor's index into the "to-do" list
            toDo.push(it->first);
            // mark neighbor as visited
            database.at(it->first).isVisited = true;
            // if neighbor node contains the index of the end city
            if((it->first) == iEnd)
            {
                while (!toDo.empty()) // empty the "to-do" list (so that the while-loop will end)
                {
                    toDo.pop();
                }
                break;
            }
        }
    }
    
    // the route's cost equals the end node's cost
    result.second = database.at(iEnd).cost;
    // build a stack of entries, starting from the end node, back towards the start
    int p = iEnd;
    while(p != -1)
    {
        result.first.push(p);
        p = database.at(p).prev;
    }
    
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
        pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
        for (; !result.first.empty(); result.first.pop())
            cout << '-' << database[result.first.top()].name;
        cout << "\nTotal edges: " << result.second;
        cout << endl;
    }
    cout << "Done!" << endl;
}
