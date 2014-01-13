#ifndef CSGDISK_H
#define CSGDISK_H

#include <string>

#include "csgNode.h"
#include "csgPrimitive.h"
#include "matrix33f.h"
#include "vec3f.h"

class CsgDisk : public CsgPrimitive
{
private:
	// Attributs
	Vec3f m_center;

public:
	// Constructeurs
	CsgDisk();
	CsgDisk(std::string, CsgNode *);
	CsgDisk(std::string, CsgNode*, Matrix33f, float);
	CsgDisk(std::string, CsgNode *, Matrix33f, float, float, float);
	CsgDisk(const CsgDisk&);
	~CsgDisk();
};

#endif // CSGDISK_H
