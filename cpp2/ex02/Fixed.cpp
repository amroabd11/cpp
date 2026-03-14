
#include "Fixed.hpp"

Fixed::Fixed()
{
}

Fixed::Fixed(const int value)
{
	this->fixed_nbr = value << this->fract_bits;
}

Fixed::Fixed(const Fixed& co_fix)
{
	*this = co_fix;
}

Fixed::Fixed(const float val)
{
	this->fixed_nbr = roundf(val *(1 << this->fract_bits));
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
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

bool Fixed::operator>(const Fixed& other) const
{
	return (this->fixed_nbr > other.fixed_nbr);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->fixed_nbr < other.fixed_nbr);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->fixed_nbr >= other.fixed_nbr);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->fixed_nbr <= other.fixed_nbr);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->fixed_nbr == other.fixed_nbr);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->fixed_nbr != other.fixed_nbr);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed res;
	res = this->toFloat() * other.toFloat();
	return res; 
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->fixed_nbr + other.fixed_nbr);
	return res;

}
Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->fixed_nbr - other.fixed_nbr);
	return res;
}

Fixed& Fixed::min(Fixed& other1, Fixed& other2)
{
	if(other1 < other2)
		return other1;
	else
		return other2;
}
Fixed& Fixed::max(Fixed& other1, Fixed& other2)
{
	if (other1 < other2)
		return other2;
	else
		return other1;
}

const Fixed& Fixed::min(const Fixed& other1, const Fixed& other2) 
{
	if (other1 < other2)
		return other1;
	else
		return other2;
}

const Fixed& Fixed::max(const Fixed& other1, const Fixed& other2) 
{
	if (other1 > other2)
		return other1;
	else
		return other2;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixed_nbr++;
	return temp;
}

Fixed& Fixed::operator++()
{
	this->fixed_nbr++;
	return *this;
}
Fixed& Fixed::operator--()
{
	this->fixed_nbr--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixed_nbr--;
	return temp;
}



