#pragma once
#include <iostream>
// If the function created the object on the stack, it wouldn't return a pointer, because the object would be destroyed as soon as the function returns.
class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name);
    void announce( void );
    ~Zombie();
};


Zombie* newZombie( std::string name );
void    randomChump( std::string name );
