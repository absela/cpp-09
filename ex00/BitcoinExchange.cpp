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

int check_date(std::string str)
{
    int dash = 0;
    int pipe = 0;

    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] == '-')
            dash++;
        if (str[i] == '|')
            pipe++;
    }
    if (dash != 2 || pipe != 1)
        return 0;
    return 1;
}

int format(std::string str)
{
    std::string year = str.substr(0,4);
    std::string month = str.substr(5,2);
    std::string day = str.substr(8,2);
    if (year.size() != 4 || month.size() != 2 || day.size() != 2)
        return 0;
    if (year[0] != '2' || year[1] != '0')
        return 0;
    int y = atoi(year.c_str());
    int m = atoi(month.c_str());
    int d = atoi(day.c_str());
    if (y < 2009 || y > 2022)
        return 0;
    if (m < 1 || m > 12)
        return 0;
    if (d < 1 || d > 31)
        return 0;
    if (m == 2)
        {
            if (y % 4 == 0 && d > 29)
                return 0;
            if (y % 4 != 0 && d > 28)
                return 0;
        }
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return 0;
    return 1;
}

std::string valide_format(std::string str)
{
    if (str.size() < 14)
    {
        std::cout << "Error: Invalid file format-" << std::endl;
        return "";
    }
    std::string date = str.substr(0,str.find('|') + 1);
    std::string currency = str.substr(str.find('|') + 1);
    if (date.size() != 12 || !format(date))
    {
        std::cout << "Error: Invalid file format" << std::endl;
        return "";
    }
    std::cout << currency << std::endl;
    return date;
}

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
    if (file.is_open())
    {
        if (file.eof())
        {
            std::cout << "Error: File is empty" << std::endl;
            return;
        }
        std::getline(file,str);
        if (str != "date | value")
        {
            std::cout << "Error: Invalid file format" << std::endl;
            return;
        }
        while (std::getline(file, str))
        {
            if (str.empty())
                continue;
            std::string date = valide_format(str);
        }
    }
    else
    {
        std::cout << "Error: File not found" << std::endl;
        return;
    }
    // std::cout << currency << std::endl;
    file.close();

}