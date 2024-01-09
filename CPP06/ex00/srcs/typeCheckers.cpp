#include "ScalarConverter.hpp"
#include <iostream>

// Checks if the string is a char and if yes, sets _char and returns true
bool ScalarConverter::_setChar(const std::string& str) {
    if (str.length() == 1 && !std::isdigit(str[0])) {
        _char = str[0];
        return true;
    }
    return false;
}

// Checks if the string is an int and if yes, sets _int and returns true
bool ScalarConverter::_setInt(const std::string& str) {
    try {
        int i = std::stoi(str);
        if (str.find('.') != std::string::npos || str.find('f') != std::string::npos)
            return false;
        _int = i;
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
}

// Checks if the string is a float and if yes, sets _float and returns true
bool ScalarConverter::_setFloat(const std::string& str) {
    try {
        float f = std::stof(str);
        if (str.find('f') == std::string::npos || str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
            return false;
        _float = f;
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
}

// Checks if the string is a double and if yes, sets _double and returns true
bool ScalarConverter::_setDouble(const std::string& str) {
    try {
        // Check for inf, -inf and nan because stod() weirdly throws an exception for them
        if (str == "inf" || str == "+inf") {
            _double = INFINITY;
            return true;
        } else if (str == "-inf") {
            _double = -INFINITY;
            return true;
        } else if (str == "nan") {
            _double = NAN;
            return true;
        }
        double d = std::stod(str);
        if (str.find('.') == std::string::npos)
            return false;
        _double = d;
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
}