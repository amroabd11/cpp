#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "Base.hpp"

Base * generate(void){
	std::srand(std::time(NULL));
	int rand = std::rand() % 3;

	if (rand == 0)
		return new A();
	else if (rand == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (Base* a = dynamic_cast<A *>(p))
		std::cout <<"type of object is A"<<std::endl;
	else if (Base* a = dynamic_cast<B *>(p))
		std::cout <<"type of object is B"<<std::endl;
	else if (Base* a = dynamic_cast<C *>(p))
		std::cout <<"type of object is C"<<std::endl;
	else
		std::cout << "none of the available object types"<<std::endl;
}
void identify(Base &p)
{
	try{
		Base& a=dynamic_cast<A&>(p);
		std::cout <<"type of reference is A"<<std::endl;
		(void)a;
		return ;
	}
	catch (...)
	{
		try{
			Base& a=dynamic_cast<B&>(p);
			std::cout << "type of reference is B"<<std::endl;
			(void)a;
			return;
		}
		catch (...)
		{
			try{
				Base &a = dynamic_cast<C&>(p);
				std::cout <<"type of reference is C"<<std::endl;
				(void)a;
				return;
			}
			catch(...){}
		}

	}

}

#endif
