#include <math.h>

#ifndef VEC2D
#define VEC2D

class vec2d
{
	public:
		float x;
		float y;
		double length();
		vec2d operator-(const vec2d& rhs);	
};


#endif
