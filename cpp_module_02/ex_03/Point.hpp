#include "Fixed.hpp"

class Point {

private:
    const Fixed _x;
    const Fixed _y;

public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point&);
    ~Point(void);

    Point& operator=(const Point& other);

    const Fixed& getX(void) const;
    const Fixed& getY(void) const;        
}
