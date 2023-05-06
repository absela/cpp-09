#pragma once

#include <iostream>
#include <string>
#include <stack>

class RPN{
    public:
        RPN();
        RPN(const RPN &s);
        RPN &operator=(const RPN &s);
        ~RPN();

        void Rpn(int ac, char **av);

    private:
        std::stack<int> _rpn;
};