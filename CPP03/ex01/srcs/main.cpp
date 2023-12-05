#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap scavtrap("test");
    ScavTrap scavtrap2( scavtrap );

    scavtrap.attack("Bob");
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(10);
    scavtrap.guardGate();

    return EXIT_SUCCESS;
}