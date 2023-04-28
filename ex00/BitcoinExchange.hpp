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
        void parsing_date(int dd, int mm, int yy);
        void Btc(int ac, char **av);


    private:
        std::map<std::string, double> base;
};