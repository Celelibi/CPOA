#ifndef CSGPRIMITIVE_H
#define CSGPRIMITIVE_H

#include "csgNode.h"
#include "matrix33f.h"

class CsgPrimitive : public CsgNode
{
protected:
	// Attributs
	Matrix33f m_matrix;
	float m_diameter;

public:
	// Constructeurs
	CsgPrimitive();
	CsgPrimitive(string, CsgNode*);
	CsgPrimitive(string, CsgNode*, Matrix33f, float);
	CsgPrimitive(const CsgPrimitive&);
	~CsgPrimitive();

	// Getters & Setters
	Matrix33f getMatrix();

	void setMatrix(Matrix33f);
};

#endif // CSGPRIMITIVE_H
