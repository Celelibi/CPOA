#ifndef _ARRAY_H
#define _ARRAY_H
#include <iostream>
#include <cassert>


/**
 * class that manage template array of N elements of type T
 */
template< unsigned int N, typename T>
class Array
{
protected:
	/// data storage
	T m_data[N];
public:

	static const unsigned int SIZE = N;

	/**
	 * @brief constructor
	 */
	Array();

	/**
	 * @brief constructor with filling value
	 * @param val value to used for filling
	 */
	Array(const T& val);

	/**
	 * @brief constructor with on value for each element
	 * @param v0
	 * @param v1
	 */
	Array(const T& v0, const T& v1);


	/**
	 * @brief constructor with on value for each element
	 * @param v0
	 * @param v1
	 * @param v2
	 */
	Array(const T& v0, const T& v1, const T& v2);

	/**
	 * @brief constructor with on value for each element
	 * @param v0
	 * @param v1
	 * @param v2
	 * @param v3
	 */
	Array(const T& v0, const T& v1, const T& v2, const T& v3);


	/**
	 * @brief copy constructor
	 * @param val array to copy
	 */
	Array(const Array<N,T>& ar);

	/**
	 * @brief copy constructor
	 * @param val array to copy
	 */
	template<typename T2>
	Array(const Array<N,T2>& ar);

	/**
	 * @brief affectation operator
	 * @param ar arrray to affect
	 * @return reference to current object
	 */
	Array<N,T>& operator=(const Array<N,T>& ar);

	/**
	 * @brief operator []
	 * @return a ref to object value
	 */
	T& operator[](unsigned int);

	/**
	 * @brief const operator []
	 * @param index index of value to acces in the array
	 * @return a const ref to object value
	 */
	const T& operator[](unsigned int index) const;

	/**
	 * @brief get pointer on data
	 * @return the pointer
	 */
	T* getDataPtr();

	/**
	 * @brief get const pointer on data
	 * @return the pointer
	 */
	const T* getDataPtr() const;


	/**
	 * @brief equality testing operator
	 * @param ar array to test
	 * @return
	 */
	bool operator==(const Array<N,T>& ar) const;

	bool operator!=(const Array<N,T>& ar) const;

	/**
	 * @brief swap values between arrays
	 * @param ar
	 */
	void swap(Array<N,T>& ar);


	/**
	 * declare flow operators as friend
	 */
	template <unsigned int M, typename TT>
	friend std::ostream& operator<<(std::ostream& out, const Array<M,TT>& ar) ;

	template <unsigned int M, typename TT>
	friend std::istream& operator>>(std::istream& in, Array<M,TT	>& ar) ;
};


// typedef


typedef Array<2,char> Array2c;
typedef Array<3,char> Array3c;
typedef Array<4,char> Array4c;

typedef Array<2,unsigned char> Array2uc;
typedef Array<3,unsigned char> Array3uc;
typedef Array<4,unsigned char> Array4uc;

typedef Array<2,int> Array2i;
typedef Array<3,int> Array3i;
typedef Array<4,int> Array4i;

typedef Array<2,unsigned int> Array2ui;
typedef Array<3,unsigned int> Array3ui;
typedef Array<4,unsigned int> Array4ui;

typedef Array<2,float> Array2f;
typedef Array<3,float> Array3f;
typedef Array<4,float> Array4f;

typedef Array<2,double> Array2d;
typedef Array<3,double> Array3d;
typedef Array<4,double> Array4d;


#ifndef NO_TEMPLATE_IMPLEMENTATION
	#include "array.hpp"
#endif


#endif // _ARRAY_H
