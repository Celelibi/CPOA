#ifndef CSGNODE_H
#define CSGNODE_H

#include <string>

#include "boundingBox.h"

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

	virtual BoundingBox getBoundingBox() = 0;
};

#endif // CSGNODE_H
