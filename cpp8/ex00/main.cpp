#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(-1);
	vec.push_back(10);
	vec.push_back(341);
	vec.push_back(3);
	vec.push_back(0);


	const std::vector<int> const_vec = const_cast<std::vector<int>&>(vec);
	try{
		easyfind(vec, 10);
		easyfind(const_vec, 1);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}
}
