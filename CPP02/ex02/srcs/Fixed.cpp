#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractionalBitsNumber = 8;


// ------------------------ Constructors and Destructor ------------------------
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


// ------------------------ Operator Overload ------------------------
Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = other.getRawBits();
	return (*this);
}

// ------------------------ Comparison Operators ------------------------
bool	Fixed::operator>(const Fixed &other) const {
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const {
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const {
	return (this->getRawBits() != other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->getRawBits() != other.getRawBits());
}

// ------------------------ Arithemtic Operators ------------------------
Fixed	Fixed::operator+(const Fixed &other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}

// ------------------------ Increment / Decrement Operators ------------------------
Fixed	&Fixed::operator++() {
	this->_fixedPointValue++;
	return (*this);
}

Fixed	&Fixed::operator--() {
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	this->_fixedPointValue++;
	return (temp);
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	this->_fixedPointValue--;
	return (temp);
}


std::ostream	&operator<<(std::ostream &o, const Fixed &rhs) {
	o << rhs.toFloat();
	return (o);
}

// ------------------------ Member Functions ------------------------
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

Fixed	&Fixed::min(Fixed &n1, Fixed &n2) {
	if (n1 < n2) {
		return (n1);
	}
	else {
		return (n2);
	}
}

const Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2) {
	if (n1 < n2) {
		return (n1);
	}
	else {
		return (n2);
	}
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2) {
	if (n1 > n2) {
		return (n1);
	}
	else {
		return (n2);
	}
}

const Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2) {
	if (n1 > n2) {
		return (n1);
	}
	else {
		return (n2);
	}
}