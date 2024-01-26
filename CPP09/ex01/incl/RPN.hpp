#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
public:
	RPN();
	RPN(const RPN & other);
	~RPN();
	RPN & operator=(const RPN & other);

	void calculate(const std::string & RPNstr);

private:
	std::stack<int> stack;
};

#endif