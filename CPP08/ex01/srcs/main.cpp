#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "Testing Excepetions:" << std::endl << std::endl;
	{
		try {
			std::cout << "Testing ContainerFullException with addNumber()" << std::endl;
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(12);
		} catch (std::exception &e) {
			std::cout << "error: " << e.what() << std::endl;	
		}
	}
	{
		try {
			std::cout << "Testing ContainerFullException with insertNumber()" << std::endl;
			Span sp = Span(5);
			std::vector<int> vec;
			vec.push_back(3);
			vec.push_back(10);
			vec.push_back(42);
			vec.push_back(18);
			vec.push_back(1);
			vec.push_back(5);
			sp.insertNumbers(vec.begin(), vec.end());
		} catch (std::exception &e) {
			std::cout << "error: " << e.what() << std::endl;	
		}
	}
	{
		try {
			std::cout << "Testing SizeTooShortExcepetion" << std::endl;
			Span sp = Span(5);
			sp.addNumber(6);
			std::cout << sp.shortestSpan() << std::endl;	
		} catch (std::exception &e) {
			std::cout << "error: " << e.what() << std::endl;	
		}
	}
	std::cout << std::endl << "Easy Testing Span Functions:" << std::endl << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "shortest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl << "Hard Testing Span Functions:" << std::endl << std::endl;
	{
		#define SIZE 15000

		std::srand(static_cast<unsigned int>(std::time(0)));

		Span sp = Span(SIZE);

		for (size_t i = 0; i < SIZE; i++) {
			sp.addNumber(std::rand() % std::numeric_limits<int>::max());
		}

		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "shortest span: " << sp.longestSpan() << std::endl;
	}


	return 0;
}
