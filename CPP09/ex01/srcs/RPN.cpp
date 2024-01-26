#include "RPN.hpp"
#include <cctype>
#include <iostream>

// STEPS
// iterate through the string:
// 		if there is a white space -> skip
//		if there is a character that is not a digit or an operator -> error
//		if there is a digit -> push it to the stack
//		if there is an operator -> retrieve the two last elements of the stack and push the result of their calculation
//			if there is no more element in the stack -> error
// 		print the result
//		
//		if the number of operator is not number of digit - 1 -> error


// ------------------------- Canonical Form Functions -------------------------
RPN::RPN() {}

RPN::RPN(const RPN & other) {
	*this = other;
}

RPN::~RPN() {}

RPN & RPN::operator=(const RPN & other) {
	if (this != &other) {
		stack = other.stack;
	}
	return *this;
}

// ------------------------- Utility Functions -------------------------
static bool isOperator(const char & c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	return false;
}

static void doStackOperation(std::stack<int> & stack, const char & c) {
	if (stack.size() < 2) {
		std::cout << "Error: not enough elements in the stack to perform a calculation." << std::endl;
		exit(-1);
	}

	int n1 = stack.top();
	stack.pop();
	int n2 = stack.top();
	stack.pop();

	if (c == '+') {
		stack.push(n2 + n1);
		#ifdef DEBUG
			std::cout << n2 << " + " << n1 << " = " << n2 + n1 << std::endl;
		#endif
	}
	else if (c == '-') {
		stack.push(n2 - n1);
		#ifdef DEBUG
			std::cout << n2 << " - " << n1 << " = " << n2 - n1 << std::endl;
		#endif
	}
	else if (c == '*') {
		stack.push(n2 * n1);
		#ifdef DEBUG
			std::cout << n2 << " * " << n1 << " = " << n2 * n1 << std::endl;
		#endif
	}
	else if (c == '/') {
		if (n1 == 0) {
			std::cout << "Error: Division by zero is impossible." << std::endl;
			exit(-1);
		}
		stack.push(n2 / n1);
		#ifdef DEBUG
			std::cout << n2 << " / " << n1 << " = " << n2 / n1 << std::endl;
		#endif
	}
}

// ------------------------- Member Functions -------------------------
void RPN::calculate(const std::string &RPNstr) {
	// Iterate through the string
	for (size_t i = 0; i < RPNstr.size(); i++) {
		// Skip to the next char if there is a whitespace
		if (isspace(RPNstr[i])) {
			continue;
		}
		// Check if the char is something else than a digit or an operator
		if (!isdigit(RPNstr[i]) && !isOperator(RPNstr[i])) {
			std::cout << "Error" << std::endl;
			exit(-1);
		}
		// If char is a digit, push it to the stack
		if (isdigit(RPNstr[i])) {
			stack.push(RPNstr[i] - '0');
			#ifdef DEBUG
				std::cout << "PUSH " << RPNstr[i] << std::endl;
			#endif
		} 
		// If char is an operator, retrieve the two last elements of the stack and push the result of their calculation
		else if (isOperator(RPNstr[i])) {
			doStackOperation(stack, RPNstr[i]);
		}
	}
	// Print the result
	std::cout << stack.top() << std::endl;
}