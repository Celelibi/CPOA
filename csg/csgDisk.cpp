#include "csgDisk.h"
#include "csgPrimitive.h"
#include "csgNode.h"
#include "matrix33f.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Constructeurs

CsgDisk::CsgDisk() : CsgPrimitive()
{
	cout << "Created empty CsgDisk" << endl;
}

CsgDisk::CsgDisk(string label, int id, CsgNode* parent)
: CsgPrimitive(label, id, parent)
{
	cout << "Created CsgDisk nb" << id << " label " << label << endl;
}

CsgDisk::CsgDisk(string label, int id, CsgNode* parent, Matrix33f matrix, float diameter)
: CsgPrimitive(label, id, parent, matrix, diameter)
{
	cout << "Created CsgDisk nb" << id << " label " << label << endl;
}

CsgDisk::CsgDisk(string label, int id, CsgNode* parent, Matrix33f matrix, float diameter, float x, float y)
: CsgPrimitive(label, id, parent, matrix, diameter), m_center(x, y, 1)
{
	cout << "Created CsgDisk nb" << id << " label " << label << endl;
}

// Constructeur de copie
	CsgDisk::CsgDisk(const CsgDisk& copy)
: CsgPrimitive(copy)
{
	cout << "Created CsgDisk nb" << m_id << " copy of nb"
		<< copy.m_id << " label " << copy.m_label << endl;
}

// Destructeur
CsgDisk::~CsgDisk()
{
	cout << "Destroyed CsgDisk nb" << m_id << " label " << m_label << endl;
}
