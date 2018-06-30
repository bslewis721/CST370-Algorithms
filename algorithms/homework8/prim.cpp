/*
Title: prim.cpp
Abstract: Uses Prim's Algorithm to calculate MST
Author: Brandon Lewis
ID: 1066
Date: 6/11/2018 
*/

#include <iostream>
#include <limits.h>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

bool InVisited(map<int, bool> visited, int edge)
{
    if (visited[edge] == 1)
    {
        return true;
    }
    return false;
}

void prims(vector<int> edgeOne, vector<int> edgeTwo, vector<int> weight, int numEdges, int numVertices)
{
    int initialVert = 0;
    cout << "Enter the first vertex to start: ";
    cin >> initialVert;

    map<int,bool> visited;
    for(int i = 1; i <= numVertices; i++)
    {
        visited.insert(make_pair(i,0));
    }
    
    visited[initialVert] = 1;
    
    int count = 0;
    
    for (int k = 0; k < numVertices - 1; k++)
    {
        int min = INT_MAX;
        int firstVert = 0;
        int secondVert = 0;
        
        for (int i = 0; i < visited.size(); i++)
        {
            for (int j = 0; j < numEdges; j++)
            {
                bool checkOne = InVisited(visited, edgeOne[j]);
                bool checkTwo = InVisited(visited, edgeTwo[j]);
                
                // Check if there is edge such that one node is visited but the other is not
                if ((checkOne && !checkTwo) || (checkTwo && !checkOne))
                {
                    if (weight[j] < min)
                    {
                        min = weight[j];
                        firstVert = edgeOne[j];
                        secondVert = edgeTwo[j];
                        
                    }
                }
            }
            
        }
        if (InVisited(visited, secondVert))
        {
            visited[firstVert] = 1;
        }
        else
        {
            visited[secondVert] = 1;
        }
        
        count++;
        cout << "(" << count << ") New edge: " << firstVert << "," << secondVert << " – cost " << min << endl;
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
	
	int numVertices = 0;
	graphFile >> numVertices;

	int numEdges = 0;
	graphFile >> numEdges;
	
	int begin, end, cost = 0;

    vector<int> edgeOne;
    vector<int> edgeTwo;
    vector<int> weight;
    
    for (int i = 0; i < numEdges; i++)
    {
        graphFile >> begin;
        graphFile >> end;
        graphFile >> cost;
        edgeOne.push_back(begin);
        edgeTwo.push_back(end);
        weight.push_back(cost);
    }
    
    prims(edgeOne, edgeTwo, weight, numEdges, numVertices);
    return 0;
}