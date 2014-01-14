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
	typedef std::map<int, const CsgNode*> id_map_t;

	// Attributs
	std::set<const CsgNode*> m_roots;
	std::set<const CsgNode*> m_leaves;
	id_map_t m_id_map;

	// Méthodes
	int vizuGraphRec(std::ostream& out, const CsgNode *node, int prof,
	                 bool right, const std::string& interligne) const;

public:
	// Constructeurs
	CsgTree();

	// Autres fonctions
	virtual void addPrimitive(CsgPrimitive*);
	virtual void joinPrimitives(std::string, CsgOperationType,
	                            CsgNode*, CsgNode*);
	virtual const CsgNode* nodeFromId(int) const;
	virtual int idFromNode(const CsgNode *) const;
	virtual std::string asciiArtGraph() const;
	virtual void printTree() const;
};

#endif // CSGTREE_H
