// graphics3.cpp
// Assignment I4


#include <QtOpenGL>
#include <math.h>
#include "graphics3.h"

Graphics3::Graphics3(QWidget *parent)
   : QGLWidget(parent)
{
   v[0][0]=-0.9;
   v[0][1]=-0.9;
   v[1][0]=0.9;
   v[1][1]=-0.9;
   v[2][0]=0.0;
   v[2][1]=0.9;

   n = 0;

   qsrand(NULL);

   QTimer *timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
   timer->start(1000);
}

Graphics3::~Graphics3()
{
}

//Initialize the GL settings
void Graphics3::initializeGL()
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   glColor3f(1, 0.98, 0);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void Graphics3::resizeGL(int w, int h)
{
   QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
   f->glViewport(0, 0, w, h);
}

//Paints the GL scene
void Graphics3::paintGL()
{
   QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
   f->glClear(GL_COLOR_BUFFER_BIT);
   f->glClear(GL_DEPTH_BUFFER_BIT);

   glBegin(GL_TRIANGLES);
        glLoadIdentity();
       glColor3f(double(qrand() % 100)/100, double(qrand() % 100)/100, double(qrand() % 100)/100);
       divide_triangle(v[0], v[1], v[2], n);
   glEnd();
   f->glFlush();

}

void Graphics3::triangle( GLfloat *a, GLfloat *b, GLfloat *c)
/* display one triangle */
{
   glVertex2fv(a);
   glVertex2fv(b);
   glVertex2fv(c);
}

void Graphics3::divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)
{
/* triangle subdivision using vertex numbers */
   GLfloat v0[2], v1[2], v2[2];
   int j;
   if(m>0)
   {
       for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
       for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
       for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
       divide_triangle(a, v0, v1, m-1);
       divide_triangle(c, v1, v2, m-1);
       divide_triangle(b, v2, v0, m-1);
   }
   else
       (triangle(a,b,c));
/* draw triangle at end of recursion */
}

void Graphics3::animate()
{
   n = (n+1) % 6;
   update();
}
