#include "Zombie.hpp"
#include <iostream>

void	Zombie::randomChump(std::string name) {
	Zombie chump(name);
	chump.announce();
	std::cout << std::endl;
}