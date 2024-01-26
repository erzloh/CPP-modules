#include "RPN.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cout << "Error: the program must take one argument." << std::endl;
		return -1;
	}

	RPN rpn;
	rpn.calculate(argv[1]);

	return 0;
}
