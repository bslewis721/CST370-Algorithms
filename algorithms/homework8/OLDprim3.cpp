// A C / C++ program for Prim's Minimum Spanning Tree (MST) algorithm. 
// The program is for adjacency matrix representation of the graph
 
// #include <stdio.h>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <vector>

using namespace std;
// Number of vertices in the graph
//#define numVertices 5
 
// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int numVertices)
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < numVertices; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v], min_index = v;
        }
    }
    
   return min_index;
}
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(vector<vector<int> > graph, int numVertices, int firstVertex)
{
    int parent[numVertices]; // Array to store constructed MST
    int key[numVertices];   // Key values used to pick minimum weight edge in cut
    bool mstSet[numVertices];  // To represent set of vertices not yet included in MST
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < numVertices; i++)
    {
        key[i] = INT_MAX, mstSet[i] = false;
    }
    
    // Always include first 1st vertex in MST.
    key[firstVertex -1] = 0;     // Make first vertex 0 so that this vertex is picked as first vertex
    parent[firstVertex - 1] = -1; // First node is always root of MST 
 
    // The MST will have numVertices vertices
    for (int count = 0; count < numVertices-1; count++)
    {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet, numVertices);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < numVertices; v++)
        {
 
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
            {
              parent[v]  = u, key[v] = graph[u][v]; 
            }
        }
    }
 
    // print the constructed MST
    for (int i = 1; i < numVertices; i++)
    {
        cout << "(" << i << ") New edge: " << parent[i] + 1 << "," << i/*FIX THIS VARIABLE!*/ << " - cost " << graph[i][parent[i]] << endl;
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
	
	int numEdges = 0;
	graphFile >> numEdges;
	
	
    vector<vector<int> > graph(numEdges);
	
	int begin, end, weight = 0;
	
	/*for (int i = 0; i < numEdges; i ++)
	{
	    for (int j = 0; j < numEdges; j++)
	    {
	        graph[i][j] = 0;
	    }
	}*/
    graph.resize(vertices);
    for (int i = 0; i < vertices; ++i)
    {
        graph[i].resize(vertices);
    }
    

    for (int k = 0; k < numEdges; k++)
    {
        graphFile >> begin;
        graphFile >> end;
        graphFile >> weight;
        
        for (int i = 1; i <= vertices; i++)
        {
            for (int j = 1; j <= vertices; j++)
            {
                if (begin == i && end == j)
                {
                    cout << "i: " << i << " j: " << j << " begin: " << begin << " end: " << end << " weight: " << weight << endl;
                    graph[i-1][j-1] = weight;
                    cout << "graph[i-1][j-1]: " << graph[i-1][j-1] << endl;
                }
                else if (begin == j && end == i)
                {
                    cout << "i: " << i << " j: " << j << " begin: " << begin << " end: " << end << " weight: " << weight << endl;
                    graph[j-1][i-1] = weight;
                    cout << "graph[i-1][j-1]: " << graph[j-1][i-1] << endl;
                }
                
            }
        }
    }
    
    
    /*for (int i = 0; i < numEdges; i++) {
        for (int j = 0; j < numEdges; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }*/
    int startVert = 1;
    cout << "Enter the first vertex to start: ";
    cin >> startVert;
    primMST(graph, vertices, startVert);
    
    return 0;
}