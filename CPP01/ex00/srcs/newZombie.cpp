#include "Zombie.hpp"

Zombie*	Zombie::newZombie(const std::string &name) {
	return (new Zombie(name));
}