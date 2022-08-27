#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);     

		Fixed &		operator=( Fixed const & rhs );

	private:
		int fixed_point;
		static const int stock_bit = 8;

};


#endif /* *********************************************************** FIXED_H */