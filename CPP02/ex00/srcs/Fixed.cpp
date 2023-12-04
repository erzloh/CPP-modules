#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_fractionalBitsNumber = 8;

Fixed::Fixed() {
	std::cout << "Default Constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = other.getRawBits();
	return (*this);
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}