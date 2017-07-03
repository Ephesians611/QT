// graphics4.h
// Johnny Sloans

#ifndef Graphics4_H
#define Graphics4_H

#include <QGLWidget>
#include <gl/GLU.h>
#include <gl/GL.h>
#include "mainwindow.h"
/* initial triangle */


class Graphics4 : public QGLWidget
{
   Q_OBJECT

public:
   Graphics4(QWidget *parent = 0);
   ~Graphics4();
   QStringList info;
   QStringList numbers;

protected:
   void initializeGL();
   void paintGL(int a, int b, int c, int d);
   void resizeGL(int w, int h);

   void point(GLfloat, GLfloat);
};

#endif
