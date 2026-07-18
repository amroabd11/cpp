#pragma once

#include <iostream>
#include <algorithm>

class Span{
	private:
		unsigned int max_store;
		std::vector<int> vect_numbers;
	public:
		Span();
		Span(unsigned int num);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int nb);
		const int shortestSpan()const;
		const int longestSpan()const;
};
