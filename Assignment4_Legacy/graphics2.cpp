// graphics2.cpp
// Assignment 4
// Johnny Sloans


#include <QtOpenGL>
#include <math.h>
#include "graphics2.h"

Graphics2::Graphics2(QWidget *parent)
   : QGLWidget(parent)
{
}

Graphics2::~Graphics2()
{
}

//Initialize the GL settings
void Graphics2::initializeGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
   f->glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   f->glClearDepthf(1.0f);
   f->glEnable(GL_DEPTH_TEST);
   f->glDepthFunc(GL_LEQUAL);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void Graphics2::resizeGL( int w, int h )
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
   //algorythm to keep scene "sqare" (preserve aspect ratio)
   //even if screen is streached
   if(w>h)
       f->glViewport((w-h)/2, 0, h, h);
   else
       f->glViewport(0, (h-w)/2, w, w);

   //setup the projection and switch to model view for transformations
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-1, 1, -1, 1, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   //implicit call to paintGL after resized
}

//Paints the GL scene
void Graphics2::paintGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
   f->glClear (GL_COLOR_BUFFER_BIT);
   f->glClear(GL_DEPTH_BUFFER_BIT);

   // point
   glLoadIdentity();
   glColor3f(1, 1, 1);
   glPointSize(2);
   glTranslatef(0.2, 0.5, 0);
   point();

   // line
   glLoadIdentity();
   glColor3f(1, 0.98, 0);
   glLineWidth(4);
   glTranslatef(0.6, 0.5, 0);
   glRotatef(-30.0, 0, 0, 1);
   line();

   // triangle
   glLoadIdentity();
   glColor3f(0.4, 0.16, 00);
   glTranslatef(-0.6, 0, 0);
   glScalef(0.5, 0.5, 1);
   polygon(3);

   // square
   glLoadIdentity();
   glColor3f(0.38, 0.69, 0.87);
   glTranslatef(-0.3, 0.5, 0);
   glScalef(0.5, 0.5, 1);
   glRotatef(45.0, 0, 0, 1);
   polygon(4);

   // pentagon
   glLoadIdentity();
   glColor3f(0.28, 0.77, 0.52);
   glTranslatef(0.6, 0, 0);
   glScalef(0.5, 0.5, 1);
   polygon(5);

   // circle
   glLoadIdentity();
   glColor3f(1, 0.39, 0);
   glTranslatef(0.3, -0.5, 0);
   glScalef(0.5, 0.5, 1);
   polygon(100);

   // elipse
   glLoadIdentity();
   glColor3f(0.68, 0.14, 0.86);
   glTranslatef(-.3, -0.5, 0);
   glRotatef(-45.0, 0, 0, 1);
   glScalef(0.25, 0.5, 1);
   polygon(100);

   // cube
   glLoadIdentity();
   glTranslatef(0, 0, 0);
   glScalef(0.25, 0.25, 0.25);
   glRotatef(45.0, 0, 1, 0);
   glRotatef(30.0, 1, 0, 1);
   cube();

   f->glFlush ();
}

//Function to draw a horizontal line at the center of the current model identity
//with length 1
void Graphics2::line(){
   glBegin(GL_LINES);
       glVertex3f(-0.5, 0, 0);
       glVertex3f(0.5, 0, 0);
   glEnd();
}

//Function to draw a single point at the center of the current model identity
void Graphics2::point(){
   glBegin(GL_POINTS);
       glVertex3f(0, 0, 0);
   glEnd();
}

//Function to draw a N-sided object that is upright (defined to have the bottom edge horizontal)
//at the center of the current model identity, with diameter = 1
void Graphics2::polygon(int n){

   float degree, vertx, verty, rotate, degToRad;

   rotate = 360.0/n;       //Vertex rotation increment
   degree = rotate/2 + 180;//Current degree of vertex (starts rotated to make object upright)
   degToRad = 180/3.14159; //Conversion factor from degrees to radians

   glBegin(GL_POLYGON);

   for(int i = 0; i < n; i++, degree += rotate)
   {
       vertx = 0.5 * sin(degree/degToRad);        //next vertex's x coordinate
       verty = 0.5 * sin((90 - degree)/degToRad); //next vertex's y coordinate
       glVertex3f(vertx, verty, 0);
   }

   glEnd();
}

//Function to draw a colored cube facing forward (defined as front face in positive z)
//at the center of the current model identity with height, width, length = 1
void Graphics2::cube()
{
   float radius = 0.5;
   glBegin(GL_QUADS);
       // Front Face
       glColor3f (0.0, 0.0, 1.0);
       glVertex3f(-radius, -radius,  radius);
       glVertex3f( radius, -radius,  radius);
       glVertex3f( radius,  radius,  radius);
       glVertex3f(-radius,  radius,  radius);
       // Back Face
       glColor3f (1.0, 0.0, 1.0);
       glVertex3f(-radius, -radius, -radius);
       glVertex3f(-radius,  radius, -radius);
       glVertex3f( radius,  radius, -radius);
       glVertex3f( radius, -radius, -radius);
       // Top Face
       glColor3f (0.0, 1.0, 0.0);
       glVertex3f(-radius,  radius,  radius);
       glVertex3f(-radius,  radius, -radius);
       glVertex3f( radius,  radius, -radius);
       glVertex3f( radius,  radius,  radius);
       // Bottom Face
       glColor3f (1.0, 1.0, 0.0);
       glVertex3f(-radius, -radius, -radius);
       glVertex3f( radius, -radius, -radius);
       glVertex3f( radius, -radius,  radius);
       glVertex3f(-radius, -radius,  radius);
       // Right face
       glColor3f (0.0, 1.0, 1.0);
       glVertex3f( radius, -radius,  radius);
       glVertex3f( radius,  radius,  radius);
       glVertex3f( radius,  radius, -radius);
       glVertex3f( radius, -radius, -radius);
       // Left Face
       glColor3f (1.0, 0.0, 0.0);
       glVertex3f(-radius, -radius,  radius);
       glVertex3f(-radius, -radius, -radius);
       glVertex3f(-radius,  radius, -radius);
       glVertex3f(-radius,  radius,  radius);
   glEnd();
}
