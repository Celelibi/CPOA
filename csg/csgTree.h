#ifndef CSGTREE_H
#define CSGTREE_H

#include <iostream>
#include <set>

#include "csgNode.h"
#include "csgOperation.h"
#include "csgPrimitive.h"

class CsgTree
{
private:
	// Attributs
	std::set<CsgNode*> roots;
	std::set<CsgNode*> leaves;

public:
	// Constructeurs
	CsgTree();

	// Autres fonctions
	void addPrimitive(CsgPrimitive*);
	void joinPrimitives(string, CsgOperationType, CsgNode*, CsgNode*);
	void printTree();
};

#endif // CSGTREE_H
