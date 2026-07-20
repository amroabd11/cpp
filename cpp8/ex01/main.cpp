#include "Span.hpp"
#include <map>

int main()
{
	Span sp = Span(5);
	try{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	//std::vector<int> a;
	//a.push_back(100);
	//a.push_back(101);
	//a.push_back(10);
	//a.push_back(0);
	//std::vector<int>::iterator it;
	//
	//it = a.begin();
	//it++;
	//it--;
	//std::vector<int>::iterator it2 = ++it;
//	std::map<int,char> m;
//	m[0] = 'a';
//	m[1] = 'b';
//
//	std::map<int,char>::iterator it;
//	std::map<int,char>::reverse_iterator it2;
//	it = m.begin();
//	it2 = m.rbegin();
//
//	std::cout << (it->second)<<std::endl;
//	std::cout << (it2->second)<<std::endl;

	return 0;
}
