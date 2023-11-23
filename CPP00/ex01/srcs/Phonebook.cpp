#include "Phonebook.hpp"
#include <iostream>

#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define ORANGE      "\033[38;5;208m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"

Phonebook::Phonebook() {
	this->i = 0;

}

Phonebook::~Phonebook() {
}

void Phonebook::start() {
	std::cout << std::endl;
    std::cout << "           /$$                                     /$$                           /$$      \n";
    std::cout << "          | $$                                    | $$                          | $$      \n";
    std::cout << "  /$$$$$$ | $$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$ | $$$$$$$   /$$$$$$   /$$$$$$ | $$   /$$\n";
    std::cout << " /$$__  $$| $$__  $$ /$$__  $$| $$__  $$ /$$__  $$| $$__  $$ /$$__  $$ /$$__  $$| $$  /$$/\n";
    std::cout << "| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$$$$$/ \n";
    std::cout << "| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$_  $$ \n";
    std::cout << "| $$$$$$$/| $$  | $$|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$/|  $$$$$$/|  $$$$$$/| $$ \\  $$\n";
    std::cout << "| $$____/ |__/  |__/ \\______/ |__/  |__/ \\_______/|_______/  \\______/  \\______/ |__/  \\__/\n";
    std::cout << "| $$                                                                                      \n";
    std::cout << "| $$                                                                                      \n";
    std::cout << "|__/                                                                                      \n";
	std::cout << std::endl;
	std::cout << "   ____   __   __    U _____ u   ____                  ____  \n";
    std::cout << "U | __\")u \\ \\ / /    \\| ___\"|/U |  _\"\\ u     ___    U /\"___| \n";
    std::cout << " \\|  _ \\/  \\ V /      |  _|\"   \\| |_) |/    |\"_|     \\| | u   \n";
    std::cout << "  | |_) | U_|\"|_u     | |___    |  _ <       | |     | |/__   \n";
    std::cout << "  |____/    |_|       |_____|   |_| \\_\\    U/| |\\u    \\____| \n";
    std::cout << " _|| \\\\_.-,//|(_      <<   >>   //   \\\\_.-,_|___|_,-._// \\\\  \n";
    std::cout << "(__) (__)(_) (__)    (__) (__) (__)  (__)\\_)-' '-(_/(__)(__) \n";
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "Hello and welcome to my awesome phonebook!" << RESET << std::endl;
	while (1) {
		if (this->readCommand())
			break;
	}
}

int Phonebook::readCommand() {
	std::string command;

	std::cout << "Type the command " << ORANGE << "ADD" << RESET << ", " << ORANGE << "SEARCH" << RESET << ", or " << ORANGE << "EXIT" << RESET << "." << std::endl;
	std::cout << "< ";
	std::getline(std::cin, command);

	if (command == "ADD") {
        std::cout << std::endl << "You chose the command " << ORANGE << "ADD" << RESET << std::endl;
		this->add();
    } else if (command == "SEARCH") {
        std::cout << "You chose the command " << ORANGE "SEARCH" << RESET << std::endl << std::endl;
		this->search();
    } else if (command == "EXIT") {
        std::cout << "You chose the command " << ORANGE << "EXIT" << RESET << std::endl;
		this->exit();
		return (1);
    } else {
        std::cout << RED << "Please enter a valid command." << RESET << std::endl;
    }
	return (0);
}

