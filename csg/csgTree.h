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
	typedef std::map<int, CsgNode*> id_map_t;

	// Attributs
	std::set<const CsgNode*> m_roots;
	std::set<const CsgNode*> m_leaves;
	id_map_t m_id_map;

	// Méthodes
	void vizuGraphRec(std::ostream& out, const CsgNode *node,
	                  const std::string& indentthis,
	                  const std::string& indentrec) const;

public:
	// Constructeurs
	CsgTree();

	// Autres fonctions
	virtual void addPrimitive(CsgPrimitive*);
	virtual CsgOperation* joinPrimitives(std::string, CsgOperationType,
	                                     CsgNode*, CsgNode*);
	virtual CsgNode* nodeFromId(int) const;
	virtual int idFromNode(const CsgNode *) const;
	virtual std::string asciiArtGraph() const;
	virtual void printTree() const;
	virtual void clear();
	virtual bool intersect(int x, int y) const;
};

#endif // CSGTREE_H
