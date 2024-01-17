#include "Span.hpp"

// Canonical Functions
Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span & other) {
	*this = other;
}

Span & Span::operator=(const Span & other) {
	if (this != &other) {
		_size = other._size;
		_container = other._container;
	}
	return *this;
}

Span::~Span() {}

// Member Functions
void Span::addNumber(int n) {
	if (_container.size() < _size) {
		_container.push_back(n);
	} else {
		throw ContainerFullException();
	}
}

int Span::shortestSpan() const {
	if (_container.size() < 2) {
		throw SizeTooShortException();
	}
	std::vector<int> sortedContainer = _container;
	std::sort(sortedContainer.begin(), sortedContainer.end());

	int shortestSpan = std::numeric_limits<int>::max();

	for (std::vector<int>::const_iterator it = sortedContainer.begin(); it != sortedContainer.end() - 1; it++) {
		int currentSpan = *(it + 1) - *it;
		if (currentSpan < shortestSpan) {
			shortestSpan = currentSpan;
		}
	}
	return shortestSpan;
}

int Span::longestSpan() const {
	if (_container.size() < 2) {
		throw SizeTooShortException();
	}
	std::vector<int> sortedContainer = _container;
	std::sort(sortedContainer.begin(), sortedContainer.end());

	return sortedContainer[sortedContainer.size() - 1] - sortedContainer[0];
}

void	Span::insertNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	if (std::distance(start, end) > static_cast<std::ptrdiff_t>(_size - _container.size())) {
		throw ContainerFullException();
	}
	_container.insert(_container.end(), start, end);
}