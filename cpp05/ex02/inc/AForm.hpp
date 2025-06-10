#pragma once
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExec;
		 
    public:
        AForm();
        AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getGradeRequiredToSign(void) const;
		int				getGradeRequiredToExec(void) const;

		void			beSigned(Bureaucrat& b);

		virtual AForm*	clone(void) const = 0;
		virtual void	execute(Bureaucrat const & executor) const;

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
