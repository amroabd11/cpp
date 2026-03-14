
#include "Zombie.hpp"

//Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie *zmb = zombieHorde(10, "3mro");
	zmb[9].announce();
	delete[] zmb;
}
