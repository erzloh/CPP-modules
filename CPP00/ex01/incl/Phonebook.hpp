#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include "Contact.hpp"

class Phonebook {

public:
	Phonebook();
	~Phonebook();
	void start();

private:
	Contact contactList[8];
	int		i;

	void	add();
	void	search();
	void	exit();

	int			readCommand();
	std::string	getProcessedStr(std::string str);
	bool		isNumber(const std::string& str);
	bool		isValidIndex(const std::string& str);
};

#endif