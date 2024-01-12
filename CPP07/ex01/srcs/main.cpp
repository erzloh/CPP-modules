#include "iter.hpp"
#include <iostream>

#define SIZE 5

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };

    std::cout << "arr1: " << std::endl;
    iter(arr1, SIZE, &print);

    double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    std::cout << "\narr2: " << std::endl;
    iter(arr2, SIZE, &print);

    char arr3[] = { 'a', 'b', 'c', 'd', 'e' };

    std::cout << "\narr3: " << std::endl;
    iter(arr3, SIZE, &print);

    std::string arr4[] = { "one", "two", "three", "four", "five" };

    std::cout << "\narr4: " << std::endl;
    iter(arr4, SIZE, &print);

	return 0;	
}
