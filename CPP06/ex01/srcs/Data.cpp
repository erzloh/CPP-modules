#include "Data.hpp"
#include <iostream>

Data::Data(const int & data1, const int & data2) : _data1(data1), _data2(data2) {}

Data::Data(const Data &other) {
    *this = other;
}

Data::~Data() {}

Data & Data::operator=(const Data &other) {
    if (this != &other) {
        _data1 = other._data1;
        _data2 = other._data2;
    }
    return *this;
}

void Data::printData() {
    std::cout << _data1 << std::endl;
    std::cout << _data2 << std::endl;
}