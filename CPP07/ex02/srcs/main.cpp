#include "Array.hpp"
#include <iostream>

#define MAX_VAL 10

int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}

// class Awesome{

// public:
//     Awesome(void) : _n(0){}
//     Awesome(int n) : _n(n) {}
// 	Awesome(const Awesome &a) : _n(a._n) {}
//     Awesome &operator= (Awesome &a) {_n = a._n; return *this;}

//     Awesome &operator= (int n) {_n = n; return *this;}

//     int get_n()const {return _n;}

// private:
//     int _n;
// };

// std::ostream &operator <<(std::ostream &o, const Awesome& a) {
// 	o << a.get_n();
// 	return o;
// }

// int main()
// {
// 	Array<Awesome> awesome_array(MAX_VAL);

// 	srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
// 		awesome_array[i] = rand();
//     }
// 	//SCOPE
//     {
//         Array<Awesome> tmp = awesome_array;
//         Array<Awesome> test(tmp);
//     }
// 	try
//     {
//         awesome_array[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         awesome_array[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         awesome_array[i] = rand();
//     }

//     return 0;
// }