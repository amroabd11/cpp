#include "Span.hpp"

Span::Span(): max_store(0){}
Span::Span(unsigned int num)
{
	max_store = num;
}

Span::Span(const Span& other):max_store(other.max_store), vect_numbers(other.vect_numbers){}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
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

int Span::shortestSpan() {
	if (vect_numbers.size() <= 1)
		return 0;
	std::sort(vect_numbers.begin(), vect_numbers.end());
	int ref = vect_numbers[1]-vect_numbers[0];
	for(size_t i=0; i<vect_numbers.size()-1;i++)
	{
		int res = vect_numbers[i+1] - vect_numbers[i];
		if (res < ref)
			ref = res;
	}
	return ref;
}

int Span::longestSpan() const{
	if (vect_numbers.size() <= 1)
		return 0;
	std::vector<int>::const_iterator min_it;
	std::vector<int>::const_iterator max_it;
	min_it = min_element(vect_numbers.begin(), vect_numbers.end());
	max_it = max_element(vect_numbers.begin(), vect_numbers.end());

	return *max_it - *min_it;
}


