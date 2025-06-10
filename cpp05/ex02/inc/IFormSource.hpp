#pragma once
# include <iostream>
# include "AForm.hpp"

class	IFormSource
{
	public:
		virtual			~IFormSource() {}
		virtual void	learnForm(AForm*) = 0;
		virtual AForm*	createForm(std::string const & type) = 0;
};
