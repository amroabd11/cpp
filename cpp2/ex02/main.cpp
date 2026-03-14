//#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	a = Fixed(0);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const j( Fixed( 10.1016f) / Fixed( 2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << j << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
