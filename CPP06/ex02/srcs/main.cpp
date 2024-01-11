#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"

int main()
{
	Base *base = generate();
	indentify(base);
	indentify(*base);

	delete base;
	return 0;
}
