#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractionalBitsNumber = 8;

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBitsNumber) {
	std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBitsNumber))) {
	std::cout << "Float Constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
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
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(const int raw) {
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat() const {
	return (static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBitsNumber));
}

int		Fixed::toInt() const {
	return (this->_fixedPointValue >> _fractionalBitsNumber);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs) {
	o << rhs.toFloat();
	return (o);
}