#ifndef CSGDISK_H
#define CSGDISK_H

#include <string>

#include "csgNode.h"
#include "csgPrimitive.h"
#include "boundingBox.h"
#include "matrix33f.h"

class CsgDisk : public CsgPrimitive
{
public:
	// Constructeurs
	CsgDisk();
	CsgDisk(std::string, CsgNode *);
	CsgDisk(std::string, CsgNode*, Matrix33f);
	CsgDisk(const CsgDisk&);
	virtual ~CsgDisk();

	virtual BoundingBox getBoundingBox();
};

#endif // CSGDISK_H
