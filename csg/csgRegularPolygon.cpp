#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "csgRegularPolygon.h"
#include "csgPrimitive.h"
#include "csgNode.h"
#include "matrix33f.h"
#include "vec3f.h"

using namespace std;

// Constructeurs

CsgRegularPolygon::CsgRegularPolygon()
: CsgPrimitive(), m_nbSommets(0), m_sommets(NULL)
{
	cout << "Created empty CsgRegularPolygon" << endl;
}

CsgRegularPolygon::CsgRegularPolygon(string label, CsgNode* parent)
: CsgPrimitive(label, parent), m_nbSommets(0), m_sommets(NULL)
{
	cout << "Created CsgRegularPolygon nb" << m_id;
	cout << " label " << m_label << endl;
}

CsgRegularPolygon::CsgRegularPolygon(string label, CsgNode* parent, Matrix33f matrix, float diameter)
: CsgPrimitive(label, parent, matrix, diameter), m_nbSommets(0), m_sommets(NULL)
{
	cout << "Created CsgRegularPolygon nb" << m_id;
	cout << " label " << m_label << endl;
}

CsgRegularPolygon::CsgRegularPolygon(string label, CsgNode* parent, Matrix33f matrix, float diameter, int nbSommets)
: CsgPrimitive(label, parent, matrix, diameter), m_nbSommets(nbSommets), m_sommets(NULL)
{
	genSommets();
	cout << "Created CsgRegularPolygon nb" << m_id;
	cout << " label " << m_label << endl;
}

// Constructeur de copie
CsgRegularPolygon::CsgRegularPolygon(const CsgRegularPolygon& copy)
: CsgPrimitive(copy), m_nbSommets(copy.m_nbSommets), m_sommets(NULL)
{
	m_sommets = new Vec3f[m_nbSommets];
	for (int i = 0; i < m_nbSommets; i++)
		m_sommets[i] = copy.m_sommets[i];

	cout << "Created CsgRegularPolygon nb" << m_id << " copy of nb"
		<< copy.m_id << " - " << copy.m_label << endl;
}

// Destructeur
CsgRegularPolygon::~CsgRegularPolygon()
{
	if(m_sommets != NULL)
		delete[] m_sommets;

	cout << "Destroyed CsgRegularPolygon nb" << m_id << " label " << m_label << endl;
}

// Getters & Setters
int CsgRegularPolygon::getNbSommets()
{
	return m_nbSommets;
}

const Vec3f* CsgRegularPolygon::getSommets()
{
	return m_sommets;
}

void CsgRegularPolygon::setNbSommets(int val)
{
	m_nbSommets = val;
	genSommets();
}

BoundingBox CsgRegularPolygon::getBoundingBox()
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

// Autres méthodes
void CsgRegularPolygon::genSommets()
{
	if (m_sommets != NULL)
		delete[] m_sommets;

	// Pas de points pour moins de 3 sommets
	if (m_nbSommets < 3)
	{
		m_sommets = NULL;
		return;
	}

	m_sommets = new Vec3f[m_nbSommets];
	for (int i = 0; i < m_nbSommets; i++)
	{
		float a = i * 2 * M_PI / m_nbSommets;
		m_sommets[i] = Vec3f(cos(a) / 2, sin(a) / 2, 1);
	}
}
