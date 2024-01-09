#include "ScalarConverter.hpp"
#include <iostream>

void ScalarConverter::_castCharAndPrint() {
    std::cout << "char: ";
    if (_char < 32 || _char > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << _char << "'" << std::endl;

    _int = static_cast<int>(_char);
    _float = static_cast<float>(_char);
    _double = static_cast<double>(_char);

    std::cout << "int: " << _int << std::endl;
    std::cout << "float: " << _float << ".0f" << std::endl;
    std::cout << "double: " << _double << ".0" << std::endl;
}

void ScalarConverter::_castIntAndPrint() {
    std::cout << "char: ";
    if (_int >= -128 && _int <= 127) {
        _char = static_cast<char>(_int);
        if (_char < 32 || _char > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << _char << "'" << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }

    _float = static_cast<float>(_int);
    _double = static_cast<double>(_int);

    std::cout << "int: " << _int << std::endl;
    std::cout << "float: " << _float << ".0f" << std::endl;
    std::cout << "double: " << _double << ".0" << std::endl;
}

void ScalarConverter::_castFloatAndPrint() {
    std::cout << "char: ";
    if (_float >= -128.0f && _float <= 127.0f) {
        _char = static_cast<char>(_float);
        if (_char < 32 || _char > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << _char << "'" << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "int: ";
    if (_float >= -2147483648.0f && _float <= 2147483647.0f) {
        _int = static_cast<int>(_float);
        std::cout << _int << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }

    _double = static_cast<double>(_float);

    // Add .0f if the float is a whole number because it's not printed by default
    if (_float == static_cast<int>(_float)) {
        std::cout << "float: " << _float << ".0f" << std::endl;
    } else {
        std::cout << "float: " << _float << "f" << std::endl;
    }
    if (_double == static_cast<int>(_double)) {
        std::cout << "double: " << _double << ".0" << std::endl;
    } else {
        std::cout << "double: " << _double << std::endl;
    }
}

void ScalarConverter::_castDoubleAndPrint() {
    std::cout << "char: ";
    if (_double >= -128.0 && _double <= 127.0) {
        _char = static_cast<char>(_double);
        if (_char < 32 || _char > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << _char << "'" << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "int: ";
    if (_double >= -2147483648.0 && _double <= 2147483647.0) {
        _int = static_cast<int>(_double);
        std::cout << _int << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "float: ";
    if (_double >= -3.402823e+38 && _double <= 3.402823e+38) {
        _float = static_cast<float>(_double);
        // Add .0f if the float is a whole number because it's not printed by default
        if (_float == static_cast<int>(_float)) {
            std::cout << _float << ".0f" << std::endl;
        } else {
            std::cout << _float << "f" << std::endl;
        }
    } else if (_double == INFINITY || _double == -INFINITY || std::isnan(_double)) {
        _float = static_cast<float>(_double);
        std::cout << _float << "f" << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }

    if (_double == static_cast<int>(_double)) {
        std::cout << "double: " << _double << ".0" << std::endl;
    } else {
        std::cout << "double: " << _double << std::endl;
    }
}