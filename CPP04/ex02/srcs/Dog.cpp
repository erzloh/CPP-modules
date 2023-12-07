#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Dog Default Constructor was called." << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog Copy Constructor was called." << std::endl;
	brain = new Brain(*other.brain);
}

Dog::~Dog() {
	std::cout << "Dog Destructor was called." << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

Brain	*Dog::getBrain() const {
	return brain;
}