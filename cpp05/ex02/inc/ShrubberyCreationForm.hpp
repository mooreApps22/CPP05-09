#pragma once
# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExec;
		 
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExec);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getGradeRequiredToSign(void) const;
		int				getGradeRequiredToExec(void) const;

		void			beSigned(Bureaucrat& b);

		virtual AForm*	clone(void) const;
		void			execute(Bureaucrat& b);

		// Exception Classes
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeInvalidException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowExecException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
