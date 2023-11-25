#include <iostream>
#include "Zombie.hpp"

int main() {
	int numberOfZombies = 42;

	std::cout << std::endl << "Creating a zombie horde on the heap:" << std::endl;
	Zombie* zombieHorde = Zombie::zombieHorde(numberOfZombies, "Aless");
	for (int i = 0; i < numberOfZombies; i++) {
		zombieHorde[i].announce();
	}
	
	delete [] zombieHorde;
}