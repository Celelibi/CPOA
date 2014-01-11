#ifndef IMAGE2_H
#define IMAGE2_H

#include "image.h"


template <typename T>
class Image2: public Image<2,T>
{
public:
	/**
	 * @brief default constructor
	 */
	Image2();

	/**
	 * @brief constructor with size
	 * @param w
	 * @param h
	 */
	Image2(unsigned int w, unsigned int h);

	/**
	 * @brief constructor with size and fill value
	 * @param w
	 * @param h
	 * @param val
	 */
	Image2(unsigned int w, unsigned int h, const T& val);


	/**
	 * @brief copy constructor
	 * @param img image to copy
	 */
	Image2(const Image<2,T>& img);

	/**
	 * @brief get the width of image (in pixels)
	 * @return the width
	 */
	unsigned int getWidth() const;

	/**
	 * @brief get the height of image (in pixels)
	 * @return the height
	 */
	unsigned int getHeight() const;


	/**
	 * @brief get pixel
	 * @param x coordinate
	 * @param y coordinate
	 * @return value of pixel
	 */
	T& getPixel(unsigned int x, unsigned int y);

	/**
	 * @brief get pixel value
	 * @param x coordinate
	 * @param y coordinate
	 * @return value of pixel
	 */
	const T& getPixel(unsigned int x, unsigned int y) const;

//	template <typename CMP>
//	void threshold(T val);

};



// typedefs

typedef Image2<char> Image2c;
typedef Image2<unsigned char> Image2uc;
typedef Image2<short> Image2s;
typedef Image2<unsigned short> Image2us;
typedef Image2<int> Image2i;
typedef Image2<unsigned int> Image2ui;

typedef Image2<float> Image2f;
typedef Image2<double> Image2d;


#ifndef NO_TEMPLATE_IMPLEMENTATION
	#include "image2.hpp"
#endif



#endif // IMAGE2_H
