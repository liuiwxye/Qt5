#include "mainwidget.h"
#include <QDebug>

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
    //connect(&w,p1,this,&MainWidget::backWin);
    //void (SubWidget::*p1)()=&SubWidget::toMainWin;


    QPushButton *b4 = new QPushButton(this);
    b4->setText("Lambda表达");
    b4->move(200,300);


    connect(b4,&QPushButton::released,
            [&](){
                    //b4->setText("123");
                    qDebug()<<"hello";
                }
            );
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
