#include "Fixed.hpp"

int main(void) {
Fixed a;
Fixed const b(10);
Fixed const c(42.42f);
Fixed const d(b);
a = Fixed(1234.4321f);
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    float n = 12.2985448;
	int stock_bit = 40;
	float fixed_point = std::roundf(n * (1 << stock_bit));
	std::cout << fixed_point / (1 << stock_bit) << std::endl;
	return 0;
}