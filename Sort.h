#ifndef SORT_H_
#define SORT_H_
#include <vector>
/*
 * Sort.h
 *
 *  Created on: Sept 23, 2020
 *      Author: Cameron
 */

class Sort
{
    public:
        Sort(std::vector<int> arr);
        ~Sort();
        std::vector<int> getArray();
        void setArray(std::vector<int> arr);
        std::vector<int> Sort::insertion();
        std::vector<int> heapSort();
        std::vector<int> quickSort(int begin, int end);
    private:
        std::vector<int> array;
        int partition(int begin, int end);
        void buildMaxHeap();
        void maxHeapify(int i);
};
#endif