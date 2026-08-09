#include "PmergeMe.hpp"


void parse_vec(int argc, char **v, vec_seq& sequence)
{
	int num;
	std::string err_rest;

	for(int i =1; i < argc ;i++)
	{
		std::stringstream ss(v[i]);
		if (!(ss >> num) || (ss >> err_rest))
			throw std::logic_error("Error");
		if (num < 0)
			throw std::logic_error("Error");
		sequence.push_back(num);
	}
}


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
	for (size_t i=0; i<jacobSeq.size(); i++)
		std::cout << "----"<<jacobSeq[i] << std::endl;
	insertOrder.push_back(0);
	if (size == 1)
		return insertOrder;
	size_t prev = 1;
	for (size_t i =0; i<jacobSeq.size(); ++i)
	{
		size_t current = jacobSeq[i];
		if (current > size)
			current = size -1;
		for(size_t j = current; j>prev; --j)
			insertOrder.push_back(j-1);
		prev = current;
		if (current >= size)
			break;
	}
	for (size_t j=size; j>prev ;--j)
		insertOrder.push_back(j-1);
	return insertOrder;
}

void F_Jhonson_sort(vec_seq& sequence)
{
	std::vector<std::pair<int ,int> > pairs;
	int struggler=0;
	bool has_struggler=false;
	std::vector<int> main_vec;
	// std::vector<int> pend_vec;

	if (sequence.size() < 2)
		return ;
	if (sequence.size() %2 != 0)
	{
		struggler = sequence[sequence.size() -1];
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
		// pend_vec.push_back(pairs[i].first);
		main_vec.push_back(pairs[i].second);
	}
	
	//std::vector<int> parterners = main_vec;
	F_Jhonson_sort(main_vec);
	std::vector<int> pend_vec(main_vec.size());
	std::vector<bool> used(pairs.size(),false);

	//align pend_vec with main_vec;
	for(size_t i =0 ; i< main_vec.size(); i++)
	{
		for(size_t j=0; j< pairs.size(); j++)
		{
			if (!used[j] && pairs[j].second == main_vec[i])
			{
				used[j] = true;
				pend_vec[i] = pairs[j].first;
				break;
			}

		}
	}

	main_vec.insert(main_vec.begin() , pend_vec[0]);

	//make_jacobSeq(pend_vec.size());
	std::vector<size_t> insertOrder = jacob_insert_order(pend_vec.size());

	for(size_t i =1; i <insertOrder.size(); ++i)
	{
		size_t index = insertOrder[i];
		// if (sequence.size() == 10)
		// 	std::cout << "index : " <<index << std::endl;
		// std::vector<int>::iterator uppderBound = std::find(main_vec.begin(), main_vec.end(), parterners[index]);
		std::vector<int>::iterator pos = std::lower_bound(main_vec.begin(), main_vec.end(), pend_vec[index]);
		// if (sequence.size() == 10)
		// 	std::cout << pend_vec[index] << ' ';
		main_vec.insert(pos, pend_vec[index]);
	}
	if (has_struggler)
	{
		std::vector<int>::iterator pos = std::lower_bound(main_vec.begin(), main_vec.end(), struggler);
		main_vec.insert(pos,struggler);
	}
	sequence.assign(main_vec.begin(), main_vec.end());


}





// implementation for deque;



std::deque<unsigned long> make_jacobSeqDeq(size_t size)
{
	std::deque<unsigned long> seq;
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

std::deque<size_t> jacob_insert_orderDeq(size_t size)
{
	std::deque<size_t> insertOrder;
	if (size == 0)
		return insertOrder;
	std::deque<unsigned long> jacobSeq = make_jacobSeqDeq(size);
	insertOrder.push_back(0);
	if (size == 1)
		return insertOrder;
	size_t prev = 1;
	for (size_t i =0; i<jacobSeq.size(); ++i)
	{
		size_t current = jacobSeq[i];
		if (current > size)
			current = size -1;
		for(size_t j = current; j>prev; --j)
			insertOrder.push_back(j-1);
		prev = current;
		if (current >= size)
			break;
	}
	for (size_t j=size; j>prev ;--j)
		insertOrder.push_back(j-1);
	return insertOrder;
}

void F_Jhonson_sort_deq(deque_seq& sequence)
{
	std::deque<std::pair<int ,int> > pairs;
	int struggler=0;
	bool has_struggler=false;
	std::deque<int> main_deq;
	std::deque<int> pend_deq;

	if (sequence.size() < 2)
		return ;
	if (sequence.size() %2 != 0)
	{
		struggler = sequence[sequence.size() -1];
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
		pend_deq.push_back(pairs[i].first);
		main_deq.push_back(pairs[i].second);
	}
	std::deque<int> parterners = main_deq;
	F_Jhonson_sort_deq(main_deq);
	main_deq.insert(main_deq.begin() , pend_deq[0]);

	//make_jacobSeq(pend_vec.size());
	std::deque<size_t> insertOrder = jacob_insert_orderDeq(pend_deq.size());

	for(size_t i =1; i <insertOrder.size(); ++i)
	{
		size_t index = insertOrder[i];
		std::deque<int>::iterator uppderBound = std::find(main_deq.begin(), main_deq.end(), parterners[index]);
		std::deque<int>::iterator pos = std::lower_bound(main_deq.begin(), uppderBound, pend_deq[index]);
		main_deq.insert(pos, pend_deq[index]);
	}
	if (has_struggler)
	{
		std::deque<int>::iterator pos = std::lower_bound(main_deq.begin(), main_deq.end(), struggler);
		main_deq.insert(pos,struggler);
	}
	sequence.assign(main_deq.begin(), main_deq.end());


}




double get_time()
{
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return(tv.tv_sec* 1000000.0) +tv.tv_usec;
}
