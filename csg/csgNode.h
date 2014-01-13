#ifndef CSGNODE_H
#define CSGNODE_H

#include <string>

using namespace std;

class CsgNode
{
private:
	static int m_idcounter;

protected:
	// Attributs
	string m_label;
	const int m_id;
	CsgNode* m_parent;

public:
	// Constructeurs
	CsgNode();
	CsgNode(string, CsgNode*);
	CsgNode(const CsgNode&);
	~CsgNode();

	// Getters & Setters
	string getLabel();
	int getId();
	CsgNode* getParent();

	void setLabel(string);
	void setParent(CsgNode*);
};

#endif // CSGNODE_H
