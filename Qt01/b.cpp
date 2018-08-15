#include "a.h"
#include "b.h"
#include <QWidget>
B::B(QWidget *parent):QWidget(parent){
    a.setWindowTitle("sub");
    a.move(50,50);
    a.show();
}
