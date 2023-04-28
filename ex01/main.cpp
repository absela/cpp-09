#include <iostream>
#include <string>
#include <stack>

int main(int ac, char **av)
{
    std::stack<int> rpn;

    if (ac != 2)
    {
        std::cout << "Error: invalid number of arguments" << std::endl;
        return (1);
    }
    std::string str(av[1]);
    int i = 0;
        while (str[i])
        {
            if (str[i] == ' ')
                i++;
            else if (isdigit(str[i]))
            {
                rpn.push(str[i] - '0');
                i++;
            }
            else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                if (rpn.size() < 2)
                {
                    std::cout << "Error" << std::endl;
                    return (1);
                }
                int a = rpn.top();
                rpn.pop();
                int b = rpn.top();
                rpn.pop();
                switch (str[i])
                {
                case '+':
                    rpn.push(a + b);
                    break;
                case '-':
                    rpn.push(a - b);
                    break;
                case '*':
                    rpn.push(a * b);
                    break;
                case '/':
                {
                    if (b == 0)
                    {
                        std::cout << "Error" << std::endl;
                        return (1);
                    }
                    rpn.push(a / b);
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
                return (1);
            }
        }
    if (rpn.size() != 1)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    std::cout << rpn.top() << std::endl;
    return (0);
}