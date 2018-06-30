/*
Title: performance.cpp
Abstract: displays performance of 3 sorting algorithms
Author: Brandon Lewis
ID: 1066
Date: 5/28/2018 
*/

#include <iostream>
#include <algorithm>
#include <ctime>
#include <time.h>
#include <fstream>
using namespace std;


void generateInput(int* list, int size);
void timeOutput(string sorting, clock_t elapsed, time_t start, time_t end);
void ascending(int* list, int size);
void descending(int* list, int size);
void random(int* list, int size);
void selectionSort(int* list, int size);
void insertionSort(int* list, int size);
int hoarePartition(int* list, int low, int high);
void quickSort(int* list, int low, int high);

int main()
{
    int size;
    cout << "Enter input size: ";
    cin >> size;
    
    int* list = new int[size];
    generateInput(list, size);
    
    int* selectionList = new int[size];
    int* insertionList = new int[size];
    int* quickList = new int[size];
    
    // Writes the list to a txt file as well as copies the primary list
    // into three different lists for the sorting algorithms 
    int count = 1;
    ofstream outputFile("input.txt");
    for (int i = 0; i < size; i++)
    {
        outputFile << list[i];
        if (count % 10 == 0)
        {
            outputFile << "\n";
        }
        else
        {
            outputFile << ", ";
        }
        selectionList[i] = list[i];
        insertionList[i] = list[i];
        quickList[i] = list[i];
        count++;
    }
    
    selectionSort(selectionList, size);
    insertionSort(insertionList, size);

    // Times the quicksort algorithm
    time_t start = time(0);
    clock_t startClock = clock();
    
    quickSort(quickList, 0, size - 1);
    
    time_t end = time(0);
    clock_t elapsedTime = clock() - startClock;
    timeOutput("Quicksort", elapsedTime, start, end);
    
    delete list, selectionList, insertionList, quickList;
    return 0;
}

// Asks user which order to fill the list and calls appropriate function
void generateInput(int* list, int size)
{
    int order = 0;
    cout << "========== Select Order of Input Numbers ==========\n    "
        "1. Ascending Order\n    2. Descending Order\n    3. Random Order\n"
        "Choose order: ";
    cin >> order;
    
    string orders[3] = {"Ascending", "Descending", "Random"};
    cout << "============================================================\n"
        "Generate input data in " << orders[order-1] << " order . . .\n"
        "Done.\n"
        "============================================================\n\n";
    
    switch(order)
    {
        case 1:
            ascending(list, size);
            break;
        case 2:
            descending(list, size);
            break;
        case 3:
            random(list, size);
            break;
        default:
            cout <<"You did not enter a proper value for ordering\n";
    }
}

// Outputs the timing of the sorting algorithm
void timeOutput(string sorting, clock_t elapsed, time_t start, time_t end)
{
    cout << "============================================================\n"
        << sorting << " performance\n"
        "Starting time: " << ctime(&start) <<
        "\nEnding time: " << ctime(&end) <<
        "\nElapsed time: " << (((double)elapsed)/CLOCKS_PER_SEC) << " seconds"
        "\n============================================================\n\n";
}

// Populates the list with variables in an ascending order
void ascending(int* list, int size)
{
    for (int i = 0; i < size; i++)
    {
        list[i] = i;
    }
}

// Populates the list with variables in a descending order
void descending(int* list, int size)
{
    int j = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        list[j] = i;
        j++;
    }
}

// Populates the list with variables in a random order by first adding them
// sequentially then shuffling the unique variables
void random(int* list, int size)
{
    ascending(list, size);
    for (int i = 0; i < size; i++)
    {
        int r = rand() % size;
        int temp = list[i];
        list[i] = list[r];
        list[r] = temp;
    }
}

// Performs selection sorting on the input list and times the
// results of the algorithm
void selectionSort(int* list, int size)
{
    time_t start = time(0);
    clock_t startClock = clock();
    
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (list[j] < list[min])
            {
                min = j;
            }
        }
        int temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
    
    time_t end = time(0);
    clock_t elapsedTime = clock() - startClock;
    timeOutput("Selection sort", elapsedTime, start, end);
}

// Performs insertion sort on the algorithm and time the
// results of the algorithm
void insertionSort(int* list, int size)
{
    time_t start = time(0);
    clock_t startClock = clock();

    for (int i = 1; i < size; i++)
    {
        int v = list[i];
        int j = i - 1;
        while(j >= 0 && list[j] > v)
        {
            list[j + 1] = list [j];
            j--;
        }
        list[j + 1] = v;
    }
    
    time_t end = time(0);
    clock_t elapsedTime = clock() - startClock;
    timeOutput("Insertion sort", elapsedTime, start, end);
}

// Performs the partitioning of the passed subsection of the list to find
// appropriate values to swap about the pivot
int hoarePartition(int* list, int low, int high)
{
    int pivot = list[low];
    int i = low;
    int j = high + 1;
  
    while (i < j)
    {
        do
        {
            i++;
        } while (list[i] < pivot);

        do
        {
            j--;
        } while (list[j] > pivot);

        swap(list[i], list[j]);
    }
    swap(list[i], list[j]);
    swap(list[low], list[j]);
    return j;
}

// Recursivly calls quicksort on partitioned subsections of the list untill
// array is sorted
void quickSort(int* list, int low, int high)
{
    if (low < high)
    {
        int s = hoarePartition(list, low, high);
        quickSort(list, low, s - 1);
        quickSort(list, s + 1, high);
    }
}