void Phonebook::add() {	
	std::cout << "Give some information about the new contact." << std::endl << std::endl;

	int current = this->i;
	if (this->i == 8) {
		std::cout << RED << "The phonebook is full, the oldest contact will be replaced." << RESET << std::endl;
		current = 0;
	}

	while (this->contactList[current].firstName.empty()) {
		std::cout << "> What is its first name:" << std::endl;
		std::cout << "< ";
		std::getline(std::cin, this->contactList[current].firstName);
		if (this->contactList[current].firstName.empty()) {
			std::cout << RED << "Please enter a valid first name." << RESET << std::endl;
		}
	}
	while (this->contactList[current].lastName.empty()) {
		std::cout << "> What is its last name:" << std::endl;
		std::cout << "< ";
		std::getline(std::cin, this->contactList[current].lastName);
		if (this->contactList[current].lastName.empty()) {
			std::cout << RED << "Please enter a valid last name." << RESET << std::endl;
		}
	}
	while (this->contactList[current].nickName.empty()) {
		std::cout << "> What is its nickname:" << std::endl;
		std::cout << "< ";
		std::getline(std::cin, this->contactList[current].nickName);
		if (this->contactList[current].nickName.empty()) {
			std::cout << RED << "Please enter a valid nickname." << RESET << std::endl;
		}
	}
	while (this->contactList[current].phoneNumber.empty()) {
		std::cout << "> What is its phone number:" << std::endl;
		std::cout << "< ";
		std::getline(std::cin, this->contactList[current].phoneNumber);
		if (this->contactList[current].phoneNumber.empty()) {
			std::cout << RED << "Please enter a valid phone number." << RESET << std::endl;
		}
	}
	while (this->contactList[current].secret.empty()) {
		std::cout << "> What is its darkest secret:" << std::endl;
		std::cout << "< ";
		std::getline(std::cin, this->contactList[current].secret);
		if (this->contactList[current].secret.empty()) {
			std::cout << RED << "Please enter a valid darkest secret." << RESET << std::endl;
		}
	}

	if (this->i != 8) {
		this->i++;
	}

	std::cout << GREEN << "Contact added!" << RESET << std::endl << std::endl;
}

void Phonebook::search() {
	std::cout << "--------------Current Repertory--------------" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->i; i++) {
		std::cout << "|         " << i+1 << "|";
		std::cout << getProcessedStr(this->contactList[i].firstName) << "|";
		std::cout << getProcessedStr(this->contactList[i].lastName) << "|";
		std::cout << getProcessedStr(this->contactList[i].nickName) << "|";
		std::cout << std::endl;
	}
	if (this->i != 0) {
		std::cout << "---------------------------------------------" << std::endl;
	}
	else {
		std::cout << "|                   Empty                   |" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}

	std::cout << std::endl << "Select a contact by typing its index or " << ORANGE << "EXIT" << RESET << " with " << ORANGE << "0" << RESET << std::endl;
	std::string index = "-1";
	while (!this->isValidIndex(index)) {
		std::cout << "< ";
		std::getline(std::cin, index);
		if (!this->isValidIndex(index)) {
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
	std::cout << "First Name    : " << this->contactList[indexInt].firstName << std::endl;
	std::cout << "Last Name     : " << this->contactList[indexInt].lastName << std::endl;
	std::cout << "Nickname      : " << this->contactList[indexInt].nickName << std::endl;
	std::cout << "Phone Number  : " << this->contactList[indexInt].phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->contactList[indexInt].secret << std::endl;
	std::cout << std::endl;
}

std::string Phonebook::getProcessedStr(std::string str) {
	if (str.size() > 10) {
		str.resize(10);
		str[9] = '.';
		return (str);
	}
	str.insert(0, 10 - str.size(), ' ');
	return (str);
}

bool Phonebook::isNumber(const std::string& str) {
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

bool Phonebook::isValidIndex(const std::string& str) {
	if (!this->isNumber(str) || std::stoi(str) > this->i || std::stoi(str) < 0) {
		return false;
	}
	return true;
}

void Phonebook::exit() {
	std::cout << BLUE << "Goodbye!" << RESET << std::endl;

	std::cout << "                                          \n";
    std::cout << "            88                           \n";
    std::cout << "            \"\"                           \n";
    std::cout << "                                          \n";
    std::cout << " ,adPPYba,  88  ,adPPYYba,   ,adPPYba,   \n";
    std::cout << "a8\"     \"\"  88  \"\"     `Y8  a8\"     \"8a  \n";
    std::cout << "8b          88  ,adPPPPP88  8b       d8  \n";
    std::cout << "\"8a,   ,aa  88  88,    ,88  \"8a,   ,a8\"  \n";
    std::cout << " `\"Ybbd8\"'  88  `\"8bbdP\"Y8   `\"YbbdP\"'   \n";
    std::cout << "                                          \n";
    std::cout << "                                          \n";
}