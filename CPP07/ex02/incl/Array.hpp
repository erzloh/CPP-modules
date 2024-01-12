#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
public:
	// Constructor with no arguments
	Array() : _array(new T()), _size(0) {}

	// Constructor with one argument
	Array(unsigned int n) : _array(new T[n]), _size(n) {}

	// Constructor Copy
	Array(const Array & other) : _array(new T[other.size()]), _size(other.size()) {
		for (size_t i = 0; i < _size; i++) {
			_array[i] = other.getArray()[i];
		}
	}

	// Assignment Operator
	Array & operator=(const Array & other) {
		if (this != &other) {
			delete [] _array;
			_array = new T[other.size()];
			_size = other.size();
			for (size_t i = 0; i < other.size(); i++) {
				_array[i] = other.getArray()[i];
			}
		}
		return *this;
	}

	// Destructor
	~Array() {
		delete [] _array;
	}

	// Squared Brackets Overload
	T & operator[](const size_t & i) {
		if (i >= _size) {
			throw OutOfBoundsException();
		}
		return _array[i];
	}

	// Member Functions
	const size_t & size() const {
		return _size;
	}

	const T * getArray() const {
		return _array;
	}

	// Exception
	class OutOfBoundsException : public std::exception {
		virtual const char * what() const throw() {
			return "Index is out of bounds.";
		}
	};

private:
	T *		_array;
	size_t	_size;
};

#endif

