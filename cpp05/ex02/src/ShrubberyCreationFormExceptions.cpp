#include "ShrubberyCreationForm.hpp"

// Exceptions
const char*	ShrubberyCreationForm::GradeTooLowSignException::what() const throw()
{
	return ("Bureaucrats must be grade 145 or higher to sign ShrubberyCreationForm!!!");
}

const char*	ShrubberyCreationForm::GradeInvalidSignException::what() const throw()
{
	return ("Bureaucrats cannot be grade 0 to sign ShrubberyCreationForm!!!");
}

const char*	ShrubberyCreationForm::GradeTooLowExecException::what() const throw()
{
	return ("Bureaucrats must be grade 145 or higher to sign ShrubberyCreationForm!!!");
}

const char*	ShrubberyCreationForm::GradeInvalidExecException::what() const throw()
{
	return ("Bureaucrats cannot be grade 0 to sign ShrubberyCreationForm!!!");
}


