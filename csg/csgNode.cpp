#include <iostream>
#include <string>
#include <cstdlib>

#include "csgNode.h"

using namespace std;

int CsgNode::m_idcounter = 0;

// Constructeurs
CsgNode::CsgNode()
: m_label(""), m_id(m_idcounter++), m_parent(NULL)
{
	cout << "CsgNode: Created empty CsgNode" << endl;
}

CsgNode::CsgNode(string label, const CsgNode* parent)
: m_label(label), m_id(m_idcounter++), m_parent(parent)
{
	cout << "CsgNode: Created CsgNode nb " << m_id;
	cout << " label " << m_label << endl;
}

// Constructeur de copie
CsgNode::CsgNode(const CsgNode& copy)
: m_label(copy.m_label), m_id(m_idcounter++), m_parent(copy.m_parent)
{
	cout << "CsgNode: Created CsgNode nb " << m_id;
	cout << " copy of nb" << copy.m_id << " label " << copy.m_label << endl;
}

// Destructeur
CsgNode::~CsgNode()
{
	cout << "CsgNode: Destroyed CsgNode nb " << m_id;
	cout << " label " << m_label << endl;
}

// Getters & Setters
string CsgNode::getLabel() const
{
	return m_label;
}

int CsgNode::getId() const
{
	return m_id;
}

const CsgNode* CsgNode::getParent() const
{
	return m_parent;
}

void CsgNode::setLabel(string val)
{
	m_label = val;
}

void CsgNode::setParent(const CsgNode* val)
{
	m_parent = val;
}
