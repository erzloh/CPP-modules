#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

private:
	int					_integer;
	static const int	_fractionalBitsNumber;

public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();

	Fixed	&operator=(const Fixed &other);

	int		getRawBits() const;
	void	setRawBits(const int raw);
};

#endif