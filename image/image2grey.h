#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H


#include "image2.h"

class Image2grey: public Image2<unsigned char>
{
public:
	/**
	 * @brief default constructor
	 */
	Image2grey();

	/**
	 * @brief constructor with size
	 * @param w
	 * @param h
	 */
	Image2grey(unsigned int w, unsigned int h);

	/**
	 * @brief constructor with size and fill value
	 * @param w
	 * @param h
	 * @param val
	 */
	Image2grey(unsigned int w, unsigned int h, const unsigned char& val);


	/**
	 * @brief copy constructor
	 * @param img image to copy
	 */
	Image2grey(const Image<2,unsigned char>& img);

	/**
	 * @brief save image in PPM ascii format (work only with unsigned char image)
	 * @param filename
	 * @return true if saving ok
	 */
	bool savePGMascii(const std::string& filename) const;

	/**
	 * @brief load PPM ascii file (work only with unsigned char image)
	 * @param filename
	 * @return true if loading ok
	 */
	bool loadPGMascii(const std::string& filename);

	/**
	 * @brief average image with 3x3 neighbourhood
	 * @return
	 */
	Image2grey average33();

	/**
	 * @brief average
	 * @param n radius in pixel (1 ~ average33)
	 * @return
	 */
	Image2grey average(int n);


	/**
	 * @brief threshold
	 * @param val
	 */
	void threshold(unsigned char val);

	/**
	 * @brief subsample image by 2
	 * @return
	 */
	Image2grey subsample();
};

#endif // IMAGE2GREY_H
