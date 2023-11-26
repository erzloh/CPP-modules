#include "Harl.hpp"

Harl::Harl() {
	this->funcPtr[0] = &Harl::debug;
	this->funcPtr[1] = &Harl::info;
	this->funcPtr[2] = &Harl::warning;
	this->funcPtr[3] = &Harl::error;

	this->level[0] = "debug";
	this->level[1] = "info";
	this->level[2] = "warning";
	this->level[3] = "error";
}

void    Harl::debug() const {
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info() const {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning() const {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}

void    Harl::error() const {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) const {
	int	i = 0;

	while (level != this->level[i] && i < 4) {
		i++;
	}
	if (i < 4) {
		(this->*funcPtr[i])();
	}
	else {
		std::cout << "Enter a valid complain level." << std::endl;
	}
}