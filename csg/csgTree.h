#ifndef CSGTREE_H
#define CSGTREE_H

#include "csgNode.h"
#include "csgOperation.h"
#include "csgPrimitive.h"

#include <iostream>
#include <set>

class CsgTree
{
    private:
    // Attributs
    std::set<CsgNode*> roots;
    std::set<CsgNode*> leaves;
    std::set<CsgNode*>::iterator it;
    int currentID;

    public:
    // Constructeurs
    CsgTree();

    // Autres fonctions
    void addPrimitive(CsgNode*);
    void joinPrimitive(CsgNode*, CsgNode*, CsgOperation*);
    void printTree();
};

#endif // CSGTREE_H