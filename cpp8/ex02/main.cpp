#include "MutantStack.hpp"
#include <vector>
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "---------------------------\n";
	std::vector<int> a(2,5);
	std::deque<int> b(10);
	b.insert(b.begin(),9);
//	a.insert(a.begin(),1);
//	a.insert(a.begin(),1);
//	a.insert(a.begin(),1);
//	for(std::vector<int>::iterator it = a.begin(); it <a.end(); it++)
//		std::cout << *it<<"\n";
	std::cout << a.capacity()<<std::endl;
	std::cout << b.size()<<std::endl;
	return 0;
}
