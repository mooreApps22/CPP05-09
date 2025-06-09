#include "Bureaucrat.hpp"
#include "Form.hpp"
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
	Bureaucrat	b("Frank", 150);
	Form		f1("GG42", 75, 75);

	try
	{
		b = Bureaucrat("Frank", 9);
		f1 = Form("GG42", 75, 75);
		Form f2("Dope222", 10, 10);

		b.signForm(f2);
		inspect(b);
		b = Bureaucrat("Frank", 76);
		b.signForm(f1);
	}
	catch (std::exception& e)
	{
		reportCatch(e);
	}
	return (0);
}
