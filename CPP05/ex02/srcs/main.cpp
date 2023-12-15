#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		Bureaucrat b("Eric", 2);
		std::cout << b << std::endl;

		ShrubberyCreationForm s("target");
		std::cout << s << std::endl;

		RobotomyRequestForm r("target");
		std::cout << r << std::endl;

		PresidentialPardonForm p("target");
		std::cout << p << std::endl;

		b.incrementGrade();

		b.signForm(s);
		std::cout << s << std::endl;

		b.signForm(r);
		std::cout << r << std::endl;

		b.signForm(p);
		std::cout << p << std::endl;

		b.executeForm(s);
		b.executeForm(r);
		b.executeForm(p);
	} catch (const std::exception &e) {
    	std::cout << e.what() << std::endl;
	}
	// } catch (Bureaucrat::GradeTooHighException &e) {
	// 	std::cout << e.what() << std::endl;
	// } catch (Bureaucrat::GradeTooLowException &e) {
	// 	std::cout << e.what() << std::endl;
	// } catch (Form::GradeTooHighException &e) {
	// 	std::cout << e.what() << std::endl;
	// } catch (Form::GradeTooLowException &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	
	return 0;
}
