#include "Bureaucrat.hpp"
#include "Form.hpp"

// Special Member Methods

Bureaucrat::Bureaucrat() : _name("Bob"), _grade(1) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)	
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
//	*this = other; // should be able to remove
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

// Getters

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int		Bureaucrat::getGrade() const
{
	return (_grade);
}

// Modus Operandi

void	Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
	if (form.getIsSigned())
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
	else
	{
		std::cout << _name << "counldn't signed " << form.getName() << " because " << std::endl;
		if (_grade > form.getGradeRequiredToSign())	
			throw GradeTooLowException();
		else
			throw GradeTooHighException();
	}
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}
void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

// Exceptions

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low! Grade 150 is the lowest grade possible!");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high! Grade 1 is the highest grade possible!");
}
