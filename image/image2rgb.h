#ifndef IMAGE2RGB_H
#define IMAGE2RGB_H

#include "image2.h"

class Image2rgb: public Image2<Array3uc>
{
public:
	/**
	 * @brief default constructor
	 */
	Image2rgb();

	/**
	 * @brief constructor with size
	 * @param w
	 * @param h
	 */
	Image2rgb(unsigned int w, unsigned int h);

	/**
	 * @brief constructor with size and fill value
	 * @param w
	 * @param h
	 * @param val
	 */
	Image2rgb(unsigned int w, unsigned int h, const Array3uc& val);


	/**
	 * @brief copy constructor
	 * @param img image to copy
	 */
	Image2rgb(const Image<2,Array3uc>& img);

	/**
	 * @brief save image in PPM ascii format (work only with Array3uc image)
	 * @param filename
	 * @return true if saving ok
	 */
	bool savePPMascii(const std::string& filename) const;

	/**
	 * @brief load PPM ascii file (work only with Array3uc image)
	 * @param filename
	 * @return true if loading ok
	 */
	bool loadPPMascii(const std::string& filename);

	/**
	 * @brief average image with 3x3 neighbourhood
	 * @return
	 */
	Image2rgb average33();

	/**
	* @brief subsample image by 2
	* @return
	*/
   Image2rgb subsample();

};

#endif // IMAGE2RGB_H
