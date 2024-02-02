#include "PmergeMe.hpp"
#include <iostream>
#include <utility>
#include <ctime>

// -------------- Canonical Functions --------------
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vectorInputArray) {
	// Print initial array
	std::cout << "Before:  ";
	for (size_t i = 0; i < vectorInputArray.size(); i++) {
		std::cout << vectorInputArray[i] << " ";
	}
	std::cout << std::endl;
	
	// Sort vector array 
	clock_t start = clock();
	std::vector<int> vectorOutputArray = sort(vectorInputArray);
	clock_t end = clock();

	// Print sorted array
	std::cout << "After:   ";
	for (size_t i = 0; i < vectorOutputArray.size(); i++) {
		std::cout << vectorOutputArray[i] << " ";
	}
	std::cout << std::endl;

	// Print vector time
	clock_t duration = end - start;
	std::cout << "Time to process a range of " << vectorInputArray.size() << " elements with std::vec<int>: "
              << static_cast<double>(duration) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;

	// Sort list array
	std::list<int> listInputArray(vectorInputArray.begin(), vectorInputArray.end());

	start = clock();
	std::list<int> listOutputArray = sort(listInputArray);
	end = clock();

	// Print list time
	duration = end - start;
	std::cout << "Time to process a range of " << listInputArray.size() << " elements with std::list<int>: "
              << static_cast<double>(duration) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;
}
	

PmergeMe::PmergeMe(const PmergeMe & other) {
	*this = other;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & other) {
	if (this != &other) {
		oddNumber = other.oddNumber;
		isOdd = other.isOdd;
	}
 	return *this;
}

PmergeMe::~PmergeMe() {}

// -------------- Member Functions --------------

std::vector<int> PmergeMe::sort(std::vector<int> inputArray) {
	// Check if array size is odd
	if (inputArray.size() % 2 != 0) {
		isOdd = true;
		oddNumber = inputArray[inputArray.size() - 1];
		inputArray.pop_back();
	} else {
		isOdd = false;
	}

	// Create a vector of pairs
	std::vector< std::pair< int, int > > pairsArray;
	for (size_t i = 0; i < inputArray.size(); i += 2) {
		pairsArray.push_back(std::make_pair(inputArray[i], inputArray[i + 1]));
	}

	// Put the highest number of each pair on the left
	for (size_t i = 0; i < pairsArray.size(); i++) {
		if (pairsArray[i].second > pairsArray[i].first) {
			std::swap(pairsArray[i].first, pairsArray[i].second);
		}
	}

	// Sort recursively by the highest number
	mergeSortVector(pairsArray, 0, pairsArray.size() - 1);

	// Put each highest element of pairsArray into an array "S"
	std::vector<int> S;
	for (size_t i = 0; i < pairsArray.size(); i++) {
		S.push_back(pairsArray[i].first);
	}

	// Put each lowest element of pairs Array into an array "pend"
	std::vector<int> pend;
	for (size_t i = 0; i < pairsArray.size(); i++) {
		pend.push_back(pairsArray[i].second);
	}

	// Put the first element of pend in the first index of S since it is obviously the smallest number
	S.insert(S.begin(), pend[0]);
	pend.erase(pend.begin());

	// Insert elements from pend to S with a binary insertion
	size_t pendSize = pend.size();
	for (size_t i = 0; i < pendSize; i++) {
		S.insert(binarySearch(S, pend[i]), pend[i]);
	}

	// Insert odd number if there is one
	if (isOdd) {
		S.insert(binarySearch(S, oddNumber), oddNumber);
	}

	return S;
}

std::list<int> PmergeMe::sort(std::list<int> inputList) {
    // Check if list size is odd
    if (inputList.size() % 2 != 0) {
        isOdd = true;
        oddNumber = inputList.back();
        inputList.pop_back();
    } else {
        isOdd = false;
    }

    // Create a list of pairs
    std::list< std::pair<int, int> > pairsList;
    std::list<int>::iterator it = inputList.begin();
    while (it != inputList.end()) {
        int first = *it;
        ++it;
        int second = *it;
        ++it;
        pairsList.push_back(std::make_pair(first, second));
    }

    // Put the highest number of each pair on the left
    for (std::list< std::pair<int, int> >::iterator pairIt = pairsList.begin(); pairIt != pairsList.end(); ++pairIt) {
        if (pairIt->second > pairIt->first) {
            std::swap(pairIt->first, pairIt->second);
        }
    }

    // Sort recursively by the highest number
    mergeSortList(pairsList, pairsList.begin(), std::prev(pairsList.end()));

    // Put each highest element of pairsList into a list "S"
    std::list<int> S;
    for (std::list< std::pair<int, int> >::const_iterator pairIt = pairsList.begin(); pairIt != pairsList.end(); ++pairIt) {
        S.push_back(pairIt->first);
    }

    // Put each lowest element of pairsList into a list "pend"
    std::list<int> pend;
    for (std::list< std::pair<int, int> >::const_iterator pairIt = pairsList.begin(); pairIt != pairsList.end(); ++pairIt) {
        pend.push_back(pairIt->second);
    }

    // Put the first element of pend in the first index of S since it is obviously the smallest number
    S.insert(S.begin(), pend.front());
    pend.pop_front();

    // Insert elements from pend to S with a binary insertion
    while (!pend.empty()) {
        S.insert(binarySearch(S, pend.front()), pend.front());
        pend.pop_front();
    }

    // Insert odd number if there is one
    if (isOdd) {
        S.insert(binarySearch(S, oddNumber), oddNumber);
    }

    return S;
}

