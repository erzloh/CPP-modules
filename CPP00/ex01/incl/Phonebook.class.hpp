#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include "Contact.class.hpp"

class Phonebook {

public:
	int number;
	char letter;

	Phonebook(int n, char s);
	~Phonebook();
	void hello() const;

private:
	Contact contactList[8];
};

#endif