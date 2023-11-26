#include "HumanB.hpp"
#include "iostream"

HumanB::HumanB(std::string name) : _name(name) {
	this->_weapon = NULL;
}

void	HumanB::attack() const {
	if (!this->_weapon)
		std::cout << this->_name << " attacks with their nothing" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}