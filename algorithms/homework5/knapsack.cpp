/*
Title: knapsack.cpp
Abstract: Using input from the user generates a list of sets and their values
Author: Brandon Lewis
ID: 1066
Date: 5/19/2018 
*/

#include <sstream>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void knapsack(int set[], int numItems, int vals[], int wgts[], int maxWgt)
{
    // Find the number of sets
    int numSets = pow(2, numItems);

    // Initialize the final solution
    int bestWgt = maxWgt;
    int bestVal = 0; 
    string bestSet = "";

    // Cycle through all possible sets
    for (int k = 0; k < numSets; k++)
    {
        int sumVal = 0;
        int sumWgt = 0;
        string tempSet = "";

        cout << "{";
        for (int j = 0; j < numItems; j++)
        {
            int temp = (1<<j);

            if (k & (1<<j))
            {
                int tempSetLen = tempSet.length();
                if (tempSetLen > 0 && tempSetLen < numItems)
                {
                    cout << ",";
                }
                cout << set[j];
                
                sumVal = sumVal + vals[j];
                sumWgt = sumWgt + wgts[j];

                ostringstream oss;
                oss << set[j];
                tempSet += oss.str();
                if (sumVal > bestVal && sumWgt <= maxWgt)
                {
                    bestSet = tempSet;
                    bestVal = sumVal;
                    bestWgt = sumWgt;
                }
            }
            if (k == 0 && j == 0)
            {
                cout << "empty";
            }
        }
        if (sumWgt <= maxWgt)
        {
            cout << "} => capacity: " << sumWgt << " , value: $" << sumVal << endl;
        }
        else
        {
            cout << "} => capacity: " << sumWgt << " - over capacity, value: N/A\n";
        }
    }
    cout << "\nSolution: {" << bestSet << "} => capacity: " << bestWgt << ", value: $" << bestVal << endl;
}

int main()
{
     
    int numItems;
    int maxWgt;
    char temp;
    
    // Get user input
    cout << "Enter a number of items: ";
	cin >> numItems;
	cout << "Enter knapsack capacity: ";
	cin >> maxWgt;
    int largeSet[numItems];
    int wgts[numItems];
    int vals[numItems];

    int tempWgt = 0;
    int tempVal = 0;
    cout << "Enter weights and values of " << numItems << " items:\n"; 
    for (int i = 0; i < numItems; i++)
    {
        cout << "    Item " << i+1 << ": ";
        cin >> tempWgt;
        cin >> tempVal;
        largeSet[i] = i+1;
        wgts[i] = tempWgt;
        vals[i] = tempVal;
    }
    cout << endl;
    knapsack(largeSet, numItems, vals, wgts, maxWgt);

    return 0;
}