#include "Phonebook.class.hpp"
#include <iostream>

int main() {
	Phonebook myPhonebook(42, 'a');
	myPhonebook.hello();
	std::cout << myPhonebook.number;
}