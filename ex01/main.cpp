#include <iostream>
#include <string>
#include <stack>
#include <sstream>


// C++ program to print the elements of a
// stack from bottom to top
using namespace std;
 
// Recursive function to print stack elements
// from bottom to top without changing
// their order
void PrintStack(stack<int> s)
{
    stack<int> temp;
    while (s.empty() == false)
    {
        temp.push(s.top());
        s.pop();
    }  
 
    while (temp.empty() == false)
    {
        int t = temp.top();
        cout << t << " ";
        temp.pop();
 
        // To restore contents of
        // the original stack.
        s.push(t); 
    }
}

// int main(int ac, char **av)
// {
//     if (ac != 2)
//     {
//         std::cout << "Error: invalid number of arguments" << std::endl;
//         return (1);
//     }
//     std::stack<int> rp;
//     std::string str;
//     // std::stringstream ss(av[1]);
//     int i = 0;
//     while (av[1][i])
//     {
        
//         if (!isdigit(av[1][i]) && av[1][i] != '*' && av[1][i] != '+' && av[1][i] != '/' && av[1][i] != '-' && av[1][i] != ' ')
//         {
//             std::cout << "Error" << "\n";
//             return 0;
//         }
//         else if(av[1][i] == ' ')
//                     i++;
//         else{
//             str += av[1][i];
//             i++;
//         }
//     }
//     if (isdigit(str.c_str()[str.length()-1]))
//     {
//         std::cout << "Error" << "\n";
//         return 0;
//     }
//     // std::cout << str << "\n";
//     i = 0;
//         try
//         {
//     while (av[1][i])
//     {
//             if (isdigit(av[1][i]))
//             {
//                 rp.push(av[1][i] - '0');
//                 i++;
//             }
//             else if (isdigit(av[1][i]) == ' ')
//                 i++;
//             i++;
//         }
        
//     PrintStack(rp);
//     }
//         catch(const std::exception& e)
//         {
//             std::cerr << e.what() << '\n';
//         }
    
//     std::cout << rp.top() << "\n";
// }

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
        PrintStack(rpn);
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