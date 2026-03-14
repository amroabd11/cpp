#pragma once

#include <iostream>

class Fixed
{
	private:
		int	fixed_nbr;
		static const int fract_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& co_fix);
		Fixed &operator=(const Fixed& other);
		~Fixed();
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};
