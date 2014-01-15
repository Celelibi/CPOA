#include "renderImg.h"
#include <QMouseEvent>
#include <iostream>

#include "image2grey.h"
//#include "imgGradient.h"
//#include "boundingbox.h"

#include <limits>


RenderImg::RenderImg( QWidget *parent ):
	QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
	m_texture(0),
	m_widthTex(0),
	m_heightTex(0),
	m_ptrTex(NULL),
	m_drawSobel(false),
	m_BBdraw(false),
	m_img()
  // QQ INIT A AJOUTER ?

{

	// VOTRE CODE ICI

}


void RenderImg::loadTexture(const std::string& filename)
{
	// NOTRE CODE ICI
	size_t size;
	m_img.loadPGMascii(filename);

	if (m_ptrTex != NULL)
		delete m_ptrTex;

	int minw = m_img.getWidth();
	m_heightTex = m_img.getHeight();

	if (minw == 0 && m_heightTex == 0)
		return;

	// Roundup to 4
	m_widthTex = 4 * (minw + 3) / 4;

	size = m_widthTex * m_heightTex;
	if (size / m_heightTex != (size_t)m_widthTex)
		throw "RenderImg: Image too big";

	m_ptrTex = new unsigned char[size];
	memset(m_ptrTex, 0, size * sizeof(*m_ptrTex));
	for (int y = 0; y < m_heightTex; y++)
	{
		// FIXME: ne pas utiliser getPixel, elle est buggué
		for (int x = 0; x < minw; x++)
			m_ptrTex[y * m_widthTex + x] = m_img.getDataPtr()[y * minw + x];
	}

	glInit();
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_widthTex, m_heightTex, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_ptrTex);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDraw();
}



void RenderImg::updateDataTexture()
{
	// VOTRE CODE ICI
	glInit();
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glTexSubImage2D(GL_TEXTURE_2D,0,0,0,m_widthTex, m_heightTex, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_ptrTex);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDraw();
}


void RenderImg::setPixel(int x, int y, unsigned char c)
{
	if (m_widthTex == 0 || m_heightTex == 0)
	{
		m_widthTex = m_winW;
		m_heightTex = m_winH;
		m_widthTex = 4 * (m_widthTex + 3) / 4;
		m_ptrTex = new unsigned char[m_widthTex * m_heightTex];
		clean();
	}

	assert(y >= 0 && y < m_heightTex && x >= 0 && x < m_widthTex);

	m_ptrTex[y * getWidth() + x] = c;
}


Image2grey& RenderImg::getImg()
{
	return m_img;
}


unsigned int RenderImg::getWidth()
{
	if (m_widthTex == 0 || m_heightTex == 0)
		return 4 * (m_winW + 3) / 4;

	return m_widthTex; // RETURN IMAGE WIDTH
}

unsigned int RenderImg::getHeight()
{
	if (m_widthTex == 0 || m_heightTex == 0)
		return m_winH;

	return m_heightTex; // RETURN IMAGE HEIGHT
}

RenderImg::~RenderImg()
{
	glDeleteTextures(1, &m_texture);
	m_texture = 0;
}

void RenderImg::initializeGL()
{
	glClearColor(0.0f,0.0f,0.4f,0.0f);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_widthTex, m_heightTex, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_ptrTex);
	glBindTexture(GL_TEXTURE_2D, 0);


}

void RenderImg::paintGL()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();		// let's go 2D

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex2f( -1,1);
	glTexCoord2f(0,1);
	glVertex2f(-1,-1);
	glTexCoord2f(1,1);
	glVertex2f( 1,-1);
	glTexCoord2f(1,0);
	glVertex2f( 1,1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	// for debugging
	if (m_drawSobel)
		drawSobel();

}

void RenderImg::resizeGL(int width, int height)
{
	m_winW = width;
	m_winH = height;
	int side = qMin(width, height);
	m_winS = side;
	glViewport((width - side) / 2, (height - side) / 2, side, side);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
}

