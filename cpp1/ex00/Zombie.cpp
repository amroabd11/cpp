#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    Zombie::name = name;
}

Zombie::~Zombie()
{
    std::cout << "bruuuuhhh " << name << " die"<<std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
