
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << name << " has been created" << std::endl;
}
	
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "Copy constructor was called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << _name << " has been killed" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	} else {
		std::cout << "ClapTrap cannot attack. Not enough hit points or energy points." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	} else {
		std::cout << "ClapTrap is already destroyed. Cannot take damage." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
		_hitPoints += amount;
		_energyPoints -= 1;
	} else {
		std::cout << "ClapTrap cannot be repaired. Not enough hit points or energy points." << std::endl;
	}
}