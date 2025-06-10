#include "AForm.hpp"
#include "AFormExceptions.hpp"
#include "Bureaucrat.hpp"

// Special Member Methods

AForm::AForm() : _name( "GG42"), _isSigned( false), _gradeRequiredToSign( 10), _gradeRequiredToExec( 10){}

AForm::AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExec)
	:	_name( name),
		_isSigned( false),
		_gradeRequiredToSign( gradeRequiredToSign),
		_gradeRequiredToExec( gradeRequiredToExec)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExec < 1)	
		throw GradeTooHighException();
	if (gradeRequiredToSign > 150 || gradeRequiredToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	:	_name( other._name),
		_isSigned( false),
		_gradeRequiredToSign( other._gradeRequiredToSign),
		_gradeRequiredToExec( other._gradeRequiredToExec)
{
//	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

// Getters

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int		AForm::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int		AForm::getGradeRequiredToExec() const
{
	return (_gradeRequiredToExec);
}

// Modus Operandi

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > 0 and b.getGrade() < _gradeRequiredToSign)
		_isSigned = true;
	else
	{
		if (b.getGrade() == 0)
			throw BureaucratGradeInvalidException();
		else
			throw BureaucratGradeTooLowException();
	}
}

// Exceptions

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("The form's grade is too low!!!");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("The form's grade is too high!!!");
}

const char*	AForm::BureaucratGradeTooLowException::what() const throw()
{
	return ("The Bureaucrat's grade is too low to sign this form!!!");
}

const char*	AForm::BureaucratGradeInvalidException::what() const throw()
{
	return ("The Bureaucrat's grade is invalid!!!");
}
