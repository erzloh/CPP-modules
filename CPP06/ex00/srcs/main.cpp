#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	return 0;
}
