#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> myVector(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::list<int> myList(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::cout << "Vector: " << std::endl;
	std::vector<int>::iterator it = easyfind(myVector, 3);
	if (it != myVector.end())
		std::cout << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;

	std::cout << "List: " << std::endl;
	std::list<int>::iterator it2 = easyfind(myList, 42);
	if (it2 != myList.end())
		std::cout << *it2 << std::endl;
	else
		std::cout << "Not found" << std::endl;
	
	return 0;
}
