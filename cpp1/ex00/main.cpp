#include "Zombie.hpp"
//Zombie *newZombie(std::string name);
int main()
{
	
	Zombie zomb("3mro");
	zomb.announce();
	Zombie *zob = newZombie("hamo");
	(*zob).announce();
}

