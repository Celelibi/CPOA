#ifndef CSGREGULARPOLYGON_H
#define CSGREGULARPOLYGON_H

#include "csgNode.h"
#include "csgPrimitive.h"
#include "matrix33f.h"
#include "vec3f.h"

#include <string>

class CsgRegularPolygon : public CsgPrimitive
{
protected:
	// Attributs
	int m_nbSommets;
	Vec3f* m_sommets;

public:
	// Constructeurs
	CsgRegularPolygon();
	CsgRegularPolygon(string, int, CsgNode*);
	CsgRegularPolygon(string, int, CsgNode*, Matrix33f, float);
	CsgRegularPolygon(string, int, CsgNode*, Matrix33f, float, int);
	CsgRegularPolygon(const CsgRegularPolygon&);
	~CsgRegularPolygon();

	// Getters & Setters
	int getNbSommets();
	Vec3f* getSommets();
	void setNbSommets(int);
	void setSommets(Vec3f*);
};

#endif // CSGREGULARPOLYGON_H
