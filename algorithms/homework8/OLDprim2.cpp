
#include <iostream>
#include <list>
#include <limits.h>
#include <stdio.h>

using namespace std;



int minKey(int key[], bool mstSet[], int numVertices)
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < numVertices; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 /*
// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int n, int graph[n][n])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < n; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
 */
// Function to construct and print MST for a graph represented using adjacency
// matrix representation

void primMST(int graph[][], int numVertices)
{
     int parent[numVertices]; // Array to store constructed MST
     int key[numVertices];   // Key values used to pick minimum weight edge in cut
     bool mstSet[numVertices];  // To represent set of vertices not yet included in MST
 
     // Initialize all keys as INFINITE
     for (int i = 0; i < numVertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have numVertices vertices
     for (int count = 0; count < numVertices-1; count++)
     {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet. numVertices);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < numVertices; v++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     // print the constructed MST
     //printMST(parent, numVertices, graph);
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
	
	int graph[vertices][vertices];
	
	int begin, end, weight = 0;
    // list <int> starts;
    // list <int> ends;
    // list <int> weights;
    
    cout << "vertices: " << vertices << " numEdges: " << numEdges << endl;
    // int temp = 0;
    
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
                    graph[i-1][j-1] = weight;
                }
            }
        }
    }
    
    primMST(graph. vertices);
    
    return 0;
}

