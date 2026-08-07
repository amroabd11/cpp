#include "PmergeMe.hpp"

int main(int argc, char **v)
{
	if (argc < 2)
	{
		std::cerr << "Error: not enough params"<<std::endl;
		return -1;
	}
	vec_seq sequence;
	try{
		parse_vec(argc, v, sequence);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
	deque_seq d_sequence(sequence.begin(), sequence.end());
	std::cout << "Before:  ";
	for(std::vector<int>::iterator it=sequence.begin(); it<sequence.end();it++)
		std::cout << *it<< " ";
	std::cout << std::endl;

	double 	v_start = get_time();
	F_Jhonson_sort(sequence);
	double v_end = get_time();

	double d_start = get_time();
	F_Jhonson_sort_deq(d_sequence);
	double d_end = get_time();
	std::cout << "After:   ";

	for(std::vector<int>::iterator it=sequence.begin(); it<sequence.end();it++)
		std::cout << *it<<" ";
	std::cout<<std::endl;
	std::cout << "Time to process a range of "<< sequence.size()<<" elements with std::vector : "<< (v_end - v_start)<< " us"<<std::endl;

	std::cout << "Time to process a range of "<< sequence.size()<<" elements with std::deque : "<< (d_end - d_start)<< " us"<<std::endl;
	return 0;
}
