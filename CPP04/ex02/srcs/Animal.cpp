#include <iostream>
#include "Animal.hpp"

Animal::Animal() {
    type = "";
	std::cout << "Animal Default Constructor was called." << std::endl;
}

Animal::Animal(const Animal& other) {
    type = other.type;
	std::cout << "Animal Copy Constructor was called." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor was called." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

std::string	Animal::getType() const {
	return (type);
}

// void Animal::makeSound() const {
// 	std::cout << "the Animal makes a sound." << std::endl;
// }
