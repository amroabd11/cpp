#include "iter.hpp"

int main()
{
	int a[5] = {1,2,3,4,5};
	iter<int>(a, sizeof(a)/sizeof(a[0]), fun<int>); 
	for (size_t i = 0; i<sizeof(a)/sizeof(a[0]);i++)
		std::cout << a[i]<<std::endl;
		//--------------------------------------
	char s[] = "my crime is of curiosity";
	char * str =s;
	iter<char>(s, sizeof(s), fun<char>); 
	std::cout << str<<std::endl;
}


















