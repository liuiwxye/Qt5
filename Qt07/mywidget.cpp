#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QKeyEvent>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);  //ui只是定义了界面，内容定义在mywidget.ui中(显示给我们看的)，其他所有的如button，dialog等由this指定
    time_id_1_ = this->startTimer(1000);  //ms为单位，每秒
    time_id_2_ = this->startTimer(500);
}

MyWidget::~MyWidget()
{
    delete ui;
}
void MyWidget::keyPressEvent(QKeyEvent *ev)
{
    //qDebug()<<ev->key();
}


void MyWidget::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug()<<ev->key();
}

void MyWidget::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() == time_id_1_){
        static int sec=0;
        ui->label->setText(QString("<center><h1>time_1 out: %1</h1></center>").arg(sec++));
        if(sec==6){
                this->killTimer(this->time_id_1_);
        }
    }else if(ev->timerId() == this->time_id_2_){
        static int sec=0;
         ui->label_2->setText(QString("<center><h1>time out: %1</h1></center>").arg(sec++));
    }
}
