#ifndef CSGOPERATION_H
#define CSGOPERATION_H

#include "csgNode.h"

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
	CsgOperation(string, CsgNode*);
	CsgOperation(string, CsgNode*, CsgOperationType, CsgNode*, CsgNode*);
	CsgOperation(const CsgOperation&);

	// Getters & Setters
	CsgOperationType getType();
	CsgNode* getLeft();
	CsgNode* getRight();

	void setType(CsgOperationType);
	void setLeft(CsgNode*);
	void setRight(CsgNode*);
};

#endif // CSGOPERATION_H
