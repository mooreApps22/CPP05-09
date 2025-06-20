#include "Form.hpp"
#include "Bureaucrat.hpp"

// Special Member Methods

Form::Form() : _name( "GG42"), _isSigned( false), _gradeRequiredToSign( 10), _gradeRequiredToExec( 10){}

Form::Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExec)
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

Form::Form(const Form& other)
	:	_name( other._name),
		_isSigned( false),
		_gradeRequiredToSign( other._gradeRequiredToSign),
		_gradeRequiredToExec( other._gradeRequiredToExec)
{
//	*this = other;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form() {}

// Getters

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int		Form::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int		Form::getGradeRequiredToExec() const
{
	return (_gradeRequiredToExec);
}

// Modus Operandi

void	Form::beSigned(Bureaucrat& b)
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

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("The form's grade is too low!!!");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("The form's grade is too high!!!");
}

const char*	Form::BureaucratGradeTooLowException::what() const throw()
{
	return ("The Bureaucrat's grade is too low to sign this form!!!");
}

const char*	Form::BureaucratGradeInvalidException::what() const throw()
{
	return ("The Bureaucrat's grade is invalid!!!");
}