// -------------- Sort Functions --------------
// Merge two sorted array together
void PmergeMe::mergeVector(std::vector< std::pair< int, int > > &vec, int left, int mid, int right) {
	int leftArraySize = mid - left + 1;
	int rightArraySize = right - mid;

	// Create arrays of both halfs
	std::vector< std::pair< int, int > > leftArray(leftArraySize);
	std::vector< std::pair< int, int > > rightArray(rightArraySize);

	for (int i = 0; i < leftArraySize; i++) {
		leftArray[i] = vec[left + i];
	}

	for (int i = 0; i < rightArraySize; i++) {
		rightArray[i] = vec[mid + 1 + i];
	}

	// Put numbers in vec in a sorted order
	int i = 0;
	int j = 0;
	int k = left;
	while (i < leftArraySize && j < rightArraySize) {
		if (leftArray[i].first <= rightArray[j].first) {
			vec[k] = leftArray[i];
			i++;
		} else {
			vec[k] = rightArray[j];
			j++;
		}
		k++;
	}

	while (i < leftArraySize) {
		vec[k] = leftArray[i];
		i++;
		k++;
	}

	while (j < rightArraySize) {
		vec[k] = rightArray[j];
		j++;
		k++;
	}
}

void PmergeMe::mergeSortVector(std::vector< std::pair< int, int > > &vec, int left, int right) {
	if (left < right) {
		// Define the index of the middle of the array
		int mid = left + (right - left) / 2;

		// Sort both halfs
		mergeSortVector(vec, left, mid);
		mergeSortVector(vec, mid + 1, right);

		// Merge the two halfs together
		mergeVector(vec, left, mid, right);
	}
}


void PmergeMe::mergeList(std::list< std::pair< int, int > > &lst, std::list< std::pair< int, int > >::iterator left, std::list< std::pair< int, int > >::iterator mid, std::list< std::pair< int, int > >::iterator right) {
	(void)lst;
    // Create temporary lists to hold the left and right halves
    std::list< std::pair< int, int > > leftList;
    std::list< std::pair< int, int > > rightList;

    for (std::list< std::pair< int, int > >::iterator it = left; it != std::next(mid); ++it) {
        leftList.push_back(*it);
    }

    for (std::list< std::pair< int, int > >::iterator it = std::next(mid); it != std::next(right); ++it) {
        rightList.push_back(*it);
    }

    // Iterate through the temporary lists and merge them back into the original list
    std::list< std::pair< int, int > >::iterator itLeft = leftList.begin();
    std::list< std::pair< int, int > >::iterator itRight = rightList.begin();
    std::list< std::pair< int, int > >::iterator it = left;

    while (itLeft != leftList.end() && itRight != rightList.end()) {
        if (itLeft->first <= itRight->first) {
            *it = *itLeft;
            ++itLeft;
        } else {
            *it = *itRight;
            ++itRight;
        }
        ++it;
    }

    // Copy the remaining elements of the left and right lists
    while (itLeft != leftList.end()) {
        *it = *itLeft;
        ++it;
        ++itLeft;
    }

    while (itRight != rightList.end()) {
        *it = *itRight;
        ++it;
        ++itRight;
    }
}

void PmergeMe::mergeSortList(std::list< std::pair< int, int > > &lst, std::list< std::pair< int, int > >::iterator left, std::list< std::pair< int, int > >::iterator right) {
    if (left != right) {
        // Find the middle of the list
        std::list< std::pair< int, int > >::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        // Sort both halves
        mergeSortList(lst, left, mid);
        mergeSortList(lst, std::next(mid), right);

        // Merge the two halves together
        mergeList(lst, left, mid, right);
    }
}