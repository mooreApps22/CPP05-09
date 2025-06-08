#include "Bureaucrat.hpp"

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
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const
{
	return (_name);
}
int		Bureaucrat::getGrade() const
{
	return (_grade);
}
void	Bureaucrat::incrementGrade()
{
	if (_grade < 1)
	{
		throw GradeTooHighException();
		return ;
	}
	_grade--;
}
void	Bureaucrat::decrementGrade()
{
	if (_grade > 150)
	{
		throw GradeTooLowException();
		return ;
	}
	_grade++;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low! Grade 150 is the lowest grade possible!");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high! Grade 1 is the highest grade possible!");
}
