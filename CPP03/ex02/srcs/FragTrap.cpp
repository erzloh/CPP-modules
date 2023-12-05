#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
    std::cout << "FragTrap attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys() {
    if (_energyPoints <= 0) {
        std::cout << "FragTrap " << _name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " high fives everybody!" << std::endl;
    _energyPoints -= 1;
}