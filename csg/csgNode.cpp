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
	cout << "Created empty CsgNode" << endl;
}

CsgNode::CsgNode(string label, CsgNode* parent)
: m_label(label), m_id(m_idcounter++), m_parent(parent)
{
	cout << "Created CsgNode nb" << m_id << " label " << m_label << endl;
}

// Constructeur de copie
CsgNode::CsgNode(const CsgNode& copy)
: m_label(copy.m_label), m_id(m_idcounter++), m_parent(copy.m_parent)
{
	cout << "Created CsgNode nb" << m_id << " copy of nb"
		<< copy.m_id << " label " << copy.m_label << endl;
}

// Destructeur
CsgNode::~CsgNode()
{
	cout << "Destroyed CsgNode nb" << m_id << " label " << m_label << endl;
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

CsgNode* CsgNode::getParent() const
{
	return m_parent;
}

void CsgNode::setLabel(string val)
{
	m_label = val;
}

void CsgNode::setParent(CsgNode* val)
{
	m_parent = val;
}
