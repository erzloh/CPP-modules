#ifndef DATA_HPP
#define DATA_HPP

class Data
{
public:
    Data(const int & data1, const int & data2);
    Data(const Data & other);
    ~Data();
    Data & operator=(const Data & other);

    void printData();

private:
    int _data1;
    int _data2;
};

#endif