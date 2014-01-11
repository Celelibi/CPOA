#include "csgTree.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructeurs

CsgTree::CsgTree()
{
    currentID = 0;
}

void CsgTree::addPrimitive(CsgNode* primitive)
{
    ostringstream oss;
    oss << "node" << currentID;
    CsgNode* root = new CsgNode(oss.str(), currentID, NULL);

    currentID++;
    primitive->setParent(root);
    roots.insert(root);
    primitive->setId(currentID);
    currentID++;
    leaves.insert(primitive);

}

void CsgTree::joinPrimitive(CsgNode* primitive1, CsgNode* primitive2, CsgOperation* operation)
{
    operation->setLeft(primitive1);
    operation->setRight(primitive2);

    it = roots.find(primitive1->getParent());
    if(it != roots.end())
    {
        roots.erase(it);
    }

    it = roots.find(primitive2->getParent());
    if(it != roots.end())
    {
        roots.erase(it);
    }

    primitive1->setParent(operation);
    primitive2->setParent(operation);
}

void CsgTree::printTree()
{
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
