// graphics.h
// Assignment I3
// Farbod Hesaaraki

#ifndef Graphics_H
#define Graphics_H

#include <QOpenGLWidget>
#include <gl/GLU.h>
#include <gl/GL.h>

class Graphics : public QOpenGLWidget
{
   Q_OBJECT

public:
   Graphics(QWidget *parent = 0);
   ~Graphics();

protected:
   void initializeGL();
   void paintGL();
   void resizeGL(int w, int h);

   void point();
   void line();
   void polygon(int n);
   void cube();
};

#endif
