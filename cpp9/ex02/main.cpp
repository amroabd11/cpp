#include "PmergeMe.hpp"

static long diff_sec(const timespec& a, const timespec& b)
{
	long sec =b.tv_sec -a.tv_sec;
	long nsec= b.tv_nsec -a.tv_nsec;
	return (long(sec)*1e9 + long(nsec));
}

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

	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);

	F_Jhonson_sort(sequence);

	clock_gettime(CLOCK_MONOTONIC, &end);

	struct timespec d_start, d_end;
	clock_gettime(CLOCK_MONOTONIC, &d_start);

	F_Jhonson_sort_deq(d_sequence);

	clock_gettime(CLOCK_MONOTONIC, &d_end);
	std::cout << "After:   ";

	for(std::vector<int>::iterator it=sequence.begin(); it<sequence.end();it++)
		std::cout << *it<<" ";
	std::cout<<std::endl;


	std::cout << "Time to process a range of "<< sequence.size()<<" elements with std::vector : "<< diff_sec(start, end)/1e3<< " us"<<std::endl;

	std::cout << "Time to process a range of "<< sequence.size()<<" elements with std::deque : "<< diff_sec(d_start, d_end)/1e3<< " us"<<std::endl;
	return 0;
}
