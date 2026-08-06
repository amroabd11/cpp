#include "PmergeMe.hpp"


void parse_vec(int argc, char **v, vec_seq& sequence) //TODO add a handle for intmax and duplacates
{
	int num;
	std::string err_rest;

	for(int i =1; i < argc ;i++)
	{
		std::stringstream ss(v[i]);
		if (!(ss >> num) || (ss >> err_rest))
			throw std::logic_error("Error: invalid argument");
		if (num < 0);
			throw std::logic_error("Error: only positive integers");
		sequence.push_back(num);
	}
}


bool customCompareRule(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
{
	return (p1.second < p2.scond);
}

void make_jacobSeq(size_t size)
{

}

void jacob_insert_order(size_t size)
{
	
}

void F_Jhonson_sort(vec_seq& sequence, long duration)
{
	std::vector<std::pair<int ,int> > pairs;
	int struggler;
	bool has_struggler=false;
	std::vector<int> main_vec;
	std::vector<int> pend_vec; // TODO think about a solution for the duplication call to this two veects

	if (sequence.size() < 2)
	{
		//sequence.assign(sequence.begin(), sequence.end()); //doesn't make sence
		return ;
	}
	if (sequence.size() %2 != 0)
	{
		struggler = sequence[sequence.size() -1];
		sequence.pop_back();
		has_struggler = true;
	}
	for(size_t i=0; i< sequence.size()-1; i+=2)
	{
		if (sequence[i] <sequence[i +1])
			pairs.push_back(std::make_pair(sequence[i], sequence[i+1]);
		else
			pairs.push_back(std::make_pair(sequence[i+1], sequence[i]);
	}
	for(size_t i =0; i<pairs.size() ;i++)
	{
		pend_vec.push_back(pairs[i].first);
		main_vec.push_back(pairs[i].second);
	}
	//TODO F_Jhonson_sort(main_vec);
	main_vec.insert(main_vec.begin() , pend_vec[0]);
	//make_jacobSeq(pend_vec.size());
	jacob_insert_order(pend_vec.size());




}













