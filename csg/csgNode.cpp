#include "csgNode.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Constructeurs
CsgNode::CsgNode()
: m_label(""), m_id(0), m_parent(NULL)
{
    cout << "Created empty CsgNode" << endl;
}

CsgNode::CsgNode(string label, int id, CsgNode* parent)
: m_label(label), m_id(id), m_parent(parent)
{
    cout << "Created CsgNode nb" << id << " label " << label << endl;
}

// Constructeur de copie
CsgNode::CsgNode(const CsgNode& copy)
: m_label(copy.m_label), m_id(copy.m_id + 1), m_parent(copy.m_parent)
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
string CsgNode::getLabel()
{
    return m_label;
}

int	CsgNode::getId()
{
    return m_id;
}

CsgNode* CsgNode::getParent()
{
    return m_parent;
}

void CsgNode::setLabel(string val)
{
    m_label = val;
}

void CsgNode::setId(int val)
{
    m_id = val;
}

void CsgNode::setParent(CsgNode* val)
{
    m_parent = val;
}
