#include <iostream>
#include "BitcoinExchange.hpp"

// 1. Read the bitcoin data file
// 2. Store the data in a map
// 3. Read input file line by line
// 4. Parse the line: is the date valid? is the value valid?
// 5. Search the map for the value
// 6. If found, print the value multiplied by the bitcoin value

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange bitcoinExchange;
	bitcoinExchange.processData(av[1]);

	return 0;
}