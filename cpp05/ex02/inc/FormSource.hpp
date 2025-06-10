#pragma once
# include <iostream>
# include "IFormSource.hpp"
# include "AForm.hpp"

class FormSource : public IFormSource
{
	private:
		AForm*	_forms[4];
	public:
		FormSource();
		FormSource(const FormSource& other);
		FormSource& operator=(const FormSource& other);
		~FormSource();
		void	learnForm(AForm *form);
		AForm*	createForm(std::string const & type);
};
