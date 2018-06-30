/*
Title: power.cpp
Abstract: Using a recursive function computes 2^n for some non negative number n
Author: Brandon Lewis
ID: 1066
Date: 5/6/2018 
*/

#include <iostream>
using namespace std;

int power( int n )
{
    if(n == 0)
    {
        return 1;
    }
    // Recursively multiply by 2
    return 2 * power(n-1);
}

int main()
{
    // Get user input   
    cout << "Please enter a number: ";
    int exponent;
    cin >> exponent;
    
    // Give answer of 2^n
    int result = power(exponent);
    cout << "Result: " << result << endl;
    
    return 0;
}
