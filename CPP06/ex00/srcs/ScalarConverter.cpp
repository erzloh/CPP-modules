#include "ScalarConverter.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

// ------------------ Static variables ------------------
char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0.0f;
double ScalarConverter::_double = 0.0;
ScalarConverter::e_type ScalarConverter::_type = ScalarConverter::NONE;

// ------------------ Orthodox Canonical Form ------------------
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {
		// Copy stuff
	}
	return (*this);
}

// ------------------ Member functions ------------------
void ScalarConverter::convert(const std::string& str) {
    // Checks the type of the string and sets the corresponding variable
    if (_setChar(str)) {
        _type = CHAR;
    } else if (_setInt(str)) {
        _type = INT;
    } else if (_setFloat(str)) {
        _type = FLOAT;
    } else if (_setDouble(str)) {
        _type = DOUBLE;
    } else {
        _type = NONE;
    }

    // Casts the type variable to the other types and prints all the types
    switch (_type) {
        case CHAR:
            _castCharAndPrint();
            break;
        case INT:
            _castIntAndPrint();
            break;
        case FLOAT:
            _castFloatAndPrint();
            break;
        case DOUBLE:
            _castDoubleAndPrint();
            break;
        default:
            std::cout << "Error: invalid input" << std::endl;
            break;
    }
}