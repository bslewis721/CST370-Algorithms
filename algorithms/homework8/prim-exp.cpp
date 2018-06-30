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

using namespace std;

bool InVisited(vector<int> visited, int edge)
{
    for (int i =0; i < visited.size(); i++)
    {
        if (visited[i] == edge)
        {
            return true;
        }
    }
    return false;
}

void prims(vector<int> edgeOne, vector<int> edgeTwo, vector<int> weight, int numEdges, int numVertices)
{
    int initialVert = 0;
    cout << "Enter the first vertex to start: ";
    cin >> initialVert;
    vector<int> visited;
    visited.push_back(initialVert);
    
    int count = 0;
    
    while (visited.size() != numVertices)
    {
        int min = INT_MAX;
        int firstVert = 0;
        int secondVert = 0;
        
        // for every node already visited
        for (int i = 0; i < visited.size(); i++)
        {
            for (int k = 0; k < visited.size(); k++)
            {
                int j = visited[k] - 1;
                bool checkOne = InVisited(visited, edgeOne[j]);
                bool checkTwo = InVisited(visited, edgeTwo[j]);
                // Check if there is edge such that one node is visited but the other is not
                if ((checkOne && !checkTwo) || (checkTwo && !checkOne))
                {
                    if (weight[j] < min) // if this min smaller then set min
                    {
                        min = weight[j];
                        firstVert = edgeOne[j];
                        secondVert = edgeTwo[j];
                        
                    }
                }
            }
            
        }
        if (InVisited(visited,secondVert))
        {
            visited.push_back(firstVert);
        }
        else
        {
            visited.push_back(secondVert);
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