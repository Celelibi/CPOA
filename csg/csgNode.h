#ifndef CSGNODE_H
#define CSGNODE_H

#include <string>

using namespace std;

class CsgNode
{
    protected:
    // Attributs
	string m_label;
    int m_id;
    CsgNode* m_parent;
		
    public:
    // Constructeurs
    CsgNode();
    CsgNode(string, int, CsgNode*);
    CsgNode(const CsgNode&);
    ~CsgNode();

    // Getters & Setters
    string getLabel();
    int getId();
    CsgNode* getParent();

    void setLabel(string);
    void setId(int);
    void setParent(CsgNode*);
};

#endif // CSGNODE_H