void RenderImg::coordInTexture(QMouseEvent *event, int& x, int& y)
{
	if (m_winS == m_winW)
	{
		x = (float(event->x())/m_winW)*m_widthTex;
		y = (float(event->y()-(m_winH-m_winS)/2)/m_winH)*m_heightTex;
	}
	else
	{
		x = (float(event->x()-(m_winW-m_winS)/2)/m_winH)*m_widthTex;
		y = (float(event->y())/m_winH)*m_heightTex;
	}
}


void RenderImg::mousePressEvent(QMouseEvent *event)
{
	int x,y;
	coordInTexture(event, x, y);
	m_lastPos.setX(x);
	m_lastPos.setY(y);

	std::cout << "PRESS in texture "<< x << " / "<< y << std::endl;

	if (m_state_modifier & Qt::ShiftModifier)
		std::cout << "     with Shift" << std::endl;
	if (m_state_modifier & Qt::ControlModifier)
		std::cout << "     with Ctrl" << std::endl;


	paintGL();

	glPointSize(4.0f);
	glColor3f(1.0f,0,0);
	glBegin(GL_POINTS);

	unsigned int nbp = 0;// VOTRE CODE ICI : nombre de particules
	for (unsigned i = 0; i < nbp; i++ )
	{
		// here get back position of each particle in ptPos
//		glVertex2f(2.0f*ptPos[0]/m_widthTex-1.0f, -2.0f*ptPos[1]/m_heightTex+1.0f);
	}
	glEnd();

	swapBuffers();
}


void RenderImg::mouseReleaseEvent(QMouseEvent *event)
{
//	int x,y;
//	coordInTexture(event, x, y);
//	m_lastPos.setX(x);
//	m_lastPos.setY(y);

//	std::cout << " RELEASE in texture "<< x << " / "<< y << std::endl;

}


void RenderImg::keyPressEvent(QKeyEvent* event)
{
	m_state_modifier = event->modifiers();

	if (event->key() == 'A')	// here 'A' check 'a' pressed (thanks to Qt!)
	{
		std::cout << " touche a enfoncee" << std::endl;
	}

}


void RenderImg::keyReleaseEvent(QKeyEvent* event)
{
	m_state_modifier = 0;
}



void RenderImg::clean()
{
	memset(m_ptrTex, 255, sizeof(*m_ptrTex) * m_widthTex * m_heightTex);
}


void RenderImg::toggleSobel()
{
	m_drawSobel = !m_drawSobel;
	if (m_drawSobel)
	{
		// VOTRE CODE ICI : compute Sobel on image

		updateDataTexture();
	}
}



void RenderImg::drawSobel()
{
	glBegin(GL_LINES);
	for (int j=0; j<m_heightTex; ++j)
	{
		for (int i=0; i<m_widthTex; ++i)
		{
			// get value of gradiant
			// Vec2f v = ??

//			if (v*v > 0.001f)
//			{
//				float x = -1.0f + (2.0f*i)/(m_widthTex-1);
//				float y = 1.0f  - (2.0f*j)/(m_heightTex-1);// minus because of GL is bottom to up and image up to boytom
//				v *= 4.0f/m_widthTex;
//				glColor3f(1.0f,1.0f,0.0f);
//				glVertex2f(x,y);
//				glColor3f(1.0f,0.0f,0.0f);
//				glVertex2f(x+v[0],y-v[1]);
//			}
		}
	}
	glEnd();
}



/*
void RenderImg::drawBB(const BoundingBox& bb)
{
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f,0.5f,0.5f);
//	glVertex2f( xImg2GL(??), yImg2GL(??) );
//	glVertex2f( xImg2GL(??), yImg2GL(??) );
//	glVertex2f( xImg2GL(??), yImg2GL(??) );
//	glVertex2f( xImg2GL(??), yImg2GL(??) );
	glEnd();
}
*/
