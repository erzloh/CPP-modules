#include "Phonebook.hpp"
#include "colors.hpp"
#include "printText.hpp"
#include <iostream>

Phonebook::Phonebook() : _i(0), _size(0) {}

Phonebook::~Phonebook() {}

void Phonebook::start() {
	printGreetings();
	std::cout << BLUE << "Hello and welcome to my awesome phonebook!" << RESET << std::endl;
	while (1) {
		if (_readCommand() == 1)
			break;
	}
}

int Phonebook::_readCommand() {
	std::string command;

	std::cout << "Type the command " << ORANGE << "ADD" << RESET << ", " << ORANGE << "SEARCH" << RESET << ", or " << ORANGE << "EXIT" << RESET << "." << std::endl;
	std::cout << "< ";
	std::getline(std::cin, command);

	if (command == "ADD") {
        std::cout << std::endl << "You chose the command " << ORANGE << "ADD" << RESET << std::endl;
		_add();
    } else if (command == "SEARCH") {
        std::cout << "You chose the command " << ORANGE "SEARCH" << RESET << std::endl << std::endl;
		_search();
    } else if (command == "EXIT") {
        std::cout << "You chose the command " << ORANGE << "EXIT" << RESET << std::endl;
		printBye();
		return (1);
    } else {
        std::cout << RED << "Please enter a valid command." << RESET << std::endl;
    }
	return (0);
}

static std::string getNonEmptyInput(std::string message) {
	std::string input = "";
	while (input.empty()) {
		std::cout << message << std::endl;
		std::cout << "< ";
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cout << RED << "Please enter a valid input." << RESET << std::endl;
		}
	}
	return (input);
}

void Phonebook::_add() {	
	std::cout << "Give some information about the new contact." << std::endl << std::endl;

	if (_size == MAX_CONTACTS) {
		std::cout << RED << "The phonebook is full, the oldest contact will be replaced." << RESET << std::endl;
	}

	_contactList[_i].setFirstName(getNonEmptyInput("> What is its first name:"));
	_contactList[_i].setLastName(getNonEmptyInput("> What is its last name:"));
	_contactList[_i].setNickName(getNonEmptyInput("> What is its nickname:"));
	_contactList[_i].setPhoneNumber(getNonEmptyInput("> What is its phone number:"));
	_contactList[_i].setSecret(getNonEmptyInput("> What is its darkest secret:"));

	if (_size < 8) {
		_size++;
	}
	if (_i < 7) {
		_i++;
	} else {
		_i = 0;
	}
	std::cout << GREEN << "Contact added!" << RESET << std::endl << std::endl;
}

static std::string getProcessedStr(std::string str) {
	if (str.size() > 10) {
		str.resize(10);
		str[9] = '.';
		return (str);
	}
	str.insert(0, 10 - str.size(), ' ');
	return (str);
}

static bool isNumber(const std::string& str) {
    try {
        size_t pos;
        std::stoi(str, &pos);
        return pos == str.size();
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
}

static bool isValidIndex(const std::string& str, int &size) {
	if (!isNumber(str) || std::stoi(str) > size || std::stoi(str) < 0) {
		return false;
	}
	return true;
}

void Phonebook::_search() {
	std::cout << "--------------Current Repertory--------------" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < _size; i++) {
		std::cout << "|         " << i+1 << "|";
		std::cout << getProcessedStr(_contactList[i].getFirstName()) << "|";
		std::cout << getProcessedStr(_contactList[i].getLastName()) << "|";
		std::cout << getProcessedStr(_contactList[i].getNickName()) << "|";
		std::cout << std::endl;
	}
	if (this->_size != 0) {
		std::cout << "---------------------------------------------" << std::endl;
	}
	else {
		std::cout << "|                   Empty                   |" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}

	std::cout << std::endl << "Select a contact by typing its index or " << ORANGE << "EXIT" << RESET << " with " << ORANGE << "0" << RESET << std::endl;
	std::string index = "-1";
	while (!isValidIndex(index, _size)) {
		std::cout << "< ";
		std::getline(std::cin, index);
		if (!isValidIndex(index, _size)) {
			std::cout << RED << "Please enter a valid contact index." << RESET << std::endl;
		}
		else if (std::stoi(index) == 0) {
			return;
		}
		else {
			break;
		}
	}
	
	int indexInt = std::stoi(index) - 1;
	std::cout << GREEN << "You chose the index " << indexInt + 1 << RESET << std::endl;
	std::cout << "Here are the details of the contact:" << std::endl << std::endl;
	std::cout << "First Name    : " << this->_contactList[indexInt].getFirstName() << std::endl;
	std::cout << "Last Name     : " << this->_contactList[indexInt].getLastName() << std::endl;
	std::cout << "Nickname      : " << this->_contactList[indexInt].getNickName() << std::endl;
	std::cout << "Phone Number  : " << this->_contactList[indexInt].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contactList[indexInt].getSecret() << std::endl;
	std::cout << std::endl;
}
