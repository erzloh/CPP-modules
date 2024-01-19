#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    type = "";
	std::cout << "WrongAnimal Default Constructor was called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    type = other.type;
	std::cout << "WrongAnimal Copy Constructor was called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor was called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

std::string	WrongAnimal::getType() const {
	return (type);
}

void WrongAnimal::makeSound() const {
	std::cout << "the WrongAnimal makes a sound." << std::endl;
}
