#include <iostream>
#include <string>

int main() {
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "The address of string:         " << &string << std::endl;
	std::cout << "The address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of string:               " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << string << std::endl;
}