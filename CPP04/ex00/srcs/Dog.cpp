#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << "Dog Default Constructor was called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog Copy Constructor was called." << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog Destructor was called." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
