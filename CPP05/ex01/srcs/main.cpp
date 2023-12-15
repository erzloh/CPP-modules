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
