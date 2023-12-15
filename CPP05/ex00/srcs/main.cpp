#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b("Eric", 2);
		// Bureaucrat b("Eric", 1);
		// Bureaucrat b("Eric", 200);
		b.incrementGrade();
		std::cout << b << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
