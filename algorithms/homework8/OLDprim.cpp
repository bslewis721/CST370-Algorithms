/*
Title: prim.cpp
Abstract: Uses Prim's Algorithm to calculate MST
Author: Brandon Lewis
ID: 1066
Date: 6/8/2018 
*/


#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <limits.h>
// #include <algorithm>
#include <map>
// #include <vector>
using namespace std;


void Prim(int start, int numEdges, int numVertices, multimap <int, list<int> > edgeList)
{
    list<int> visited;
    visited.push_back(start);
    
    /*
    // 2. test
    typedef multimap< int, list<int> >::iterator edgeIt;
    list<int> tempList;
        
    for (int i = 0; i < numEdges; i++) // perhaps while visited is not full ie length = numVertices
    {
        // cycle through find all edges from visited, and look for the least expensive to a non visited
        pair<edgeIt, edgeIt> result = edgeList.equal_range(start); // 2. replace start with iteration through visited
        tempList.clear(); // 2.
        for (edgeIt it = result.first; it != result.second; it++)
        {
            tempList.insert(tempList.begin(), it->second.begin(), tempList.end()); // 2.
		    //cout << tempList[0] << endl;
        }
    }
    */
    int count = 1;
    while(count != numVertices)
    {
        for (int i = 0; i < numEdges; i++)
        {
            int minVal = INT_MAX;
            int edgeOne = 0;
            int edgeTwo = 0;
            for (int j = 0; j < visited.size(); j++)
            {
                if (edgeList[i] == visited[j] && visited.find(edgeList[i][0]) != visited.end()) //first visited and second not visited
                {
                    //check the min and set min
                    edgeOne = edgeList[i];
                }
            }
            cout min info
        }
    }
    
}

int main()
{
    ifstream graphFile;
	string fileLocation;

    cout << "Please enter a file name: ";
	getline(cin, fileLocation);
		graphFile.open(fileLocation.c_str());

    // If file fails to open keep asking
	while(graphFile.fail())
	{
		cout << "The file at location " << fileLocation << " failed to open" << endl;
		cout << "Enter an input file name: ";
		getline(cin, fileLocation);
		graphFile.open(fileLocation.c_str());
	}
	
	int vertices = 0;
	graphFile >> vertices;
	
	// int numVertices = vertices;
	
	int numEdges = 0;
	graphFile >> numEdges;
	
	
	int begin, end, weight = 0;
    //list<int> *edges = new list<int>[numEdges];
    // 1. Worked to get values set up: vector< vector<int> > edgeList(numEdges);
    multimap <int, list<int> > edgeList;
    list<int> temp;
    
    cout << "vertices: " << vertices << " numEdges: " << numEdges << endl;
    // int temp = 0;
    for (int i = 1; i <= numEdges; i++)
    {
        temp.clear();    
        graphFile >> begin;
        graphFile >> end;
        graphFile >> weight;
        temp.push_back(end);
        temp.push_back(weight);
        //cout << "begin: " << begin << " end: " << end << " weight: " << weight << endl;
        
        /*
        1. Worked to get values set up:
        edgeList[begin].push_back(end);
        edgeList[begin].push_back(weight);
        cout << edgeList[begin][0] << edgeList[begin][1] << endl;
        */
        
        edgeList.insert(pair <int, list<int> > (begin, temp));
    }
    
    int start;
    cout << "Enter the first vertex to start: ";
    cin >> start;
    
    Prim(start, numEdges, vertices, edgeList);
 
    return 0;
}