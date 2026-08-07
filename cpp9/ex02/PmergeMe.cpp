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
		if (num < 0)
			throw std::logic_error("Error: only positive integers");
		sequence.push_back(num);
	}
}


//bool customCompareRule(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
//{
//	return (p1.second < p2.scond);
//}

std::vector<unsigned long> make_jacobSeq(size_t size)
{
	std::vector<unsigned long> seq;
	if (size <=1)
		return seq;
	unsigned long j0 = 1;
	unsigned long j1 =3;
	seq.push_back(j0);
	while (j1<size)
	{
		seq.push_back(j1);
		unsigned long next = j1+2*j0;
		j0 = j1;
		j1 = next;
	}
	return seq;
	
}

std::vector<size_t> jacob_insert_order(size_t size)
{
	std::vector<size_t> insertOrder;
	if (size == 0)
		return insertOrder;
	std::vector<unsigned long> jacobSeq = make_jacobSeq(size);
	insertOrder.push_back(0);
	if (size == 1)
		return insertOrder;
	size_t prev = 1;
	for (size_t i =0; i<jacobSeq.size(); ++i)
	{
		size_t current = jacobSeq[i];
		if (current >= size)
			current = size -1;
		for(size_t j = current; j>prev; --j)
			insertOrder.push_back(j);
		prev = current;
		if (current == size-1)
			break;
	}
	for (size_t j=size-1; j>prev ;--j)
		insertOrder.push_back(j);
	return insertOrder;
}

void F_Jhonson_sort(vec_seq& sequence)
{
	std::vector<std::pair<int ,int> > pairs;
	int struggler;
	bool has_struggler=false;
	std::vector<int> main_vec;
	std::vector<int> pend_vec; // TODO think about a solution for the duplication call to this two veects

	if (sequence.size() < 2)
	{
		sequence.assign(sequence.begin(), sequence.end()); //doesn't make sence
		return ;
	}
	if (sequence.size() %2 != 0)
	{
		struggler = sequence[sequence.size() -1];
		//sequence.pop_back();
		has_struggler = true;
	}
	for(size_t i=0; i< sequence.size()-1; i+=2)
	{
		if (sequence[i] <sequence[i +1])
			pairs.push_back(std::make_pair(sequence[i], sequence[i+1]));
		else
			pairs.push_back(std::make_pair(sequence[i+1], sequence[i]));
	}
	for(size_t i =0; i<pairs.size() ;i++)
	{
		pend_vec.push_back(pairs[i].first);
		main_vec.push_back(pairs[i].second);
	}
	F_Jhonson_sort(main_vec);
	main_vec.insert(main_vec.begin() , pend_vec[0]);
	//make_jacobSeq(pend_vec.size());
	std::vector<size_t> insertOrder;
	insertOrder = jacob_insert_order(pend_vec.size());

	for(size_t i =1; i <insertOrder.size(); ++i)
	{
		size_t index = insertOrder[i];
		std::vector<int>::iterator pos = std::lower_bound(main_vec.begin(), main_vec.end(), pend_vec[index]);
		main_vec.insert(pos, pend_vec[index]);
	}


}













