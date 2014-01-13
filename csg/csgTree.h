#ifndef CSGTREE_H
#define CSGTREE_H

#include <iostream>
#include <string>
#include <set>
#include <map>

#include "csgNode.h"
#include "csgOperation.h"
#include "csgPrimitive.h"

class CsgTree
{
private:
	// Types
	typedef std::map<std::string, CsgNode*> label_map_t;

	// Attributs
	std::set<CsgNode*> roots;
	std::set<CsgNode*> leaves;
	label_map_t label_map;

public:
	// Constructeurs
	CsgTree();

	// Autres fonctions
	void addPrimitive(CsgPrimitive*);
	void joinPrimitives(std::string, CsgOperationType, CsgNode*, CsgNode*);
	CsgNode* nodeFromLabel(std::string);
	std::string labelFromNode(CsgNode*);
	void printTree();
};

#endif // CSGTREE_H
