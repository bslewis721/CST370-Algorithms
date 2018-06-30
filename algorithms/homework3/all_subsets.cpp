/*
Title: all_subsets.cpp
Abstract: using input from the user prints out all subsets of the characters entered.
Author: Brandon Lewis
ID: 1066
Date: 5/6/2018 
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void printSets(string set, int numChars)
{
    // Find the number of sets
    int numSets = pow(2, numChars);

    // Cycle through all possible sets
    for (int k = 0; k < numSets; k++)
    {
        cout << "{";
        for (int j = 0; j < numChars; j++)
        {
            int temp = (1<<j);
            // If jth bit is set then print jth element
            if (k & (1<<j))
            {
                cout << set[j];
            }
            if (k == 0 && j == 0)
            {
                cout << "empty";
            }
        }
        cout << "}\n";
    }
}

int main()
{
    string originalSet = "";
    int numChars;
    char temp;
    
    // Get user input
    cout << "Please enter a number: ";
    cin >> numChars;
    cout << "Please enter " << numChars << " characters: ";

    // Add charactert to our string
    for (int i = 0; i < numChars; i++)
    {
        cin >> temp;
        originalSet.push_back(temp);
    }
    printSets(originalSet, numChars);

    return 0;
}
