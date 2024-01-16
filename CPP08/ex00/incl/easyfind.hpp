#include <algorithm>

// Function that returns the iterator of the first element matching n
template <typename T>
typename T::iterator easyfind(T & container, const int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end()) {
		return it;
	} else {
		return container.end();
	}
}