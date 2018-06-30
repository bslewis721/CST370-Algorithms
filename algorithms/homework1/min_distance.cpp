/*
Title: min_distance.cpp
Abstract: Reads an input file name from a user and displays the closest distance
    between two numbers among the numbers in the file. 
Author: Brandon Lewis
ID: 1066
Date: 4/21/2018
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <map>
using namespace std;


int main()
{
    ifstream numFile;
	string fileLocation;

    // Ask user for file
	cout << "Enter an input file name: ";
	getline(cin, fileLocation);
		numFile.open(fileLocation.c_str());
    
    // If file fails to open keep asking
	while(numFile.fail())
	{
		cout << "The file at location " << fileLocation << " failed to open" << endl;
		cout << "Enter an input file name: ";
		getline(cin, fileLocation);
		numFile.open(fileLocation.c_str());
	}
	
	// Get number of entries and all entries from file
	int entries = 0;
	numFile >> entries;
	int * numbers = new int [entries];
	int k = 0;
	int number;
	while (numFile >> number)
    {
        numbers[k] = number;
        k++;
    }
    numFile.close();
	
	// Sort array
    sort(numbers, numbers + entries);

    // Find smallest distance
    int diff = numeric_limits<int>::max();
    map<int,int> finalDist;
    int newDiff = diff;
    for ( int i = 0; i < entries - 1; i++)
    {
        newDiff = numbers[i+1] - numbers[i];
        if (newDiff == diff)
        {
           finalDist[numbers[i]] = numbers[i+1];
        }
        if (newDiff < diff)
        {
            finalDist.clear();
            diff = newDiff;
            finalDist[numbers[i]] = numbers[i+1];
        }
    }
    
    // Print out results
    cout << "Min distance: " << diff << endl;
    while (!finalDist.empty())
    {
        cout << "Numbers for min distance: " << finalDist.begin()->first <<
            " and " << finalDist.begin()->second << endl;
        finalDist.erase(finalDist.begin());
    }

    delete [] numbers;

    return 0;
}