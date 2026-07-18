#include "Span.hpp"

Span::Span(): store(0){}
Span::Span(unsigned int num)
{
	max_store = num;
}

Span::Span(const Span& other):max_store(other.max_store), vect_numbers(other.vect_numbers){}

Span& Span::operator=(const Span& other)
{
	if (*this != other)
	{
		max_store = other.max_store;
		vect_numbers = other.vect_numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int nb)
{
	if (vect_numbers.size() < max_store)
		vect_numbers.push_back(nb);
	else
		throw std::runtime_error("you can't add numbers anymore");
}

const int Span::shortestSpan() const{
		
}
