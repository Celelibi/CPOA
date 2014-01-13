#ifndef CSGNODE_H
#define CSGNODE_H

#include <string>

class CsgNode
{
private:
	static int m_idcounter;

protected:
	// Attributs
	std::string m_label;
	const int m_id;
	CsgNode* m_parent;

public:
	// Constructeurs
	CsgNode();
	CsgNode(std::string, CsgNode*);
	CsgNode(const CsgNode&);
	~CsgNode();

	// Getters & Setters
	std::string getLabel();
	int getId();
	CsgNode* getParent();

	void setLabel(std::string);
	void setParent(CsgNode*);
};

#endif // CSGNODE_H
