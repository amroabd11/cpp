#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename type>
void fun(type &element){
	element--;
}


template <typename tp>
void iter(tp* addr, const size_t  len, void (*fun_ptr)(tp&))
{
	size_t t = 0;
	while(t < len && *addr != '\0') //TODO this works only with strings
	{
		fun_ptr(*addr);
		t++;
		addr++;
	}
}

#endif
