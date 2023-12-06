#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	std::cout << "WrongCat Default Constructor was called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat Copy Constructor was called." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor was called." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}