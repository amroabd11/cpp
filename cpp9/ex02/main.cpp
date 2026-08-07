#include "PmergeMe.hpp"

int main(int argc, char **v)
{
	if (argc < 2)
		return -1;
	vec_seq sequence;
	try{
		parse_vec(argc, v, sequence);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	for(std::vector<int>::iterator it=sequence.begin(); it<sequence.end();it++)
	{
		std::cout << *it<<std::endl;
	}
	F_Jhonson_sort(sequence);
	std::cout << "after ----------------------------after\n";

	for(std::vector<int>::iterator it=sequence.begin(); it<sequence.end();it++)
	{
		std::cout << *it<<std::endl;
	}
}
