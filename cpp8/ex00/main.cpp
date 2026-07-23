#include "easyfind.hpp"
#include <list>

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(-1);
	vec.push_back(10);
	vec.push_back(341);
	vec.push_back(3);
	vec.push_back(0);
	std::list<int> lis;
	lis.push_back(1);
	lis.push_back(10);
	lis.push_back(100);
	lis.push_front(-11);

//	std::vector<int>::iterator it1;
//	it1 = vec.begin();
//	it1 += 3;
//	std::list<int>::iterator it;
//	it = lis.begin();
//	it--;
//	std::cout << "iterator: "<< *it1<<std::endl;
	const std::vector<int> const_vec = const_cast<std::vector<int>&>(vec);
	try{
		easyfind(vec, 10);
		easyfind(const_vec, 1);
		easyfind(lis, -110);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}
}
