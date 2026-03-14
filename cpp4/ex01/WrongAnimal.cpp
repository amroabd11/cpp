#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wrong animal")
{
	std::cout <<"wrong Animal default construtor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "wrong Animal copy constructor called"<<std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "wrong Animal assignement operator called"<< std::endl;
	this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "wrong Animal destructor called"<<std::endl;
}

void	WrongAnimal::makeSound() const
{
		std::cout << "mssg from wrongAnimal"<<std::endl;
}

 std::string WrongAnimal::getType() const
{
	return type;
}
