#include <iostream>
#include <algorithm>

#include "vec3f.h"
#include "boundingBox.h"

using namespace std;

// Constructeurs

BoundingBox::BoundingBox()
: m_xmin(0), m_xmax(0), m_ymin(0), m_ymax(0), m_empty(true)
{
	cout << "Created empty BoundingBox" << endl;
}

BoundingBox::BoundingBox(float xmin, float xmax, float ymin, float ymax)
: m_xmin(xmin), m_xmax(xmax), m_ymin(ymin), m_ymax(ymax), m_empty(false)
{
	cout << "Created new BoundingBox" << endl;
}

// Constructeur de copie

BoundingBox::BoundingBox(const BoundingBox& copy)
: m_xmin(copy.m_xmin), m_xmax(copy.m_xmax),
  m_ymin(copy.m_ymin), m_ymax(copy.m_ymax),
  m_empty(copy.m_empty)
{
	cout << "Created new copy of a BoundingBox" << endl;
}

// Getters & Setters

float BoundingBox::getXmin() const
{
	return m_xmin;
}

float BoundingBox::getXmax() const
{
	return m_xmax;
}

float BoundingBox::getYmin() const
{
	return m_ymin;
}

float BoundingBox::getYmax() const
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

void BoundingBox::addPoint(Vec3f &v)
{
	addPoint(v[0], v[1]);
}

void BoundingBox::addPoint(float x, float y)
{
	if (m_empty)
	{
		m_xmin = m_xmax = x;
		m_ymin = m_ymax = y;
		m_empty = false;
	}
	else
	{
		m_xmin = min(m_xmin, x);
		m_xmax = max(m_xmax, x);
		m_ymin = min(m_ymin, y);
		m_ymax = max(m_ymax, y);
	}
}

// Surcharge d'opérateurs

BoundingBox BoundingBox::operator+(const BoundingBox box) const
{
	return BoundingBox(min(m_xmin, box.m_xmin), max(m_xmax, box.m_xmax),
	                   min(m_ymin, box.m_ymin), max(m_ymax, box.m_ymax));
}

BoundingBox BoundingBox::operator-(const BoundingBox box) const
{
	return BoundingBox(*this);
}

BoundingBox BoundingBox::operator^(const BoundingBox box) const
{
	return BoundingBox(max(m_xmin, box.m_xmin), min(m_xmax, box.m_xmax),
	                   max(m_ymin, box.m_ymin), min(m_ymax, box.m_ymax));
}
