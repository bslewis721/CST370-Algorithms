/*
Title: BFS.cpp
Abstract: Uses a Breadth-First Search (BFS) algorithm to read input from file
    and display a list of vertices visited for a graph
Author: Brandon Lewis
ID: 1066
Date: 5/20/2018 
*/
#include<iostream>
#include <list>
#include <fstream>
using namespace std;

void BFS(int start, int numVertices, list<int> *adj)
    {
        bool *visited = new bool[numVertices];
        list<int> queue;
     
        // Mark vertices as unvisited
        for(int i = 0; i < numVertices; i++)
        {
            visited[i] = false;
        }
        // Mark the current node as visited and add it to the queue it
        visited[start] = true;
        queue.push_back(start);
     
        list<int>::iterator i;
        int count = 1;
        while(!queue.empty())
        {
            // Remove vertex from queue and print it
            start = queue.front();
            cout << start;
            if (count < numVertices)
            {
                cout << " -> ";
            }
            queue.pop_front();
     
            // Find adjacent vertices of vertex start and if an adjacent has not yet 
            // been visited mark it visited and add it to the queue
            for (i = adj[start].begin(); i != adj[start].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
            count++;
        }
        cout << endl;
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
	
	int numVertices = vertices;
    list<int> *adjacent = new list<int>[numVertices];

    int temp = 0;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graphFile >> temp;
            if (temp == 1)
            {
                adjacent[i].push_back(j);
            }
        }
    }
    
    int start;
    cout << "enter a starting vertex: ";
    cin >> start;
    
    BFS(start, numVertices, adjacent);
 
    return 0;
}
