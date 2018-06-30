/*
Title: coin_row.cpp
Abstract: Solves the coin row program given a users input
Author: Brandon Lewis
ID: 1066
Date: 6/8/2018 
*/


#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

void coinRow(int numCoins, int coins[])
{
    vector< vector<int> > coinSets(numCoins + 1);
    int maxValues[numCoins + 1];
    int temp = 0;

    maxValues[0] = 0;
    maxValues[1] = coins[0];
    coinSets[0].push_back(0);
    coinSets[1].push_back(coins[0]);
    
    for (int i = 2; i <= numCoins; i++)
    {
        temp = coins[i-1] + maxValues[i-2];
        if (temp > maxValues[i-1])
        {
            maxValues[i] = temp;
            coinSets[i].push_back(coins[i-1]);
            if(coinSets[i-2][0] != 0)
            {
                coinSets[i].insert(coinSets[i].end(), coinSets[i-2].begin(), coinSets[i-2].end());
            }
        }
        else
        {
            maxValues[i] = maxValues[i-1];
            coinSets[i].insert(coinSets[i].end(), coinSets[i-1].begin(), coinSets[i-1].end());
        }
    }
    
    int counter = 0;
    int size = coinSets[numCoins].size();
    cout << "Best set: ";
    for (int i = 0; i < size; i++)
    {
        cout << coinSets[numCoins][i]; 
        if (counter < size - 1)
        {
            cout << ", ";
        }
        counter++;
    }
    cout << endl << "Max value: " << maxValues[numCoins] << endl;
}


int main() {
    
    int numCoins = 0;
    cout << "Number of coin(s): ";
    cin >> numCoins;
    cout << "Value(s): ";
    
    int coins[numCoins];
    int tempCoin = 0;
    for (int i = 0; i < numCoins; i++)
    {
        cin >> tempCoin;
        coins[i] = tempCoin;
    }
    
    coinRow(numCoins, coins);
   
    return 0;
}