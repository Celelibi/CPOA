#ifndef IMGGRADIENT_H
#define IMGGRADIENT_H

#include "image2grey.h"
#include "image2rgb.h"
#include "image2.h"
#include "vec2f.h"


class GradientSobel
{
protected:

	static const int Sobel5x[25];

	static const int Sobel5y[25];

public:

	static Image2<Vec2f> gradient33(const Image2grey& img_in);

	static Image2<Vec2f> gradient55(const Image2grey& img_in);

	static Image2rgb gradientToRGB(const Image2<Vec2f>& grad);
};



#endif // IMGGRADIENT_H
