#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &s);
        BitcoinExchange &operator=(const BitcoinExchange &s);
        ~BitcoinExchange();


        
        void Btc(int ac, char **av);


    private:
        std::map<std::string, double> _base;
};