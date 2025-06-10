#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "IFormSource.hpp"
#include "FormSource.hpp"
#include "data.hpp"

void	reportCatch(std::exception& e)
{
	std::cerr << "Exception caught: " << e.what() << std::endl;
}

void	inspect(Bureaucrat b)
{
	std::cout << b << std::endl;
}

int	main(void)
{
	IFormSource*	src = new FormSource();
	AForm*			tmp;
	Bureaucrat		b("Frank", 150);

	src->learnForm(new ShrubberyCreationForm());
	tmp = src->createForm("shrub");
	try
	{
		b = Bureaucrat("Bob", 34);
		inspect(b);
		b.signForm(*tmp);
		b.executeForm(*tmp);
	}
	catch (std::exception& e)
	{
		reportCatch(e);
	}
	return (0);
}
