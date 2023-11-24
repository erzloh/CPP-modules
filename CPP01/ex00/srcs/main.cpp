#include <iostream>
#include "Zombie.hpp"

int main() {
	std::cout << std::endl << "Creating a Zombie on the main stack:" << std::endl;
	Zombie zombie1("Eric");
	zombie1.announce();

	std::cout << std::endl << "Creating a Zombie on the heap:" << std::endl;
	Zombie *newZombie = Zombie::newZombie("Aless");
	newZombie->announce();

	std::cout << std::endl << "Creating a random Zombie on a function stack:" << std::endl;
	Zombie::randomChump("Nathan");
	
	delete newZombie;
}