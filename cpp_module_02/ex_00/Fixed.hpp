#pragma once

#include <iostream>

class Fixed {

	private:
		int _value;

	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(const int raw);
        
};
