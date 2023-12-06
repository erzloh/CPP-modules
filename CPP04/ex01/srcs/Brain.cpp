#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain Default Constructor was called." << std::endl;
	for (size_t i = 0; i < 100; i++) {
		ideas[i] = "";
	}
}

Brain::Brain(const Brain& other) {
	*this = other;
	std::cout << "Brain Copy Constructor was called." << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain Destructor was called." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (size_t i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
    }
    return *this;
}
