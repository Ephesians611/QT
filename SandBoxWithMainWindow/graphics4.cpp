// graphics4.cpp
// Assignment I4
// Johnny Sloans


#include <QtOpenGL>
#include <math.h>
#include "graphics.h"
#include "graphics4.h"


Graphics4::Graphics4(QWidget *parent)
   : QGLWidget(parent)
{

}

Graphics4::~Graphics4()
{
}

//Initialize the GL settings
void Graphics4::initializeGL()
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   //gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
   gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
   glMatrixMode(GL_MODELVIEW);
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void Graphics4::resizeGL(int w, int h)
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
   f->glViewport(0, 0, w, h);
}

//Paints the GL scene
void Graphics4::paintGL()
{
   QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
   f->glClear (GL_COLOR_BUFFER_BIT);
   f->glClear(GL_DEPTH_BUFFER_BIT);

   // point
   glLoadIdentity();
   //glColor3f(1, 0.98, 0);
   glColor3f(1, 1, 1);
   glPointSize(4);

   int n = d;
   if (n != 0)
   {
       GLfloat stepX, stepY;

       glTranslatef(0, 0.5, 0);

       for (int i = 0; i < n; i++)
       {
           stepX += 0.1;
           stepY = (a + (b*stepX) + pow(c*stepX,2));
           point(stepX, stepY);
       }
   }

   f->glFlush();

}

//Function to draw a single point
void Graphics4::point(GLfloat x, GLfloat y){
  glBegin(GL_POINTS);
     glVertex3f(x, y, 0);
   glEnd();
}

