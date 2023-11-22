#include "Phonebook.class.hpp"
#include <iostream>

Phonebook::Phonebook(int n, char l) : number(n), letter(l) {
	std::cout << "Hello from the constructor!" << std::endl;

}

Phonebook::~Phonebook() {
	std::cout << "Hello from the deconstructor!" << std::endl;
}

void Phonebook::hello() const {
	std::cout << "Hello!" << std::endl;
}