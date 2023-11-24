#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string &name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << this->_name << " has been destroyed." << std::endl;
}

void	Zombie::announce() const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}