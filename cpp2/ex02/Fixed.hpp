#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixed_nbr;
		static const int fract_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& co_fix);
		Fixed &operator=(const Fixed& other);
		Fixed(const int);
		Fixed(const float);
		~Fixed();
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		//Fixed &operator<<(const Fixed& left, const Fixed& r);
		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		Fixed operator++(int);
		Fixed &operator++();
		Fixed operator--(int);
		Fixed &operator--();
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream& operator<<(std::ostream&, const Fixed&);

