#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &s){
    this->_base = s._base;
};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &s){
    this->_base = s._base;
    return *this;
};
BitcoinExchange::~BitcoinExchange(){};

int check_date(std::string str)
{
    int dash = 0;

    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] == '-')
            dash++;
    }
    if (dash != 2)
        return 0;
    return 1;
}

int check_pipe(std::string str)
{
    int pipe = 0;

    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] == '|')
            pipe++;
    }
    if (pipe != 1)
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
    int y = atoi(year.c_str());
    int m = atoi(month.c_str());
    int d = atoi(day.c_str());
    if (y < 2009)
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

std::string valide_value(std::string str)
{
    std::string value = str.substr(str.find('|') + 2);
    if (value.size() < 1)
    {
        std::cout << "Error: bad input" + str.substr(0,10) << std::endl;
        return "";
    }
    int pp;

    pp = 0;
    for (int i = 0; i < (int)value.size(); i++)
    {
        if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-')
        {
            std::cout << "Error: bad input =>" + str.substr(0,10) << std::endl;
            return "";
        }
        if (isdigit(value[i]))
        {
            continue;
        }
        else if (value[i] == '.' && pp == 0)
        {
            pp = 1;
        }
        else if (value[i] == '.' && pp == 1)
        {
            std::cout << "double . " << std::endl;
            return "";
        }
    }
    float n;
    try
    {
        n = std::atof(value.c_str());
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error : Value" << '\n';
    }
    
    if (n > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return "";
    }
    if (n <= 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return "";
    }
    return value;
}

std::string valide_format(std::string str)
{
    if (str.size() < 14 || !check_pipe(str) || (str.substr(13,1) == "-" && str.substr(14, -1) == "0"))
    {
        std::cout << "Error: bad inputs =>" + str.substr(0,10) << std::endl;
        return "";
    }
    std::string date = str.substr(0,str.find('|') + 1);
    if (date.size() != 12 || !format(date))
    {
        std::cout << "Error: bad input =>" + str.substr(0,10) << std::endl;
        return "";
    }
    return date;
}

void BitcoinExchange::Btc(int ac, char **av)
{
    (void)ac;
    std::ifstream base;
    std::ifstream file;
    std::string line;
    std::string str;
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
            std::string value_b = line.substr(line.find(',') + 1);
            this->_base.insert(std::make_pair(key,std::atof(value_b.c_str())));
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
            std::string value = valide_value(str);
            std::string date_v = date.substr(0, 10);
            if (date.empty() || value.empty())
                continue;
            std::map<std::string, double>::iterator it = this->_base.find(date_v);
            if (it == this->_base.end())
            {
                it = this->_base.lower_bound(date_v);
                if (it == this->_base.begin())
                {
                    std::cout << "Error: No data" << std::endl;
                    return;
                }
                double low_b = (--it)->second;
                double input = atof(value.c_str());
                std::cout << date + " => " << input << " = " << input * low_b << std::endl;
            }
            else
            {
                double input = atof(value.c_str());
                std::cout << date + " => " << input << " = " << input * it->second << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Error: File not found" << std::endl;
        return;
    }
    file.close();
}