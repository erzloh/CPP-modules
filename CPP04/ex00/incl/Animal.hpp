#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal {
public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();
	Animal&	operator=(const Animal& other);

	std::string		getType() const;
	virtual void	makeSound() const;

protected:
	std::string	type;
};

#endif
