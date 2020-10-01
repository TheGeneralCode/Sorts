#include "Sort.h"
#include "Sort.cpp"
#include <iostream>
#include <string>
void print(std::vector <int> a) {
    std::cout << "The vector elements are : ";

    for(int i=0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';
    std::cout << std::endl;
}
int main()
{
    std::vector<int> arr; 
    arr = {1,3,59,66,88,12,69,86,83,31,39,22,25,27,24,34,96,14,44,63,76,89,36,20,80,95,67,18,26,55};
    std::cout << "Original Array:" << std::endl;
    print(arr);
    Sort thethings(arr);

    std::vector<int> heap = thethings.heapSort();
    std::cout << "After HeapSort:" << std::endl;
    print(heap);

    thethings.setArray(arr);
    std::vector<int> quick = thethings.quickSort(0, arr.size() - 1);
    std::cout << "After QuickSort:" << std::endl;
    print(quick);

    return 0;
}