/*
Title: adj_matrix.cpp
Abstract: Converts a directed graph stored in an input file into an adjacency matrix format.
Author: Brandon Lewis
ID: 1066
Date: 4/29/2018
*/

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
    ifstream graphFile;
	string fileLocation;

    // Ask user for file
	cout << "Enter an input file name: ";
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
	
	// Grab the vertices and edges values
	int vertices = 0;
	graphFile >> vertices;
	int edges = 0;
	graphFile >> edges;

	// Grab the edge information
	multimap<int,int> edgeInfo;
	int edgeKey;
	int edgeValue;
	int k = 0;
	while (k < edges)
    {
    	graphFile >> edgeKey;
    	graphFile >> edgeValue;
        edgeInfo.insert(pair <int,int> (edgeKey, edgeValue));
        k++;
    }
    graphFile.close();
    
    // Iterate through the multimap and output the matrix
	multimap<int,int>::iterator itLow, itUp;
	for (int i = 0; i < vertices; i++)
	{
		itLow = edgeInfo.lower_bound(i);
		itUp = edgeInfo.upper_bound(i);
		cout << "[ ";
		for (int j = 0; j < vertices; j++)
		{
			if (itLow->first == i && itLow->second == j && itLow != itUp)
			{
				cout << "1";
				itLow++;
			}
			else
			{
			cout << "0";
			}
			if (j != vertices - 1)
			{
				cout << ", ";
			}
		}
		cout << "]\n";
	}
	return 0;
}