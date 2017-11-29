//
//  BFS.cpp
//  Data Course
//
//  Created by Inna Soboleva on 11/27/17.
//  Copyright © 2017 Inna Soboleva. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Node
{
    string name;
    
    bool isVisited;
    list<int> neighbors;
};

queue<int> doBreadthFirstSearch(int iOriginNode, vector<Node>& database)
{
    queue<int> searchOrder, toDo; // return this queue of indices
    // initialize each node in database: set to "not visited"
    for(vector<Node>::iterator it = database.begin(); it != database.end(); ++it)
    {
        it->isVisited = false;
    }
    // mark starting node as "visited"
    database.at(iOriginNode).isVisited = true;
    
    // push start node's index onto the result queue and "to-do" list
    searchOrder.push(iOriginNode);
    toDo.push(iOriginNode);
    // while the "to-do" list is not empty
    while(!toDo.empty())
    {
        int ind = toDo.front();
        toDo.pop(); // peek/pop a node's index from the "to-do" list
        // for each of that node's neighbors
        for(list<int>::iterator it = database.at(ind).neighbors.begin(); it != database.at(ind).neighbors.end(); ++it)
        {
            if(!(database.at(*it).isVisited)) // if neighbor has not yet been visited
            {
                database.at(*it).isVisited = true; // mark neighbor as visited
                // push neighbor's index onto the result queue and "to-do" list
                searchOrder.push(*it);
                toDo.push(*it);
            }
        }
    }
    
    return searchOrder;
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
        string fromCity, toCity;
        
        // read one edge
        getline(fin, fromCity);
        getline(fin, toCity);
        fin.ignore(1000, 10); // skip the line with distance
        fin.ignore(1000, 10); // skip the separator
        
        // add vertices for new cities included in the edge
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
        database[iFromNode].neighbors.push_back(iToNode);
        database[iToNode].neighbors.push_back(iFromNode);
    }
    fin.close();
    cout << "Input file processed\n\n";
    
    while (true)
    {
        // get the start city for the search
        string startCity;
        cout << "\nEnter the start city [blank to exit]: ";
        getline(cin, startCity);
        if (startCity.length() == 0) break;
        
        // find the start city
        int i;
        for (i = 0; i < database.size(); i++)
            if (database[i].name == startCity)
                break;
        
        // BFS result by copy-pop
        cout << "BFS";
        for (queue<int> q = doBreadthFirstSearch(i, database); !q.empty(); q.pop())
            cout  << '-'<< database[q.front()].name;
        cout << endl;
    }
    cout << "Done!" << endl;
}
