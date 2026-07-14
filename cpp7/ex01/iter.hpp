#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>


template <typename tp, typename tp2>
void iter(tp* addr, const size_t  len, void (*fun_ptr)(tp2&))
{
	if (!addr || !fun_ptr)
		return;
	size_t t = 0;
	while(t < len)
	{
		fun_ptr(addr[t]);
		t++;
	}
}

#endif
