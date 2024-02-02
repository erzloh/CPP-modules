#include "PmergeMe.hpp"
#include <vector>
#include <iostream>

int main(int ac, char **av)
{
	// Check for input errors
	if (ac < 3) {
		std::cout << "Error: not enough arguments." << std::endl;
		exit(-1);
	}
	for (int i = 1; i < ac; i++) {
		int j = 0;
		while (av[i][j]) {
			if (!isdigit(av[i][j])) {
				std::cout << "Error: non digit character found." << std::endl;
				exit(-1);
			}
			j++;
		}
	}

	// Put elements in a vector
	std::vector<int> vec;
	for (int i = 1; i < ac; i++) {
		vec.push_back(atoi(av[i]));
	}


	// std::vector<int> myVector;

	// myVector.push_back(42);
    // myVector.push_back(17);
    // myVector.push_back(8);
    // myVector.push_back(91);
    // myVector.push_back(4);
    // myVector.push_back(62);
    // myVector.push_back(53);
    // myVector.push_back(29);
    // myVector.push_back(11);
    // myVector.push_back(77);
    // myVector.push_back(35);
    // myVector.push_back(88);
    // myVector.push_back(19);
    // myVector.push_back(50);
    // myVector.push_back(73);
    // myVector.push_back(26);
    // myVector.push_back(67);
    // myVector.push_back(14);
    // myVector.push_back(95);
    // myVector.push_back(38);

	// PmergeMe p(myVector);

	PmergeMe p(vec);
	return 0;
}
