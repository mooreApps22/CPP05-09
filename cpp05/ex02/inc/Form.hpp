#pragma once
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExec;
		 
    public:
        Form();
        Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeRequiredToSign(void) const;
		int			getGradeRequiredToExec(void) const;

		void		beSigned(Bureaucrat& b);

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

		class BureaucratGradeInvalidException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class BureaucratGradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
