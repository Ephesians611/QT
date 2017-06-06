// graphics4.h

#ifndef Graphics4_H
#define Graphics4_H

#include <QGLWidget>
#include <gl/GLU.h>
#include <gl/GL.h>
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
   void paintGL();
   void resizeGL(int w, int h);

   void point(GLfloat, GLfloat);
};

#endif
