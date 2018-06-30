/*
Title: min_distance.cpp
Abstract: Takes a txt file, uses the first 
Author: Brandon Lewis
ID: 1066
Date: 4/21/2018
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
 	ifstream myfile;
	string fileLocation;

    // Ask user for file
	cout << "Enter an input file name: ";
	getline(cin, fileLocation);
	
	myfile.open(fileLocation.c_str());
    
    // If file fails to open keep asking
	while(myfile.fail())
	{
	//	cout << "The file at location " << fileLocation << " failed to open" << endl;
	//	cout << "Enter an input file name: ";
		getline(cin, fileLocation);
		myfile.open(fileLocation.c_str());
	}

    // Get numbers from file and close file
    int number;
    vector <int> numbers;
    int k = 0;
    while (myfile >> number)
    {
        numbers.push_back(number);
        k++;
    }
    cout << "k:" << k << endl << endl;
    myfile.close();
    
    // Get number of entries, and sort distances from least to greatest
    int entries = numbers[0];
    int distances[entries];
    for (int i = 1; i <= entries; i++)
    {
        distances[i-1] = numbers[i];
        cout << "distances: " << distances[i-1] << endl;
        cout << "numbers: " << numbers[i] << endl;
    }
    sort(distances, distances + entries);
    
    // Initiallize final numbers
    int diff = 999;
    map<int,int> finalDist;
    
    // Find smallest distance
    for ( int i = 0; i < entries - 1; i++)
    {
        if (distances[i+1] - distances[i] == diff)
        {
            cout << endl << "Here is the equals area" << endl;
            cout << "distances[i+1] " << distances[i+1] << endl;
            cout << "distances[i] " << distances[i] << endl;
            cout << "distances[i+1] - distances[i] " << distances[i+1] - distances[i] << endl;
            cout << "diff = " << diff << endl << endl;
            finalDist[distances[i+1]] = distances[i];
        }
        if (distances[i+1] - distances[i] < diff)
        {
            cout << endl << "here is the < area " << endl;
            cout << "distances[i+1] " << distances[i+1] << endl;
            cout << "distances[i] " << distances[i] << endl;
            cout << "distances[i+1] - distances[i] " << distances[i+1] - distances[i] << endl;
            cout << "diff = " << diff << endl << endl;
            finalDist.clear();
            diff = distances[i+1] - distances[i];
            finalDist[distances[i+1]] = distances[i];
        }
    }

    cout << finalDist[8] << endl << endl;

    cout << "Min distance: " << diff << endl;
    cout << "Numbers for min distance: ";
    while (!finalDist.empty())
    {
        cout << finalDist.begin()->first << " and " << finalDist.begin()->second << ", ";
        finalDist.erase(finalDist.begin());
    }
    cout << endl;
	return 0;
}