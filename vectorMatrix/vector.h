#ifndef VECTOR_H
#define VECTOR_H

#include "array.h"

/**
 * class that manage template Vectors
 */
template< unsigned int N, typename T>
class Vector: public Array<N,T>
{
public:
	/**
	 * @brief Default constructor
	 */
	Vector();

	/**
	 * @brief copy constructor from other type of array/vector (same size)
	 */
	template<typename T2>
	Vector(const Array<N,T2>& vec);

	/**
	 * @brief operator +
	 * @param v
	 * @return
	 */
	Vector operator+(const Vector<N,T>& v) const;

	/**
	 * @brief operator -
	 * @param v
	 * @return
	 */
	Vector operator-(const Vector<N,T>& v) const;

	/**
	 * @brief operator +=
	 * @param v
	 * @return
	 */
	Vector& operator+=(const Vector<N,T>& v);

	/**
	 * @brief operator -=
	 * @param v
	 * @return
	 */
	Vector& operator-=(const Vector<N,T>& v);


	/**
	 * @brief operator *=
	 * @param v
	 * @return
	 */
	Vector& operator*=(const T& val);

	/**
	 * @brief operator *=
	 * @param v
	 * @return
	 */
	Vector& operator/=(const T& val);

	/**
	 * @brief operator *
	 * @param val
	 * @return
	 */
	Vector operator*(const T& val) const;

	/**
	 * @brief operator /
	 * @param val
	 * @return
	 */
	Vector operator/(const T& val) const;

};

template <unsigned int N, typename T>
Vector<N, T> operator*(const T& a, const Vector<N,T>& v);



// typedefs

typedef Vector<2,int> Vec2i;
typedef Vector<3,int> Vec3i;
typedef Vector<4,int> Vec4i;

typedef Vector<2,unsigned int> Vec2ui;
typedef Vector<3,unsigned int> Vec3ui;
typedef Vector<4,unsigned int> Vec4ui;

typedef Vector<4,float> Vec4f;

typedef Vector<2,double> Vec2d;
typedef Vector<3,double> Vec3d;
typedef Vector<4,double> Vec4d;


#ifndef NO_TEMPLATE_IMPLEMENTATION
	#include "vector.hpp"
#endif


#endif // VECTOR_H
