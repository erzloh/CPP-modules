#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H
#include "Contact.hpp"

#define MAX_CONTACTS 8

class Phonebook {

public:
	Phonebook();
	~Phonebook();
	void start();

private:
	Contact _contactList[8];
	int		_i;
	int		_size;

	int		_readCommand();
	void	_add();
	void	_search();
};

#endif