#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error :: bad input" << std::endl;
        return (1);
    }
    PmergeMe Pem;
    std::vector<int> vec;
    std::deque<int> dq;
    int i = 0;
    while (++i < ac)
    {
        std::string str(av[i]);
        for (int i = 0; i < (int)str.size();i++)
        {
            if (!std::isdigit(str[i]))
            {
                std::cout << "Error :: bad input" << std::endl;
                return (1);
            }
        }
    int num;
    try
    {
        num = std::stoi(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        vec.push_back(num);
        dq.push_back(num);
    }
    clock_t T;
    T = clock();
    std::cout << "befor :vector: ";
    for (int i = 0; i < (int)vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
        std::cout << "befor :deque: ";
    for (int i = 0; i < (int)dq.size(); i++)
        std::cout << dq[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    Pem.mergeSort(vec);
    T = clock() - T;
    double time = ((double)T) / CLOCKS_PER_SEC;
    std::cout << "time for vector: " << time << std::endl;
    Pem.mergeSort(dq);
    T = clock() - T;
    double timee = ((double)T) / CLOCKS_PER_SEC;
    std::cout << "time for deque: " << timee << std::endl;
    std::cout << "after vector: ";
    for (int i = 0; i < (int)vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    std::cout << "deque: ";
    for (int i = 0; i < (int)dq.size(); i++)
        std::cout << dq[i] << " ";
    std::cout << std::endl;
    return (0);
}