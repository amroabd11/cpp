
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout <<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called"<< std::endl;
	this->fixed_nbr = value << this->fract_bits;
}

Fixed::Fixed(const Fixed& co_fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = co_fix;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called"<< std::endl;
	this->fixed_nbr = roundf(val * ( 1 << this->fract_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignement operator called"<<std::endl;
	if (this != &other)
	{
		this->fixed_nbr = other.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits()const
{
	return this->fixed_nbr;
}

void	Fixed::setRawBits(int	const raw)
{
	fixed_nbr = raw;
}

float Fixed::toFloat()const
{
	return (float)fixed_nbr / (1 << fract_bits);
}

int	Fixed::toInt()const
{
	return fixed_nbr >> fract_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& others)
{
	out << others.toFloat();
	return out;
}






