#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "vec3f.h"


class BoundingBox
{
private:
	// Attributs
	float m_xmin;
	float m_xmax;
	float m_ymin;
	float m_ymax;
	bool m_empty;

public:
	// Constructeurs
	BoundingBox();
	BoundingBox(float, float, float, float);
	BoundingBox(const BoundingBox&);

	// Getters & Setters
	float getXmin();
	float getXmax();
	float getYmin();
	float getYmax();

	void setXmin(float);
	void setXmax(float);
	void setYmin(float);
	void setYmax(float);

	// Étend la bounding box pour contenir le point
	void addPoint(Vec3f &);
	void addPoint(float, float);

	// Surcharge d'opérateurs
	BoundingBox operator+(const BoundingBox);  // Opérateur d'union
	BoundingBox operator-(const BoundingBox);  // Opérateur de différence
	BoundingBox operator^(const BoundingBox);  // Opérateur d'intersection
};

#endif // BOUNDINGBOX_H
