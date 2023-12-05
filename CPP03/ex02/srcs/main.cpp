#include "FragTrap.hpp"

int main( void )
{
    FragTrap fragtrap("test");
    FragTrap fragtrap2(fragtrap);

    fragtrap.attack("Bob");
    fragtrap.takeDamage(10);
    fragtrap.beRepaired(10);
    fragtrap.highFivesGuys();

    return EXIT_SUCCESS;
}