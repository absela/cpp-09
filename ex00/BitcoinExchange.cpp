#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &s){
    this->base = s.base;
};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &s){
    this->base = s.base;
    return *this;
};
BitcoinExchange::~BitcoinExchange(){};


void BitcoinExchange::Btc(int ac, char **av)
{
    (void)ac;
    // (void)av;
    std::ifstream base;
    std::ifstream file;
    std::string line;
    std::string str;
    // int i = 0;
    // float value;
    base.open("data.csv");
    if (base.is_open())
    {
        if (base.eof())
        {
            std::cout << "Error: File is empty" << std::endl;
            return;
        }
        while (std::getline(base, line))
        {
            std::string key = line.substr(0, line.find(','));
            std::string value = line.substr(line.find(',') + 1);
            this->base.insert(std::make_pair(key,std::atof(value.c_str())));
        }
    }
    else
    {
        std::cout << "Error: File not found" << std::endl;
        return;
    }
    base.close();
    file.open(av[1]);
    if (!file.good() || file.eof()){    
            std::cout << "Error: File is not good" << std::endl;
            return;}
    std::getline(file, str);
    if (str.empty())
    {
        std::cout << "Error: File is empty" << std::endl;
        return;
    }
    std::string date = str.substr(0,str.find('|') - 1);
    std::string currency = str.substr(str.find('|') + 1);
    std::map<std::string, double>::iterator it = this->base.lower_bound(date);
    if (it == this->base.end())
    {
        std::cout << "Error: Date or currency not found" << std::endl;
        return;
    }
    std::cout << it->second << std::endl;
    // std::cout << currency << std::endl;
    file.close();

}