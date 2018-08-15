#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    :QWidget(parent)
{
    this->setWindowTitle("main window");
    b1.setParent(this);
    b1.setText("button");
    b1.move(50,50);
    b2.setParent(this);
    b2.setText("切换到子窗口");
    //w.setWindowTitle("sub Window");
    //w.show();
    w.setBaseSize(40,50);
    connect(&b2,&QPushButton::clicked,this,&MainWidget::changeWin);
    connect(&w,&SubWidget::toMainWin,this,&MainWidget::backWin);
    resize(400,400);
}

void MainWidget::changeWin()
{
    w.show();
    this->hide();
}

void MainWidget::backWin()
{
    this->show();
    w.hide();
}
