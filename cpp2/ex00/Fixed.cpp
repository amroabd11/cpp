#include "Fixed.hpp"

Fixed::Fixed(): fixed_nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& co_fix)
{
	std::cout <<"Copy constructor called" <<std::endl;
	this->fixed_nbr = co_fix.getRawBits();	
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called"<<std::endl;
	if (this != &other)
		this->fixed_nbr = other.getRawBits();
	return *this;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout<<"getRawBits member function called" <<std::endl;
	return fixed_nbr;
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_nbr = raw;
}
