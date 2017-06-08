// graphics2.h
// Assignment 4
// Johnny Sloans


#ifndef Graphics2_H
#define Graphics2_H

#include <QGLWidget>

class Graphics2 : public QGLWidget
{
   Q_OBJECT

public:
   Graphics2(QWidget *parent = 0);
   ~Graphics2();

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
