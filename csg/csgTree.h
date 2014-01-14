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
	std::set<CsgNode*> m_roots;
	std::set<CsgNode*> m_leaves;
	label_map_t m_label_map;

	// Méthodes
	int vizuGraphRec(std::ostream& out, CsgNode *node, int prof,
	                 bool right, const std::string& interligne);

public:
	// Constructeurs
	CsgTree();

	// Autres fonctions
	virtual void addPrimitive(CsgPrimitive*);
	virtual void joinPrimitives(std::string, CsgOperationType,
	                            CsgNode*, CsgNode*);
	virtual CsgNode* nodeFromLabel(std::string);
	virtual std::string labelFromNode(CsgNode*);
	virtual std::string asciiArtGraph();
	virtual void printTree();
};

#endif // CSGTREE_H
