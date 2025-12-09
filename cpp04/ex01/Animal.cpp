#include "Animal.hpp"

Animal::Animal() : type("animal")
{
	std::cout <<"Animal default construtor called"<<std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called"<<std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignement operator called"<< std::endl;
	this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called"<<std::endl;
}

void	Animal::makeSound() const
{
		std::cout << "animals sound"<<std::endl;
}

 std::string Animal::getType() const
{
	return type;
}
