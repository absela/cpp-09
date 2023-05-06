#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &s)
{
    *this = s;
}

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(const PmergeMe &s)
{
    (void)s;
    return *this;
}

void insertSort(std::vector<int> &vec)
{
    int i;
    int j;
    int tmp;
    for (i = 1; i < (int)vec.size(); i++)
    {
        tmp = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] > tmp)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = tmp;
    }
}

void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vec)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < (int)left.size() && j < (int)right.size())
    {
        if (left[i] < right[j])
        {
            vec[k] = left[i];
            i++;
        }
        else
        {
            vec[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < (int)left.size())
    {
        vec[k] = left[i];
        i++;
        k++;
    }
    while (j < (int)right.size())
    {
        vec[k] = right[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSort(std::vector<int> &vec)
{
    std::vector<int> left;
    std::vector<int> right;
    int middle;

    if (vec.size() <= 1)
        return;
    if (vec.size() <= 20)
    {
        insertSort(vec);
        return;
    }
    middle = vec.size() / 2;
    for (int i = 0; i < middle; i++)
        left.push_back(vec[i]);
    for (int i = middle; i < (int)vec.size(); i++)
        right.push_back(vec[i]);
    mergeSort(left);
    mergeSort(right);
    merge(left, right, vec);
}

void insertSort(std::deque<int> &dq)
{
    int i;
    int j;
    int tmp;

    for (i = 1; i < (int)dq.size(); i++)
    {
        tmp = dq[i];
        j = i - 1;
        while (j >= 0 && dq[j] > tmp)
        {
            dq[j + 1] = dq[j];
            j--;
        }
        dq[j + 1] = tmp;
    }
}

void merge(std::deque<int> &left, std::deque<int> &right, std::deque<int> &dq)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < (int)left.size() && j < (int)right.size())
    {
        if (left[i] < right[j])
        {
            dq[k] = left[i];
            i++;
        }
        else
        {
            dq[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < (int)left.size())
    {
        dq[k] = left[i];
        i++;
        k++;
    }
    while (j < (int)right.size())
    {
        dq[k] = right[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSort(std::deque<int> &dq)
{
    std::deque<int> left;
    std::deque<int> right;
    int middle;

    if (dq.size() <= 1)
        return;
    if (dq.size() <= 20)
    {
        insertSort(dq);
        return;
    }
    middle = dq.size() / 2;
    for (int i = 0; i < middle; i++)
        left.push_back(dq[i]);
    for (int i = middle; i < (int)dq.size(); i++)
        right.push_back(dq[i]);
    mergeSort(left);
    mergeSort(right);
    merge(left, right, dq);
}