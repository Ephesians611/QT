// graphics2.h
// Assignment I4


#ifndef Graphics2_H
#define Graphics2_H

#include <QtGui>

class Graphics2 : public QWidget
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
