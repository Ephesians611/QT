// graphics.h
// Assignment I4
// Johnny Sloans


#ifndef Graphics_H
#define Graphics_H

#include <QGLWidget>

class Graphics : public QGLWidget
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
