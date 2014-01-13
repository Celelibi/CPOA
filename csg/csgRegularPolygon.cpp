#include "csgRegularPolygon.h"
#include "csgPrimitive.h"
#include "csgNode.h"
#include "matrix33f.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Constructeurs

CsgRegularPolygon::CsgRegularPolygon() : CsgPrimitive()
{
	cout << "Created empty CsgRegularPolygon" << endl;
}

CsgRegularPolygon::CsgRegularPolygon(string label, int id, CsgNode* parent)
: CsgPrimitive(label, id, parent)
{
	cout << "Created CsgRegularPolygon nb" << id << " label " << label << endl;
}

CsgRegularPolygon::CsgRegularPolygon(string label, int id, CsgNode* parent, Matrix33f matrix, float diameter)
: CsgPrimitive(label, id, parent, matrix, diameter)
{
	cout << "Created CsgRegularPolygon nb" << id << " label " << label << endl;
}

CsgRegularPolygon::CsgRegularPolygon(string label, int id, CsgNode* parent, Matrix33f matrix, float diameter, int nbSommets)
: CsgPrimitive(label, id, parent, matrix, diameter), m_nbSommets(nbSommets)
{
	m_sommets = new Vec3f[m_nbSommets];
	cout << "Created CsgRegularPolygon nb" << id << " label " << label << endl;
}

// Constructeur de copie
CsgRegularPolygon::CsgRegularPolygon(const CsgRegularPolygon& copy)
: CsgPrimitive(copy)
{
	cout << "Created CsgRegularPolygon nb" << m_id << " copy of nb"
		<< copy.m_id << " - " << copy.m_label << endl;
}

// Destructeur
CsgRegularPolygon::~CsgRegularPolygon()
{
	if(m_sommets != NULL)
	{
		delete[] m_sommets;
	}
	cout << "Destroyed CsgRegularPolygon nb" << m_id << " label " << m_label << endl;
}

// Getters & Setters
int CsgRegularPolygon::getNbSommets()
{
	return m_nbSommets;
}

Vec3f* CsgRegularPolygon::getSommets()
{
	return m_sommets;
}

void CsgRegularPolygon::setNbSommets(int val)
{
	m_nbSommets = val;
}

void CsgRegularPolygon::setSommets(Vec3f* val)
{
	m_sommets = val;
}
