#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_fractionalBitsNumber = 8;

Fixed::Fixed() {
	std::cout << "Default Constructor called" << std::endl;
	this->_integer = 0;
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_integer = other.getRawBits();
	return (*this);
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_integer);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_integer = raw;
}