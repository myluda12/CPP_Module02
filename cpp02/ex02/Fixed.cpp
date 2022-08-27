#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_point = (n << stock_bit)	;
}
Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_point = std::roundf(n * (1 << stock_bit));
}

float Fixed::toFloat(void) const
{
    return ((float)fixed_point / (1 << stock_bit));
}
int Fixed::toInt(void) const
{
    return (fixed_point >> stock_bit);
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return fixed_point;
}

void	Fixed::setRawBits(int raw)
{
    fixed_point = raw;
}


Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->fixed_point = rhs.getRawBits();
	}
	return *this;
}
std::ostream &			operator<<( std::ostream & o, Fixed const & i ) 
{
    o << i.toFloat();
    return o;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	return a.fixed_point < b.fixed_point ? a : b;
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	return a.fixed_point < b.fixed_point ? a : b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	return a.fixed_point > b.fixed_point ? a : b;
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
	return a.fixed_point > b.fixed_point ? a : b;
}

bool Fixed::operator>(Fixed const & f) const
{
	return this->fixed_point > f.fixed_point;
}

bool Fixed::operator<(const Fixed & f) const
{
	return this->fixed_point < f.fixed_point;
}

bool Fixed::operator>=(const Fixed & f) const
{
	return this->getRawBits() >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed & f) const
{
	return this->getRawBits() <= f.getRawBits();
}

bool Fixed::operator==(const Fixed & f) const
{
	return this->getRawBits() == f.getRawBits();;
}

bool Fixed::operator!=(const Fixed & f) const
{
	return !(*this == f);
}

Fixed Fixed::operator+(const Fixed & f) const
{
	return Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed & f) const
{
	return Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed & f) const
{
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed & f) const
{
	if(f.toInt() != 0)
		return Fixed(this->toFloat() / f.toFloat());
	else
	{
		std::cout << "Divison impossible" << std::endl;
		return Fixed(this->toFloat());
	}
}

Fixed & Fixed::operator++()
{
	this->fixed_point++;
	return *this;
}

Fixed & Fixed::operator--()
{
	this->fixed_point--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed f(*this);
	++fixed_point;
	return f;
}

Fixed Fixed::operator--(int)
{
	Fixed f(*this);
	--fixed_point;
	return f;
}
