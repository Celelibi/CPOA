#include <iostream>
#include <string>

#include "csgPrimitive.h"
#include "csgNode.h"
#include "matrix33f.h"

using namespace std;

// Constructeurs
CsgPrimitive::CsgPrimitive() : CsgNode()
{
	cout << "Created empty CsgPrimitive" << endl;
}

CsgPrimitive::CsgPrimitive(string label, CsgNode* parent)
: CsgNode(label, parent)
{
	cout << "Created CsgPrimitive nb" << m_id;
	cout << " label " << m_label << endl;
}

CsgPrimitive::CsgPrimitive(string label, CsgNode* parent, Matrix33f matrix, float diameter)
: CsgNode(label, parent), m_matrix(matrix), m_diameter(diameter)
{
	cout << "Created CsgPrimitive nb" << m_id;
	cout << " label " << m_label << endl;
}

// Constructeur de copie
CsgPrimitive::CsgPrimitive(const CsgPrimitive& copy)
: CsgNode(copy)
{
	cout << "Created CsgPrimitive nb" << m_id << " copy of nb"
		<< copy.m_id << " label " << copy.m_label << endl;
}

// Destructeur
CsgPrimitive::~CsgPrimitive()
{
	cout << "Destroyed CsgPrimitive nb" << m_id << " label " << m_label << endl;
}

// Getters & Setters
Matrix33f CsgPrimitive::getMatrix()
{
	return m_matrix;
}

void CsgPrimitive::setMatrix(Matrix33f val)
{
	m_matrix = val;
}
