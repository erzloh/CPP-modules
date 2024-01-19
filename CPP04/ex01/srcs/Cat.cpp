#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	std::cout << "Cat Default Constructor was called." << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat Copy Constructor was called." << std::endl;
	brain = new Brain(*other.getBrain());
}

Cat::~Cat() {
	std::cout << "Cat Destructor was called." << std::endl;
	delete brain;
}

Cat & Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.getBrain();
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

Brain	*Cat::getBrain() const {
	return brain;
}