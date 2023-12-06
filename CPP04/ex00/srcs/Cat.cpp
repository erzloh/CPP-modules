#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << "Cat Default Constructor was called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat Copy Constructor was called." << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor was called." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}