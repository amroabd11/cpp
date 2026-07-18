#pragma once
#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>


template<typename T>
void easyfind(T &cont, int num)
{
	typename T::const_iterator found = std::find(cont.begin(), cont.end(), num);
	if (found == cont.end())
		throw std::runtime_error("not found");
	std::cout << "found"<<std::endl;
}
