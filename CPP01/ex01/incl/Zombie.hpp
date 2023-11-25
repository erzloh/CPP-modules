#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie {

public:
	~Zombie();

	void	announce() const;

	static Zombie*	zombieHorde(int N, std::string name);

private:
	std::string	_name;
};

#endif