#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class MainWidget:public QWidget{

    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    void changeWin();
    void backWin();

private:
    QPushButton b1;
    QPushButton b2;
    SubWidget w;
};

#endif // MAINWIDGET_H
