#ifndef CSGOPERATION_H
#define CSGOPERATION_H

#include <string>

#include "csgNode.h"
#include "boundingBox.h"

enum CsgOperationType { INTERSECT, UNION, DIFF };

class CsgOperation : public CsgNode
{
protected:
	// Attributs
	CsgOperationType m_type;
	CsgNode* m_left;
	CsgNode* m_right;

public:
	// Constructeurs
	CsgOperation();
	CsgOperation(std::string, CsgNode*);
	CsgOperation(std::string, CsgNode*, CsgOperationType, CsgNode*,
	             CsgNode*);
	CsgOperation(const CsgOperation&);
	virtual ~CsgOperation();

	// Getters & Setters
	virtual CsgOperationType getType();
	virtual CsgNode* getLeft();
	virtual CsgNode* getRight();

	virtual void setType(CsgOperationType);
	virtual void setLeft(CsgNode*);
	virtual void setRight(CsgNode*);

	virtual BoundingBox getBoundingBox();
};

#endif // CSGOPERATION_H
