#include "RPN.hpp"

Rpn::Rpn() {

}

Rpn::~Rpn(){

}

Rpn::Rpn(const Rpn& other): _stack(other._stack) {

}

Rpn& Rpn::operator=(const Rpn& other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

int	Rpn::_pop(){
	int top = _stack.top();
	_stack.pop();
	return top;
}

bool isOperator(char token) {
	return (token  == '+' || token  == '-' || token  == '*' || token  == '/' );
}

void Rpn::_calculate(char c) {
	int a = _pop();
	int b = _pop();
	if (c == '/' && a == 0) {
		std::cerr << "Error" << std::endl;
		exit(1);
	}
	else if (c == '/') {
		_stack.push(b / a);
	}
	else if (c == '*') {
		_stack.push(b * a);
	}
	else if (c == '+') {
		_stack.push(a + b);
	}
	else if (c == '-') {
		_stack.push(b - a);
	}
}

Rpn::Rpn(const char *expr) {
	std::istringstream iss(expr);
	std::string token;
	while (iss >> token){
		if (token.length() == 1) {
			char c = token[0];
			if (!isOperator(c) && !isdigit(c)) {
				std::cerr << "Error" << std::endl;
				exit(1);
			}
			if (isOperator(c) && _stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				exit(1);
			}
			if (isOperator(c)){
				_calculate(c);
			} else {
				_stack.push(c - '0');
			}
		} else {
			std::cerr << "Error" << std::endl;
			exit(1);
		}
	}
	std::cout << _pop() << std::endl;
}
