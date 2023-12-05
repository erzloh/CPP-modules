#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {

private:
	int					_fixedPointValue;
	static const int	_fractionalBitsNumber;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &other);
	~Fixed();

	// Operator Overload
	Fixed	&operator=(const Fixed &other);

	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	// Member Functions
	int		getRawBits() const;
	void	setRawBits(const int raw);

	float	toFloat() const;
	int		toInt() const;

	static Fixed		&min(Fixed &n1, Fixed &n2);
	static const Fixed	&min(const Fixed &n1, const Fixed &n2);
	static Fixed		&max(Fixed &n1, Fixed &n2);
	static const Fixed	&max(const Fixed &n1, const Fixed &n2);
};

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs);

#endif