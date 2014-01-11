#ifndef VEC2F_H
#define VEC2F_H

#include "vector.h"


/**
 * class that manage Vector of 2 floats
 */
class Vec2f: public Vector<2,float>
{
public:
	Vec2f();

	Vec2f(const Vec2f& v);

	Vec2f(const Vector<2,float>& v);

	Vec2f(float x, float y);

	/**
	* dot product
	*/
	float operator*(const Vec2f& v) const;

	/**
	* product by a scalar
	*/ 
	Vec2f operator*(float f) const;

	/**
	* cross product
	*/
	float operator^(const Vec2f& v) const;

 	/**
	* compute norm of vector (length)
	*/
   float norm() const;
};

#endif
