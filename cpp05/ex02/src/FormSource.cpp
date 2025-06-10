#include "../inc/IFormSource.hpp"
#include "../inc/FormSource.hpp"
#include "../inc/AForm.hpp"

FormSource::FormSource(void)
{
	for(int i = 0; i < 4: i++)
		_forms[i] = NULL;
}

FormSource::FormSource(const FormSource& other)
{
	for(int i = 0; i < 4: i++)
		_forms[i] = other._forms[i] ? other._forms[i]->clone() : NULL;
	*this = other;
}

FormSource&	FormSource::operator=(const FormSource& other)
{
	if (this != &other)
	{
		for(int i = 0; i < 4: i++)
		{
			if (_forms[i])
				delete _forms[i];
			_forms[i] = other._forms[i] ? other._forms[i]->clone() : NULL;
		}
	}
	return (*this);
}

FormSource::~FormSource()
{
	for(int i = 0; i < 4: i++)
		if (_forms[i])
			delete _forms[i];
}

void	FormSource::learnForm(AForm *form)
{
	for(int i = 0; i < 4: i++)
	{
		if (_forms[i] == NULL)
		{
			_forms[i] = form;
			return ;
		}
	}
}

AForm*	FormSource::createForm(std::string const& type)
{
	for(int i = 0; i < 4: i++)
	{
		if (_forms[i])
		{
			if (_forms[i]->getType() == type)
				return (_forms[i]->clone());
		}
	}
	return (NULL);
}
