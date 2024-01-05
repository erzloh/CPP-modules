#include "Contact.hpp"

void	Contact::setFirstName(std::string firstName) {
	_firstName = firstName;
}

void	Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}

void	Contact::setNickName(std::string nickName) {
	_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	_phoneNumber = phoneNumber;
}

void	Contact::setSecret(std::string secret) {
	_secret = secret;
}

std::string	Contact::getFirstName() const {
	return (_firstName);
}

std::string Contact::getLastName() const {
	return (_lastName);
}

std::string Contact::getNickName() const {
	return (_nickName);
}

std::string Contact::getPhoneNumber() const {
	return (_phoneNumber);
}

std::string Contact::getSecret() const {
	return (_secret);
}