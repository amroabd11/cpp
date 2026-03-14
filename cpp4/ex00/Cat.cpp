#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat default constructor called "<<std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called"<<std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignement constructor called"<<std::endl;
	this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called"<<std::endl;
}

void Cat::makeSound()const
{
	std::cout << "Meow!"<<std::endl;
}

