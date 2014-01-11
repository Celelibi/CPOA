#ifndef VEC3F_H
#define VEC3F_H

#include "vector.h"


/**
 * class that manage Vector of 2 floats
 */
class Vec3f: public Vector<3,float>
{
public:
	Vec3f();

	Vec3f(const Vec3f& v);

	Vec3f(const Vector<3,float>& v);

	Vec3f(float x, float y, float z);

	/**
	* dot product
	*/
	float operator *(const Vec3f& v) const;

	/**
	* product by a scalar
	*/ 
	Vec3f  operator*(float f) const;

	/**
	* cross product
	*/
	Vec3f operator^(const Vec3f& v);

 	/**
	* compute norm of vector (length)
	*/
   float norm() const;

};


#endif // VEC3F_H
