#include <iostream>
#include "Bureaucrat.hpp"

std::ostream& operator<<(std:: ostream& output, const Bureaucrat& other)
{
	output << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (output);
}
