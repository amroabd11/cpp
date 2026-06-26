#include "Base.hpp"
#include "functions.hpp"

int main(){
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	Base *pt = new Base();
	identify(pt);
}
