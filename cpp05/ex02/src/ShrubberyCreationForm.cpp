#include "ShrubberyCreationForm.hpp"
#include "ShrubberyCreationFormExceptions.hpp"
#include "Bureaucrat.hpp"

// Special Member Methods

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("GG42", 20, 20) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExec)
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:	_name( other._name),
		_isSigned( false),
		_gradeRequiredToSign( other._gradeRequiredToSign),
		_gradeRequiredToExec( other._gradeRequiredToExec)
{
//	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Getters

std::string	ShrubberyCreationForm::getName() const
{
	return (_name);
}

bool	ShrubberyCreationForm::getIsSigned() const
{
	return (_isSigned);
}

int		ShrubberyCreationForm::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int		ShrubberyCreationForm::getGradeRequiredToExec() const
{
	return (_gradeRequiredToExec);
}

// Modus Operandi

void	ShrubberyCreationForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > 0 and b.getGrade() < _gradeRequiredToSign)
		_isSigned = true;
	else
	{
		if (b.getGrade() == 0)
			throw BureaucratGradeInvalidSignException();
		else
			throw BureaucratGradeTooLowSignException();
	}
}

void	ShrubberyCreationForm::execute(Bureaucrat& b)
{
	if (b.getGrade() == 0)
			throw BureaucratGradeInvalidExecException();
	if (b.getGrade() > 137)
			throw BureaucratGradeTooLowExecException();
	std::cout << "    ###      " << std::endl;
	std::cout << "   #o###*    " << std::endl;
	std::cout << " #####o###   " << std::endl;
	std::cout << "#o#\#|#/###  " << std::endl;
	std::cout << " ###\|/#o#   " << std::endl;
	std::cout << "  # }|{ #    " << std::endl;
	std::cout << "    }|{      " << std::endl;
}

AForm*	ShrubberyCreationForm::clone(void) const
{
	return new ShrubberyCreationForm(*this);
}
