#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap("Test");

    clapTrap.attack("Target");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);

    return 0;
}