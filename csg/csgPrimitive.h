#ifndef CSGPRIMITIVE_H
#define CSGPRIMITIVE_H

#include <string>

#include "csgNode.h"
#include "boundingBox.h"
#include "matrix33f.h"

class CsgPrimitive : public CsgNode
{
protected:
	// Attributs
	Matrix33f m_matrix;

public:
	// Constructeurs
	CsgPrimitive();
	CsgPrimitive(std::string, CsgNode*);
	CsgPrimitive(std::string, CsgNode*, Matrix33f);
	CsgPrimitive(const CsgPrimitive&);
	virtual ~CsgPrimitive();

	// Getters & Setters
	virtual Matrix33f getMatrix();

	virtual void setMatrix(Matrix33f);
};

#endif // CSGPRIMITIVE_H
