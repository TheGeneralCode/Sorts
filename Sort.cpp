#include "Sort.h"
#include <iostream>
#include <string>
#include <cmath>
Sort::Sort(std::vector<int> arr)
{
    array = arr;
}
Sort::~Sort()
{
    
}

// Public Methods
std::vector<int> Sort::getArray()
{
    return array;
}
void Sort::setArray(std::vector<int> arr)
{
    array = arr;
}
std::vector<int> Sort::insertion()
{
    for(int i = 1; i < array.size(); i++)
    {
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    return array;
}


std::vector<int> Sort::heapSort()
{
    buildMaxHeap();
    for (int i = array.size() - 1; i >= 1; i--)
    {
        int temp = array[0];//Exchange first element with i'th element
        array[0] = array[i];
        array[i] = temp;
        
        maxHeapify(0);
    }
    return array;
}

std::vector<int> Sort::quickSort(int begin, int end)
{
    int mid;
    if(begin < end)
    {
        mid = partition(begin, end); 
        quickSort(begin, mid - 1); //recursevly calls for each half of array
        quickSort(mid + 1, end);
    }
    return array;
}

// Private Methods
int Sort::partition(int begin, int end)
{
    int temp;
    int x = array[end];
    int i = begin - 1;
    for(int j = begin; j <= end-1; j++)
    {
        if(array[j] < x) // if current is smaller than last element
        {
            i++; 
            temp = array[i]; // Exchange first element with last element
            array[i] = array[j];
            array[j] = temp;
        }
        
    }
    temp = array[i + 1]; // Exchange first element with last element
    array[i + 1] = array[end];
    array[end] = temp;

    return i + 1;
}


void Sort::buildMaxHeap(){
    for (int i = array.size() / 2; i >= 0; i--)
    {
        maxHeapify(i);
    }
}
void Sort::maxHeapify(int i)
{
    int largest = i;
    int l = (2 * (i + 1)) - 1;// Left and right shifted for 0 base
    int r =  2 * (i + 1);

    if(l >= array.size()) // To insure that no actions are peformed when out of bounds
        l = -1;
    if (r >= array.size())
        r = -1;

    if(l != -1 && (array[l] > array[i]))
        {
            largest = l;
        }
    else if(l != -1)
        largest = i;
    
    if(r  != -1 && (array[r] > array[largest]))
        largest = r;
    if(largest != i)
    {
        int temp = array[i]; // Exchange parent with largest child
        array[i] = array[largest];
        array[largest] = temp;
        maxHeapify(largest);
    }
}