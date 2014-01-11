#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

class BoundingBox
{
	private:
	// Attributs
	float m_xmin;
	float m_xmax;
	float m_ymin;
	float m_ymax;
	
	public:
	// Constructeurs
	BoundingBox();
	BoundingBox(float, float, float, float);
	BoundingBox(const BoundingBox&);

	// Getters & Setters
	float getXmin();
	float getXmax();
	float getYmin();
	float getYmax();

	void setXmin(float);
	void setXmax(float);
	void setYmin(float);
	void setYmax(float);

	// Surcharge d'opérateurs 
	BoundingBox operator+(const BoundingBox);  // Opérateur d'union
	BoundingBox operator-(const BoundingBox);  // Opérateur de différence
	BoundingBox operator^(const BoundingBox);  // Opérateur d'intersection
};

#endif // BOUNDINGBOX_H
