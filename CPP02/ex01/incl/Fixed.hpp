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

	Fixed	&operator=(const Fixed &other);

	int		getRawBits() const;
	void	setRawBits(const int raw);

	float	toFloat() const;
	int		toInt() const;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs);

#endif