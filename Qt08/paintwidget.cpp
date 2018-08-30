#include "paintwidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QPen>

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800,600);
    this->setWindowTitle("Paint Demo");
    x=0;
    button = new QPushButton(this);
    button->move(600,500);
    button->setText("Button");
    connect(button,&QPushButton::clicked,this,&PaintWidget::on_pushButton_clicked);
}

PaintWidget::~PaintWidget()
{

}

void PaintWidget::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPen pen;
    //painter.drawPixmap(0,0,width(),height(),QPixmap("../wall.jpg"));
    //same as  painter.drawPixmap(rect(),QPixmap("../wall.jpg"));
    painter.drawLine(80, 100, 650, 500);
    painter.drawRect(10, 10, 100, 400);
    painter.drawLine(110,0,110,410);
    painter.setPen(QPen(Qt::green, 5));
    painter.setBrush(Qt::blue);
    painter.drawEllipse(50, 150, 400, 200);
    painter.drawPixmap(x,200,30,30,QPixmap("../.qt8/face.png"));
}

void PaintWidget::on_pushButton_clicked()
{
    x+=30;
    if(x>this->width()){
        x=0;
    }
    //update
    //update();
    update(0,200,width(),30);

}
