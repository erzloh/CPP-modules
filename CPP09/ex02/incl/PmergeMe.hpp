#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <iterator>

class PmergeMe {
public:
	PmergeMe(std::vector<int> inputArray);
	PmergeMe(const PmergeMe & other);
	PmergeMe &operator=(const PmergeMe & other);
	~PmergeMe();

	std::vector<int> sort(std::vector<int> inputArray);
	std::list<int> sort(std::list<int> inputArray);

private:
	PmergeMe();
	int oddNumber;
	bool isOdd;

	void mergeVector(std::vector< std::pair< int, int > > &vec, int left, int mid, int right);
	void mergeSortVector(std::vector< std::pair< int, int > > &vec, int left, int right);

	void mergeList(std::list< std::pair< int, int > > &lst, std::list< std::pair< int, int > >::iterator left, std::list< std::pair< int, int > >::iterator mid, std::list< std::pair< int, int > >::iterator right);
    void mergeSortList(std::list< std::pair< int, int > > &lst, std::list< std::pair< int, int > >::iterator left, std::list< std::pair< int, int > >::iterator right);

	// Binary Search
	template <typename T>
	typename T::const_iterator binarySearch(const T &vec, const int &value) {
		typename T::const_iterator left = vec.begin();
		typename T::const_iterator right = vec.end();

		while (left != right) {
			typename T::const_iterator mid = left;
			std::advance(mid, std::distance(left, right) / 2);

			if (*mid == value) {
				return mid;
			} else if (*mid < value) {
				left = std::next(mid);
			} else {
				right = mid;
			}
		}
		return left;
	}

	template <typename T>
	void insertPendToS(T & pend, T & S) {
		size_t pendSize = pend.size();
		for (size_t i = 0; i < pendSize; i++) {
			S.insert(binarySearch(S, pend[i]), pend[i]);
		}
	}
};

#endif