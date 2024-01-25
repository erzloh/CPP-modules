#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange & other);
	~BitcoinExchange();
	BitcoinExchange & operator=(const BitcoinExchange & other);

	void	printDatabase() const;
	void	processData(const std::string & filename);
	
private:
	void	getDatabase(const std::string & filename);
	// void	parseLine(const std::string & line);

	bool	isDateCorrect(std::string line) const;
	bool	isValueCorrect(std::string line, float & value) const;
	float	getValueAtDate(float value, std::string date);

	std::map<std::string, float> database;
};

#endif