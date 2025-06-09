#include "data.hpp"
#include "Bureaucrat.hpp"

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
	Bureaucrat b("Frank", 150);

	try
	{
		b = Bureaucrat("Frank", 1);
		inspect(b);
		for (int i = 0; i < 162; i++)
		{
			b.decrementGrade();
			inspect(b);
		}
	}
	catch (std::exception& e)
	{
		reportCatch(e);
	}

	try
	{
		b = Bureaucrat("Frank", 150);
		inspect(b);
		for (int i = 0; i < 162; i++)
		{
			b.incrementGrade();
			inspect(b);
		}
	}
	catch (std::exception& e)
	{
		reportCatch(e);
	}
	return (0);
}
