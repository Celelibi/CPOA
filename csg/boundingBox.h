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
	virtual float getXmin() const;
	virtual float getXmax() const;
	virtual float getYmin() const;
	virtual float getYmax() const;

	virtual void setXmin(float);
	virtual void setXmax(float);
	virtual void setYmin(float);
	virtual void setYmax(float);

	// Étend la bounding box pour contenir le point
	virtual void addPoint(Vec3f &);
	virtual void addPoint(float, float);

	// Surcharge d'opérateurs
	virtual BoundingBox operator+(const BoundingBox) const;  // Opérateur d'union
	virtual BoundingBox operator-(const BoundingBox) const;  // Opérateur de différence
	virtual BoundingBox operator^(const BoundingBox) const;  // Opérateur d'intersection
};

#endif // BOUNDINGBOX_H
