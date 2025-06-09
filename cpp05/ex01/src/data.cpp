#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream& operator<<(std:: ostream& output, const Bureaucrat& other)
{
	output << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (output);
}

std::ostream& operator<<(std:: ostream& output, const Form& other)
{
	output << "Form: " << other.getName();
	return (output);
}
