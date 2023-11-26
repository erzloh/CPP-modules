#include <iostream>
#include <fstream>

void	replace(std::string &text, std::string &target, std::string &replacement) {
	size_t	pos = 0;
	while ((pos = text.find(target, pos)) != std::string::npos) {
		text = text.substr(0, pos) + replacement + text.substr(pos + target.length(), text.length());
	}
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "You must launch the program as following: ./programName filename s1 s2" << std::endl;
		return (1);
	}
	std::ifstream	inputFile(av[1]);
	if (!inputFile.is_open()) {
		std::cout << "An error occured when opening the file." << std::endl;
		return (1);
	}
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		fileStr;
	std::string		line;

	while (getline(inputFile, line)) {
		fileStr += line;
	}

	replace(fileStr, s1, s2);
	std::ofstream	outputFile("output.txt");
	if (!outputFile.is_open()) {
		std::cout << "An error occured when trying to create the output file." << std::endl;
		inputFile.close();
		return (1);
	}
	outputFile << fileStr;
	inputFile.close();
	outputFile.close();
}