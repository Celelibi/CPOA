#include <iostream>
#include <sstream>
#include <string>

#include "csgNode.h"
#include "csgOperation.h"
#include "csgPrimitive.h"
#include "csgTree.h"

using namespace std;

// Constructeurs

CsgTree::CsgTree()
{
}

void CsgTree::addPrimitive(CsgPrimitive* primitive)
{
	int id = primitive->getId();

	primitive->setParent(NULL);
	m_leaves.insert(primitive);

	if (nodeFromId(id) != NULL)
		throw "A node with this name already exists";
	else
		m_id_map[id] = primitive;
}

CsgOperation* CsgTree::joinPrimitives(string label, CsgOperationType optype,
                                      CsgNode* node1, CsgNode* node2)
{
	CsgOperation *operation;

	operation = new CsgOperation(label, NULL, optype, node1, node2);

	m_id_map[operation->getId()] = operation;

	node1->setParent(operation);
	node2->setParent(operation);

	// erase ne fait rien s'il l'élément n'existe pas.
	m_roots.erase(node1);
	m_roots.erase(node2);
	m_leaves.erase(node1);
	m_leaves.erase(node2);

	m_roots.insert(operation);
	return operation;
}

CsgNode* CsgTree::nodeFromId(int id) const
{
	id_map_t::const_iterator it;
	it = m_id_map.find(id);

	if (it == m_id_map.end())
		return NULL;
	else
		return it->second;
}

int CsgTree::idFromNode(const CsgNode* node) const
{
	return node->getId();
}

int CsgTree::vizuGraphRec(ostream& out, const CsgNode *node, int prof,
		bool right, const string& interligne) const
{
	int lprof;
	int rprof;

	if (node == NULL)
	{
		if (right)
			out << interligne << endl;
		else
			out << endl;
		return 0;
	}

	if (right)
		for (int i = 0; i < prof; ++i)
			out << "          ";

	out << " --> " << node->getLabel();

	if (!node->isPrimitive())
	{
		const CsgOperation *op = dynamic_cast<const CsgOperation *>(node);
		lprof = vizuGraphRec(out, op->getLeft(), prof + 1, false,
					 interligne + "|         ");
		rprof = vizuGraphRec(out, op->getRight(), prof + 1, true,
					 interligne + "          ");
	}
	else
	{
		lprof = vizuGraphRec(out, NULL, prof + 1, false,
					 interligne + "|         ");
		rprof = vizuGraphRec(out, NULL, prof + 1, true,
					 interligne + "          ");
	}

	return max(lprof, rprof);
}

string CsgTree::asciiArtGraph() const
{
	set<const CsgNode *>::const_iterator it;
	stringstream ss;

	for (it = m_roots.begin(); it != m_roots.end(); ++it)
		vizuGraphRec(ss, *it, 0, false, "");

	return ss.str();
}

void CsgTree::printTree() const
{
	std::set<const CsgNode*>::const_iterator it;

	for(it = m_roots.begin() ; it != m_roots.end() ; it++)
	{
		cout << "Racine" << endl << "label : " << (*it)->getLabel() << endl << "id : " << (*it)->getId() << endl;
		if((*it)->getParent() != NULL){
			cout << "Parent : " << (*it)->getParent()->getId() << endl;
		}
		cout << endl;
	}
	for(it = m_leaves.begin() ; it != m_leaves.end() ; it++)
	{
		cout << "Feuille" << endl << "label : " << (*it)->getLabel() << endl << "id : " << (*it)->getId() << endl;
		if((*it)->getParent() != NULL){
			cout << "Parent : " << (*it)->getParent()->getId() << endl;
		}
		cout << endl;
	}
}
