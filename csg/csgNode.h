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
	virtual ~CsgNode();

	// Getters & Setters
	virtual std::string getLabel();
	virtual int getId();
	virtual CsgNode* getParent();

	virtual void setLabel(std::string);
	virtual void setParent(CsgNode*);

	virtual bool isPrimitive() = 0;
	virtual BoundingBox getBoundingBox() = 0;
};

#endif // CSGNODE_H
