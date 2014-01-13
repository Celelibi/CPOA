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
: CsgPrimitive(), m_nbVertices(0), m_vertices(NULL)
{
	cout << "Created empty CsgRegularPolygon" << endl;
}

CsgRegularPolygon::CsgRegularPolygon(string label, CsgNode* parent)
: CsgPrimitive(label, parent), m_nbVertices(0), m_vertices(NULL)
{
	cout << "Created CsgRegularPolygon nb" << m_id;
	cout << " label " << m_label << endl;
}

CsgRegularPolygon::CsgRegularPolygon(string label, CsgNode* parent, Matrix33f matrix, float diameter)
: CsgPrimitive(label, parent, matrix, diameter), m_nbVertices(0), m_vertices(NULL)
{
	cout << "Created CsgRegularPolygon nb" << m_id;
	cout << " label " << m_label << endl;
}

CsgRegularPolygon::CsgRegularPolygon(string label, CsgNode* parent, Matrix33f matrix, float diameter, int nbVertices)
: CsgPrimitive(label, parent, matrix, diameter), m_nbVertices(nbVertices), m_vertices(NULL)
{
	genVertices();
	cout << "Created CsgRegularPolygon nb" << m_id;
	cout << " label " << m_label << endl;
}

// Constructeur de copie
CsgRegularPolygon::CsgRegularPolygon(const CsgRegularPolygon& copy)
: CsgPrimitive(copy), m_nbVertices(copy.m_nbVertices), m_vertices(NULL)
{
	m_vertices = new Vec3f[m_nbVertices];
	for (int i = 0; i < m_nbVertices; i++)
		m_vertices[i] = copy.m_vertices[i];

	cout << "Created CsgRegularPolygon nb" << m_id << " copy of nb"
		<< copy.m_id << " - " << copy.m_label << endl;
}

// Destructeur
CsgRegularPolygon::~CsgRegularPolygon()
{
	if(m_vertices != NULL)
		delete[] m_vertices;

	cout << "Destroyed CsgRegularPolygon nb" << m_id << " label " << m_label << endl;
}

// Getters & Setters
int CsgRegularPolygon::getNbVertices()
{
	return m_nbVertices;
}

const Vec3f* CsgRegularPolygon::getVertices()
{
	return m_vertices;
}

void CsgRegularPolygon::setNbVertices(int val)
{
	m_nbVertices = val;
	genVertices();
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
void CsgRegularPolygon::genVertices()
{
	if (m_vertices != NULL)
		delete[] m_vertices;

	// Pas de points pour moins de 3 vertices
	if (m_nbVertices < 3)
	{
		m_vertices = NULL;
		return;
	}

	m_vertices = new Vec3f[m_nbVertices];
	for (int i = 0; i < m_nbVertices; i++)
	{
		float a = i * 2 * M_PI / m_nbVertices;
		m_vertices[i] = Vec3f(cos(a) / 2, sin(a) / 2, 1);
	}
}
