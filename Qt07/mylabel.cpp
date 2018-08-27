#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i =ev->x();
    int j = ev->y();
    /*
     * QString str = QString("hello %1 split %2 world").arg(Qt).arg("Creator");
     * str = hello Qt split Creator world
    */
    if(ev->button() == Qt::RightButton){
        qDebug()<<"Right";
    }else if(ev->button() == Qt::MiddleButton){
        qDebug()<<"Middle";
    }else{
        QString posMouse = QString("<center><h1>Mouse Press: (%1, %2)</h1></center>").arg(i).arg(j);
        this->setText(posMouse);
    }


}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    int i =ev->x();
    int j = ev->y();
    QString posMouse = QString("<center><h1>Mouse Release: (%1, %2)</h1></center>").arg(i).arg(j);
    this->setText(posMouse);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    int i =ev->x();
    int j = ev->y();
    QString posMouse = QString("<center><h1>Mouse Move: (%1, %2)</h1></center>").arg(i).arg(j);
    //this->setText(posMouse);
}

void MyLabel::enterEvent(QEvent *ev)
{
    QString text = QString("<center><h1>Mouse Enter</h1></center>");
    this->setText(text);
}

void MyLabel::leaveEvent(QEvent *ev)
{
    QString text = QString("<center><h1>Mouse Leave</h1></center>");
    this->setText(text);
}
