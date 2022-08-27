#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>


class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);     
        Fixed(const int n);
        Fixed(const float n);
        float toFloat(void) const;
        int toInt(void) const;

		Fixed &		operator=( Fixed const & rhs );

	private:
		int fixed_point;
		static const int stock_bit = 8;

};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif 