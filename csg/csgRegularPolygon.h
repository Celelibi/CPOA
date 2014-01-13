#ifndef CSGREGULARPOLYGON_H
#define CSGREGULARPOLYGON_H

#include <string>

#include "csgNode.h"
#include "csgPrimitive.h"
#include "boundingBox.h"
#include "matrix33f.h"
#include "vec3f.h"

class CsgRegularPolygon : public CsgPrimitive
{
protected:
	// Attributs
	int m_nbSommets;
	Vec3f* m_sommets;

public:
	// Constructeurs
	CsgRegularPolygon();
	CsgRegularPolygon(std::string, CsgNode*);
	CsgRegularPolygon(std::string, CsgNode*, Matrix33f, float);
	CsgRegularPolygon(std::string, CsgNode*, Matrix33f, float, int);
	CsgRegularPolygon(const CsgRegularPolygon&);
	virtual ~CsgRegularPolygon();

	// Getters & Setters
	virtual int getNbSommets();
	virtual Vec3f* getSommets();
	virtual void setNbSommets(int);
	virtual void setSommets(Vec3f*);

	virtual BoundingBox getBoundingBox();
};

#endif // CSGREGULARPOLYGON_H
