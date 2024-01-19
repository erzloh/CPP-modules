#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap1("ClapTrap1");
	ClapTrap clapTrap2("ClapTrap2");

	clapTrap1.attack("ClapTrap2");
	clapTrap1.beRepaired(5);

	clapTrap2.takeDamage(10);
	clapTrap2.attack("ClapTrap1");
	clapTrap2.beRepaired(5);

	clapTrap1.attack("ClapTrap2");
	clapTrap1.attack("ClapTrap2");
	clapTrap1.attack("ClapTrap2");
	clapTrap1.attack("ClapTrap2");
	clapTrap1.attack("ClapTrap2");
	clapTrap1.attack("ClapTrap2");
	clapTrap1.attack("ClapTrap2");
	clapTrap1.attack("ClapTrap2");
	clapTrap1.attack("ClapTrap2");

    return 0;
}