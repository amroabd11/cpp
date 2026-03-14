#include "Harl.hpp"

int main(){
	Harl harl;
	std::string level;
	std::cout<< "options: (DEBUG,,INFO,,WARNING,,ERROR)chose one: ";
	std::cin >> level;
	//accessing an element using the object created by the class ;
	harl.complain(level);
}
