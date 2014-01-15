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
	int m_nbVertices;
	Vec3f* m_vertices;

	void genVertices();

public:
	// Constructeurs
	CsgRegularPolygon();
	CsgRegularPolygon(std::string, const CsgNode*);
	CsgRegularPolygon(std::string, const CsgNode*, Matrix33f);
	CsgRegularPolygon(std::string, const CsgNode*, Matrix33f, int);
	CsgRegularPolygon(const CsgRegularPolygon&);
	virtual ~CsgRegularPolygon();

	// Getters & Setters
	virtual int getNbVertices() const;
	virtual const Vec3f* getVertices() const;
	virtual void setNbVertices(int);

	virtual BoundingBox getBoundingBox() const;
	virtual bool intersect(int x, int y) const;
};

#endif // CSGREGULARPOLYGON_H
