#include <iostream>
#include <string>
#include <cstdlib>

#include "csgDisk.h"
#include "csgPrimitive.h"
#include "csgNode.h"
#include "matrix33f.h"
#include "vec2f.h"

using namespace std;

// Constructeurs

CsgDisk::CsgDisk() : CsgPrimitive()
{
	cout << "Created empty CsgDisk" << endl;
}

CsgDisk::CsgDisk(string label, CsgNode* parent)
: CsgPrimitive(label, parent)
{
	cout << "Created CsgDisk nb" << m_id << " label " << m_label << endl;
}

CsgDisk::CsgDisk(string label, CsgNode* parent, Matrix33f matrix, float diameter)
: CsgPrimitive(label, parent, matrix, diameter)
{
	cout << "Created CsgDisk nb" << m_id << " label " << m_label << endl;
}

CsgDisk::CsgDisk(string label, CsgNode* parent, Matrix33f matrix, float diameter, float x, float y)
: CsgPrimitive(label, parent, matrix, diameter), m_center(x, y, 1)
{
	cout << "Created CsgDisk nb" << m_id << " label " << m_label << endl;
}

// Constructeur de copie
	CsgDisk::CsgDisk(const CsgDisk& copy)
: CsgPrimitive(copy)
{
	cout << "Created CsgDisk nb" << m_id << " copy of nb ";
	cout << copy.m_id << " label " << copy.m_label << endl;
}

// Destructeur
CsgDisk::~CsgDisk()
{
	cout << "Destroyed CsgDisk nb" << m_id << " label " << m_label << endl;
}

BoundingBox CsgDisk::getBoundingBox()
{
	BoundingBox ret;
	Matrix33f mat = getMatrix();
	Vec3f v;

	v = mat * Vec3f(-0.5, -0.5, 1);
	ret.addPoint(v);
	v = mat * Vec3f(-0.5, +0.5, 1);
	ret.addPoint(v);
	v = mat * Vec3f(+0.5, -0.5, 1);
	ret.addPoint(v);
	v = mat * Vec3f(+0.5, +0.5, 1);
	ret.addPoint(v);

	return ret;
}
