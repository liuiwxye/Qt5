#ifndef B_H
#define B_H
#include "a.h"
#include <QWidget>

class B:public QWidget{
public:
    B(QWidget *parent=0 );
private:
    A a;
};


#endif // B_H
