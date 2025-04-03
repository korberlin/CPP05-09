#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

class Rpn {
    private:
        std::stack<int> _stack;
        Rpn();
    public:
        Rpn(const char *expr);
        ~Rpn();
        Rpn(const Rpn &other);
        Rpn& operator=(const Rpn &other);
		int	_pop();
		void _calculate(char c);
};

#endif
