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
	const CsgNode* m_left;
	const CsgNode* m_right;

public:
	// Constructeurs
	CsgOperation();
	CsgOperation(std::string, const CsgNode*);
	CsgOperation(std::string, const CsgNode*, CsgOperationType,
	             const CsgNode*, const CsgNode*);
	CsgOperation(const CsgOperation&);
	virtual ~CsgOperation();

	// Getters & Setters
	virtual CsgOperationType getType() const;
	virtual const CsgNode* getLeft() const;
	virtual const CsgNode* getRight() const;

	virtual void setType(CsgOperationType);
	virtual void setLeft(const CsgNode*);
	virtual void setRight(const CsgNode*);

	virtual bool isPrimitive() const;
	virtual BoundingBox getBoundingBox() const;
};

#endif // CSGOPERATION_H
