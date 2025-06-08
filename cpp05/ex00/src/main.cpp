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
		b = Bureaucrat("Frank", 2);
		inspect(b);
	}
	catch (std::exception& e)
	{
		reportCatch(e);
	}
	return (0);
}
