/*
Title: BFS.cpp
Abstract: Uses a Breadth-First Search (BFS) algorithm to read input from file
    and display a list of vertices visited for a graph
Author: Brandon Lewis
ID: 1066
Date: 5/19/2018 
*/
#include<iostream>
#include <list>
#include <fstream>

using namespace std;
 
// Represents a directed graph using adjacency list representation
class Graph
{
    int numVertices;
    list<int> *adj;   
    
    public:
    
    Graph(int vertices)
    {
        numVertices = vertices;
        adj = new list<int>[numVertices];
    }

    // adds an edge to graph by adding a connected vertice to vertice's list
    void addEdge(int vertice, int connected)
    {
        adj[vertice].push_back(connected);
    }
 
    // prints BFS traversal from a given source s
    void BFS(int s)
    {
        bool *visited = new bool[numVertices];
        list<int> queue;
     
        // Mark vertices as unvisited
        for(int i = 0; i < numVertices; i++)
        {
            visited[i] = false;
        }
        // Mark the current node as visited and add it to the queue it
        visited[s] = true;
        queue.push_back(s);
     
        list<int>::iterator i;
        int count = 1;
        while(!queue.empty())
        {
            // Remove vertex from queue and print it
            s = queue.front();
            cout << s;
            if (count < numVertices)
            {
                cout << "->";
            }
            queue.pop_front();
     
            // Find adjacent vertices of vertex s and if an adjacent has not yet 
            // been visited mark it visited and add it to the queue
            for (i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
            count++;
        }
    }

};

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
	Graph g(vertices);

    //map <int, int[vertices]> edges;
    int temp = 0;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graphFile >> temp;
            //edge[i].push_back(temp);
            if (temp == 1)
            {
                g.addEdge(i, j);
            }
        }
    }
    
    int start;
    cout << "enter a starting vertex: ";
    cin >> start;
    
    g.BFS(start);
 
    return 0;
}
