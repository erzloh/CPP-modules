#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat b("Eric", 2);
		Form f("Form", 1, 1);
		std::cout << f << std::endl;
		b.incrementGrade();
		b.signForm(f);
		// f.beSigned(b);
		std::cout << f << std::endl;
		std::cout << b << std::endl;
	} catch (const std::exception &e) {
    	std::cout << e.what() << std::endl;
	}

	// test exceptions
	std::cout << std::endl << "-------- Test exceptions --------" << std::endl;
	std::cout << "Grade too low:" << std::endl;
	try {
		Bureaucrat b("Eric", 151);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Grade too high:" << std::endl;
	try {
		Bureaucrat b("Eric", 0);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Increment grade too high:" << std::endl;
	try {
		Bureaucrat b("Eric", 1);
		b.incrementGrade();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Decrement grade too low:" << std::endl;
	try {
		Bureaucrat b("Eric", 150);
		b.decrementGrade();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Sign form with grade too low:" << std::endl;
	Bureaucrat b("Eric", 150);
	Form f("Form", 1, 1);
	b.signForm(f);

	std::cout << "test beSigned():" << std::endl;
	try {
		Form f2("Form", 1, 1);
		f2.beSigned(b);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}