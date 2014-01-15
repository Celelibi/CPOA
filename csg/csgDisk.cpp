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
	cout << "CsgDisk: Created empty CsgDisk" << endl;
}

CsgDisk::CsgDisk(string label, const CsgNode* parent)
: CsgPrimitive(label, parent)
{
	cout << "CsgDisk: Created CsgDisk nb " << m_id;
	cout << " label " << m_label << endl;
}

CsgDisk::CsgDisk(string label, const CsgNode* parent, Matrix33f matrix)
: CsgPrimitive(label, parent, matrix)
{
	cout << "CsgDisk: Created CsgDisk nb " << m_id;
	cout << " label " << m_label << endl;
}

// Constructeur de copie
	CsgDisk::CsgDisk(const CsgDisk& copy)
: CsgPrimitive(copy)
{
	cout << "CsgDisk: Created CsgDisk nb " << m_id << " copy of nb ";
	cout << copy.m_id << " label " << copy.m_label << endl;
}

// Destructeur
CsgDisk::~CsgDisk()
{
	cout << "CsgDisk: Destroyed CsgDisk nb " << m_id;
	cout << " label " << m_label << endl;
}

BoundingBox CsgDisk::getBoundingBox() const
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
