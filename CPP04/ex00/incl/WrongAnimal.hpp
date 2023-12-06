#ifndef WrongANIMAL_HPP
#define WrongANIMAL_HPP
#include <string>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal();
	WrongAnimal&	operator=(const WrongAnimal& other);

	std::string	getType() const;
	void		makeSound() const;

protected:
	std::string	type;
};

#endif
