#include "boundingBox.h"

#include <iostream>
#include <algorithm>

using namespace std;

// Constructeurs

BoundingBox::BoundingBox()
{
	cout << "Created empty BoundingBox" << endl;
}

BoundingBox::BoundingBox(float xmin, float xmax, float ymin, float ymax)
: m_xmin(xmin), m_xmax(xmax), m_ymin(ymin), m_ymax(ymax)
{
	cout << "Created new BoundingBox" << endl;
}

// Constructeur de copie

BoundingBox::BoundingBox(const BoundingBox& copy)
: m_xmin(copy.m_xmin), m_xmax(copy.m_xmax), m_ymin(copy.m_ymin), m_ymax(copy.m_ymax)
{
    cout << "Created new copy of a BoundingBox" << endl;
}

// Getters & Setters

float BoundingBox::getXmin()
{
    return m_xmin;
}

float BoundingBox::getXmax()
{
	return m_xmax;
}

float BoundingBox::getYmin()
{
	return m_ymin;
}

float BoundingBox::getYmax()
{
	return m_ymax;
}

void BoundingBox::setXmin(float xmin)
{
	m_xmin = xmin;
}

void BoundingBox::setXmax(float xmax)
{
	m_xmax = xmax;
}

void BoundingBox::setYmin(float ymin)
{
	m_ymin = ymin;
}

void BoundingBox::setYmax(float ymax)
{
	m_ymax = ymax;
}

// Surcharge d'opérateurs

BoundingBox BoundingBox::operator+(const BoundingBox box)
{
    return BoundingBox(min(m_xmin, box.m_xmin), max(m_xmax, box.m_xmax), min(m_ymin, box.m_ymin), max(m_ymax, box.m_ymax));
}

BoundingBox BoundingBox::operator-(const BoundingBox box)
{
    return BoundingBox(*this);
}

BoundingBox BoundingBox::operator^(const BoundingBox box)
{
    return BoundingBox(max(m_xmin, box.m_xmin), min(m_xmax, box.m_xmax), max(m_ymin, box.m_ymin), min(m_ymax, box.m_ymax));
}
