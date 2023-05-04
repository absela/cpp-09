#pragma once


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h> 

class PmergeMe{
    private:
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &s);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &s);

        void mergeSort(std::vector<int> &vec);
        void mergeSort(std::deque<int> &dq);
};
