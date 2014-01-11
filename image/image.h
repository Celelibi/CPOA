#ifndef _IMAGE_H
#define _IMAGE_H

#include "array.h"

template<unsigned int N, typename T>
class Image
{
protected:
	/// images pixel (voxel)
	T* m_data;

	/// sizes of images
	Array<N,unsigned int> m_size;

	/// size of subdimension for easy accessor []
	Array<N,unsigned int> m_subDimSz;

	/// total size in number of elements in image
	unsigned int m_totalSz;

	/**
	 * @brief compute image size in number of elements
	 * @param sizes array of size (for each dimension)
	 */
	void computeImageSize(const Array<N,unsigned int>& sizes);

	/**
	 * @brief compute image size in number of elements
	 * @param size (same) size for all dimension
	 */
	void computeImageSize(unsigned int size);


public:
	/**
	 * @brief Constructor for empty image
	 */
	Image();

	/**
	 * @brief Destructor
	 */
	~Image();

	/**
	 * @brief Constructor with sizes
	 * @param size
	 */
	Image(const Array<N,unsigned int>& sizes);

	/**
	 * @brief Constructor with sizes and value
	 * @param size
	 * @param val value used to fill the image
	 */
	Image(const Array<N,unsigned int>& size, const T& val);

	/**
	 * @brief Constructor with one size for all dimension
	 * @param size
	 */
	Image(unsigned int size);

	/**
	 * @brief Constructor with one size for all dimension and value
	 * @param size
	 * @param val value used to fill the image
	 */
	Image(unsigned int size, const T& val);

	/**
	 * @brief Copy constructor
	 * @param img image to copy
	 */
	Image(const Image<N,T>& img);

	/**
	 * @brief affectation operator
	 * @param img image to copt
	 * @return ref on current object
	 */
	Image<N,T>& operator=(const Image<N,T>& img);

	/**
	 * @brief swap
	 * @param img
	 */
	void swap(Image<N,T>& img);


	/**
	 * @brief operator [] for access to elements
	 * @param pos position in the image
	 * @return const ref to the value of element
	 */
	const T& operator[](const Array<N,unsigned int>& pos) const;

	/**
	 * @brief operator [] for access to elements
	 * @param pos position in the image
	 * @return ref to the value of element
	 */
	T& operator[](const Array<N,unsigned int>& pos);

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
	 * @brief operator == test perfect equality of image
	 * @param img
	 * @return
	 */
	bool operator==(const Image<N,T>& img);

};

#ifndef NO_TEMPLATE_IMPLEMENTATION
	#include "image.hpp"
#endif

#endif // IMAGE_H
