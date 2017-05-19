// graphics.cpp
// Assignment I4
// Farbod Hesaaraki

#include <QtGui>
#include <math.h>
#include "graphics.h"

Graphics::Graphics(QWidget *parent)
   : QOpenGLWidget(parent)
{
    frequency = 1;
    amplitude = 0.6;
}

Graphics::~Graphics()
{
}

//Initialize the GL settings
void Graphics::initializeGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
   f->glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   //glClearDepth(1.0f);
   f->glEnable(GL_DEPTH_TEST);
   f->glDepthFunc(GL_LEQUAL);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void Graphics::resizeGL(int w, int h)
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glViewport(0, 0, w, h);


//   //setup the projection and switch to model view for transformations
//   glMatrixMode(GL_PROJECTION);
//   glLoadIdentity();
//   glOrtho(-1, 1, -1, 1, -1, 1);
//   glMatrixMode(GL_MODELVIEW);
//   glLoadIdentity();

   //implicit call to paintGL after resized
}

//Paints the GL scene
void Graphics::paintGL()
{
//   glClear (GL_COLOR_BUFFER_BIT);
//   glClear(GL_DEPTH_BUFFER_BIT);

//   glLoadIdentity();
//   glColor3f(0, 1, 0);
//   glLineWidth(2);
//   glTranslatef(-1, 0, 0);
//   glRotatef(0, 0, 0, 1);
//   signal();

//   glFlush ();
}

//Function to draw the signal
void Graphics::signal(){
//   glBegin(GL_LINE_STRIP);
       for (float x = 0; x <= 5; x += 0.1){
           //glVertex3f(0.5 * x, amplitude * sin(2 * 3.14 * frequency * x), 0);
       }
//   glEnd();
}


