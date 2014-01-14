#include <iostream>
#include <string>

#include "csgOperation.h"
#include "boundingBox.h"
#include "csgNode.h"

using namespace std;

// Constructeurs
CsgOperation::CsgOperation() : CsgNode()
{
	cout << "Created empty CsgOperation" << endl;
}

CsgOperation::CsgOperation(string label, const CsgNode* parent)
: CsgNode(label, parent)
{
	cout << "Created CsgOperation nb" << m_id;
	cout << " label " << m_label << endl;
}

CsgOperation::CsgOperation(string label, const CsgNode* parent,
                           CsgOperationType type, const CsgNode* left,
                           const CsgNode* right)
: CsgNode(label, parent), m_type(type), m_left(left), m_right(right)
{
	cout << "Created CsgOperation nb" << m_id;
	cout << " label " << m_label << endl;
}

// Constructeur de copie
CsgOperation::CsgOperation(const CsgOperation& copy)
: CsgNode(copy)
{
	cout << "Created CsgOperation nb" << m_id << " copy of nb"
		<< copy.m_id << " label " << copy.m_label << endl;
}

// Destructeur
CsgOperation::~CsgOperation()
{
	cout << "Destroyed CsgOperation nb" << m_id << " label " << m_label << endl;
}

// Getters & Setters

CsgOperationType CsgOperation::getType() const
{
	return m_type;
}

const CsgNode* CsgOperation::getLeft() const
{
	return m_left;
}

const CsgNode* CsgOperation::getRight() const
{
	return m_right;
}

void CsgOperation::setType(CsgOperationType val)
{
	m_type = val;
}

void CsgOperation::setLeft(const CsgNode* val)
{
	m_left = val;
}

void CsgOperation::setRight(const CsgNode* val)
{
	m_right = val;
}

bool CsgOperation::isPrimitive() const
{
	return false;
}

BoundingBox CsgOperation::getBoundingBox() const
{
	switch (m_type)
	{
	case INTERSECT:
		return m_left->getBoundingBox() ^ m_right->getBoundingBox();
		break;
	case UNION:
		return m_left->getBoundingBox() + m_right->getBoundingBox();
		break;
	case DIFF:
		return m_left->getBoundingBox() - m_right->getBoundingBox();
		break;
	default:
		throw "WTF is this operation type?";
	}
}
