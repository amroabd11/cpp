
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{

	Zombie *zomObjs = new Zombie[N];
	int i = 0;
	while(i < N)
	{
		zomObjs[i].setName(name);
		//zomObjs[i] = Zombie(name);
		i++;
	}
	return zomObjs;

}
