#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include "Contact.hpp"

class Phonebook {

public:
	Phonebook();
	~Phonebook();
	void start();

private:
	Contact _contactList[8];
	int		_i;
	int		_size;

	void	_add();
	void	_search();
	void	_exit();

	int			_readCommand();
	std::string	_getProcessedStr(std::string str);
	bool		_isNumber(const std::string& str);
	bool		_isValidIndex(const std::string& str);
};

#endif