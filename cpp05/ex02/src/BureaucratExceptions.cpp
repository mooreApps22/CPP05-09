#include "../inc/Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low! Grade 150 is the lowest grade possible!");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high! Grade 1 is the highest grade possible!");
}
