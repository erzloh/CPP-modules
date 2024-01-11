#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base *generate() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomNumber = rand() % 3;

	if (randomNumber == 0)
		return new A();
	else if (randomNumber == 1)
		return new B();
	else
		return new C();
}

void indentify(Base *p) {
	A *ptrA = dynamic_cast<A *>(p);
	if (ptrA != NULL) {
		std::cout << "actual type of the object pointed to by p: \"A\"" << std::endl;
		return;
	}
	B *ptrB = dynamic_cast<B *>(p);
	if (ptrB != NULL) {
		std::cout << "actual type of the object pointed to by p: \"B\"" << std::endl;
		return;
	}
	C *ptrC = dynamic_cast<C *>(p);
	if (ptrC != NULL) {
		std::cout << "actual type of the object pointed to by p: \"C\"" << std::endl;
		return;
	}
}

void indentify(Base &p) {
	try {
		A &refA = dynamic_cast<A &>(p);
		(void)refA;
		std::cout << "actual type of the object referenced by p: \"A\"" << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		B &refB = dynamic_cast<B &>(p);
		(void)refB;
		std::cout << "actual type of the object referenced by p: \"B\"" << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		C &refC = dynamic_cast<C &>(p);
		(void)refC;
		std::cout << "actual type of the object referenced by p: \"C\"" << std::endl;
		return;
	} catch (const std::bad_cast&) {}
}