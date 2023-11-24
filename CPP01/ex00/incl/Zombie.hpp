#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie {

public:
	Zombie(const std::string &name);
	~Zombie();

	void	announce() const;

	static Zombie*	newZombie(const std::string &name);
	static void		randomChump(const std::string &name);

private:
	std::string	_name;
};

#endif