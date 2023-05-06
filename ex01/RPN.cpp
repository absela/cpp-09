#include "RPN.hpp"

RPN::RPN(){};
RPN::RPN(const RPN &s){
    this->_rpn = s._rpn;
};
RPN &RPN::operator=(const RPN &s){
    this->_rpn = s._rpn;
    return *this;
};
RPN::~RPN(){};

void RPN::Rpn(int ac, char **av)
{
if (ac != 2)
    {
        std::cout << "Error: invalid number of arguments" << std::endl;
    }
    std::string str(av[1]);
    int i = 0;
        while (str[i])
        {
            if (str[i] == ' ')
                i++;
            else if (isdigit(str[i]))
            {
                _rpn.push(str[i] - '0');
                i++;
            }
            else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                if (_rpn.size() < 2)
                {
                    std::cout << "Error" << std::endl;
                    exit(0);
                }
                int a = _rpn.top();
                _rpn.pop();
                int b = _rpn.top();
                _rpn.pop();
                switch (str[i])
                {
                case '+':
                    _rpn.push(a + b);
                    break;
                case '-':
                    _rpn.push(a - b);
                    break;
                case '*':
                    _rpn.push(a * b);
                    break;
                case '/':
                {
                    if (b == 0)
                    {
                        std::cout << "Error" << std::endl;
                        exit(0);
                    }
                    _rpn.push(a / b);
                    break;
                }
                default:
                    break;
                }
                i++;
            }
            else
            {
                std::cout << "Error" << std::endl;
                exit(0);
            }
        }
    if (_rpn.size() != 1)
    {
        std::cout << "Error" << std::endl;
        exit(0);
    }
    std::cout << _rpn.top() << std::endl;
}