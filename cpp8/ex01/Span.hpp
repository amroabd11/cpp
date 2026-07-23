#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

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
		int shortestSpan();
		int longestSpan()const;
		template<typename it1>
		void addNumber(it1 begin, it1 end)
		{
			while(begin < end)
			{
				addNumber(*begin);
				begin++;
			}
		}
};
