#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl {

public:
	Harl();

	void	complain(std::string level) const;

private:
	void		(Harl::*funcPtr[4])() const;
	std::string	level[4];

	void	debug() const;
	void	info() const;
	void	warning() const;
	void	error() const;
};

#endif