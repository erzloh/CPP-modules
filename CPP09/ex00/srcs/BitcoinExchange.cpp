#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>

// 1. Read the bitcoin data file
// 2. Store the data in a map
// 3. Read input file line by line
// 4. Parse the line: is the date valid? is the value valid?
// 5. Search the map for the value
// 6. If found, print the value multiplied by the bitcoin value

// -------------  Orthodox Form Functions -------------
BitcoinExchange::BitcoinExchange() {
	getDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & other) {
    if (this != &other) {
    }
    return *this;
}

// ------------- Helper Functions -------------
static bool isStrDigit(const std::string& str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

// ------------- Member Functions -------------
void BitcoinExchange::getDatabase(const std::string & filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "Bitcoin database file couldn't be open." << std::endl;
		exit(1);
	}

	std::string line;
	std::string date;
	float		value;

	// Skip the first line
	std::getline(file, line);

	// Store each line in a map
	while (std::getline(file, line)) {
		date = line.substr(0, line.find(','));

		std::istringstream iss(line.substr(line.find(',') + 1));
		if ((iss >> value).fail()) {
			std::cout << "Error: value couldn't be casted to a float in from the database" << std::endl;
			exit(-1);
		}

		database[date] = value;
	}
	file.close();
}

void BitcoinExchange::printDatabase() const {
	for (std::map<std::string, float>::const_iterator it = database.begin(); it != database.end(); it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

bool BitcoinExchange::isDateCorrect(std::string line) const {
	// Check if the date's digits are actually digits
	if (!isStrDigit(line.substr(0, 4)) || !isStrDigit(line.substr(5, 2)) || !isStrDigit(line.substr(8, 2)))
		return false;
	// Check if the hyphens are in the correct place
	if (line[4] != '-' || line[7] != '-')
		return false;

	return true;
}

bool BitcoinExchange::isValueCorrect(std::string line, float & value) const {
	std::istringstream iss(line.substr(13));

	if ((iss >> value).fail()) {
		std::cout << "Error: bad input => " << line << ", (incorrect value)" << std::endl;
		return false;
	}

	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}

	if (value > 1000) {
		std::cout << "Error: number is too large." << std::endl;
		return false;
	}
	// std::cout << value << std::endl;

	return true;
}

float BitcoinExchange::getValueAtDate(float value, std::string date) {
	std::map<std::string, float>::iterator it = database.find(date);
	if (it != database.end()) {
		return database[date] * value;
	}
	for (std::map<std::string, float>::iterator it = database.begin(); it != database.end(); it++) {
		if (it->first > date) {
			it--;
			return it->second * value;
		}
	}
	return (-1);
}

// Reads each line from the input file and prints either an error either the converted bitcoin value at the specified date.
void BitcoinExchange::processData(const std::string & filename) {
	// Read input file
	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		std::cout << "inputFile file couldn't be open." << std::endl;
		exit(1);
	}

	// Read inputFile file line by line
	std::string line;
	while (std::getline(inputFile, line)) {
		// Check if the minimal lenght is correct
		if (line.length() < 14) {
			std::cout << "Error: bad input => " << line << ", (line too short)" << std::endl;
			continue;
		}

		// Check if date is valid
		if (!isDateCorrect(line)) {
			std::cout << "Error: bad input => " << line << ", (date is incorrect)" << std::endl;
			continue;
		}

		// Check if date is smaller than the smallest date possible
		if (line.substr(0, 10) < database.begin()->first) {
			std::cout << "Error: bad input => " << line <<  ", (the date should be higher or equal than the first date of the database)" << std::endl;
			continue;
		}

		// Check if there is a pipe
		if (line[11] != '|') {
			std::cout << "Error: bad input => " << line <<  ", ('|' not found at the expected place)" << std::endl;
			continue;
		}
		
		// Check if the value is valid (the function prints the errors itself)
		float value;
		if (!isValueCorrect(line, value)) {
			continue;
		}

		// Print the correct output
		std::cout << line.substr(0, 10) << " => " << value << " = " << getValueAtDate(value, line.substr(0, 10)) << std::endl;
	}
	inputFile.close();
}