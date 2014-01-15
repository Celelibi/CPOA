#include <iostream>
#include <string>

#include "csgPrimitive.h"
#include "csgNode.h"
#include "matrix33f.h"

using namespace std;

// Constructeurs
CsgPrimitive::CsgPrimitive() : CsgNode()
{
	m_matrix.setIdentity();
	cout << "CsgPrimitive: Created empty CsgPrimitive" << endl;
}

CsgPrimitive::CsgPrimitive(string label, const CsgNode* parent)
: CsgNode(label, parent)
{
	m_matrix.setIdentity();
	cout << "CsgPrimitive: Created CsgPrimitive nb " << m_id;
	cout << " label " << m_label << endl;
}

CsgPrimitive::CsgPrimitive(string label, const CsgNode* parent, Matrix33f matrix)
: CsgNode(label, parent), m_matrix(matrix)
{
	cout << "CsgPrimitive: Created CsgPrimitive nb " << m_id;
	cout << " label " << m_label << endl;
}

// Constructeur de copie
CsgPrimitive::CsgPrimitive(const CsgPrimitive& copy)
: CsgNode(copy)
{
	cout << "CsgPrimitive: Created CsgPrimitive nb " << m_id << " copy of nb"
		<< copy.m_id << " label " << copy.m_label << endl;
}

// Destructeur
CsgPrimitive::~CsgPrimitive()
{
	cout << "CsgPrimitive: Destroyed CsgPrimitive nb " << m_id;
	cout << " label " << m_label << endl;
}

// Getters & Setters
Matrix33f CsgPrimitive::getMatrix() const
{
	return m_matrix;
}

void CsgPrimitive::setMatrix(Matrix33f val)
{
	m_matrix = val;
}

bool CsgPrimitive::isPrimitive() const
{
	return true;
}
