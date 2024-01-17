#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span {
public:
	// Canonical Functions
	Span(unsigned int n);
	Span(const Span & other);
	Span & operator=(const Span & other);
	~Span();

	// Member Functions
	void	addNumber(int n);
	void	insertNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
	int		shortestSpan() const;
	int		longestSpan() const;

	// Exceptions
	class ContainerFullException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Container is full";
		}
	};

	class SizeTooShortException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Container is too short";
		}
	};

private:
	std::vector<int>	_container;
	unsigned int		_size;
};

#endif