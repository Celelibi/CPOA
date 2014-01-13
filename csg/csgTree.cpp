#include <iostream>
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
	string label(primitive->getLabel());
	primitive->setParent(NULL);
	leaves.insert(primitive);

	if (nodeFromLabel(label) != NULL)
		throw "A node with this name already exists";
	else
		label_map[label] = primitive;
}

void CsgTree::joinPrimitives(string label, CsgOperationType optype,
                             CsgNode* node1, CsgNode* node2)
{
	CsgOperation *operation;

	operation = new CsgOperation(label, NULL, optype, node1, node2);

	if (nodeFromLabel(label) != NULL)
		throw "A node with this name already exists";
	else
		label_map[label] = operation;

	node1->setParent(operation);
	node2->setParent(operation);

	// erase ne fait rien s'il l'élément n'existe pas.
	roots.erase(node1);
	roots.erase(node2);
	leaves.erase(node1);
	leaves.erase(node2);

	roots.insert(operation);
}

CsgNode* CsgTree::nodeFromLabel(string label)
{
	label_map_t::iterator it;
	it = label_map.find(label);

	if (it == label_map.end())
		return NULL;
	else
		return it->second;
}

string CsgTree::labelFromNode(CsgNode* node)
{
	return node->getLabel();
}

void CsgTree::printTree()
{
	std::set<CsgNode*>::iterator it;

	for(it = roots.begin() ; it != roots.end() ; it++)
	{
		cout << "Racine" << endl << "label : " << (*it)->getLabel() << endl << "id : " << (*it)->getId() << endl;
		if((*it)->getParent() != NULL){
			cout << "Parent : " << (*it)->getParent()->getId() << endl;
		}
		cout << endl;
	}
	for(it = leaves.begin() ; it != leaves.end() ; it++)
	{
		cout << "Feuille" << endl << "label : " << (*it)->getLabel() << endl << "id : " << (*it)->getId() << endl;
		if((*it)->getParent() != NULL){
			cout << "Parent : " << (*it)->getParent()->getId() << endl;
		}
		cout << endl;
	}
}
