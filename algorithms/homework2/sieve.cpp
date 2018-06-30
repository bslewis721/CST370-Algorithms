/*sieve.cpp
Abstract: 
Author: Brandon Lewis
ID: 1066
Date: 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

cout << "Please enter your target number: ";
int targetNumber;
cin >> targetNumber;

// assign all numbers to array
int * allNumbers = new int [targetNumber + 1];
for (int i = 2; i < targetNumber; i++)
{
    allNumbers[i] = i;
}

// Check for prime numbers
int multiples = 0;
for (int k = 2; k < sqrt(targetNumber); k++)
{
    if (allNumbers[k] != 0)
    {
        multiples = k * k;
    }
    while (multiples <= targetNumber)
    {
        allNumbers[multiples] = 0;
        multiples = multiples + k;
    }
}

// Put prime numbers into our final numbers array
int * finalNumbers = new int [targetNumber];
int i = 0;
for (int j = 2; j < targetNumber; j++)
{
    if (allNumbers[j] != 0)
    {
        finalNumbers[i] = allNumbers[j];
        i++;
    }
}

// Print out final numbers
cout << "Prime Numbers: ";
for(int l = 0; l  < i; l++)
{
    cout << finalNumbers[l];
    if (l != i-1)
    {
        cout << ", ";
    }
}
cout << endl;

delete [] finalNumbers;
delete [] allNumbers;
return 0;
}