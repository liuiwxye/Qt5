#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include <QPainter>
#include <QBitmap>
#include <QDebug>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *ev)
{
    //QPainter p(this);
    //p.drawPixmap(0,0,QPixmap("../beach.jpg"));
    //p.drawPixmap(0,0,QBitmap("../beach.jpg"));
    //QPainter p(this);

    /*
    //绘图设备QPixmap
    QPixmap pixmap(400,300);
    QPainter p(&pixmap);
    p.fillRect(0,0,500,350,QBrush(Qt::yellow));
    p.drawPixmap(0,0,QPixmap("../face.png"));
    pixmap.save("../pix.jpg");
    */

    /*
    //Qimage
    QImage image(400,300,QImage::Format_ARGB32);
    QPainter p;
    p.begin(&image);
    p.drawImage(0,0,QImage("../face.png"));

    for(int i =0;i<50;i++)
        for(int j =0;j<50;j++){
            image.setPixel(QPoint(i,j),qRgb(0,255,0));

        }
    auto t =image.pixel(QPoint(50,50));
    qDebug()<<typeid(t).name()<<hex<<t;
    p.end();
    image.save("../imagesave.jpg");
    */

    //QPicture
    QPicture picture;
    QPainter p;
    p.begin(&picture);
    p.drawPixmap(0,0,80,80,QPixmap("../face.png"));
    p.drawLine(50,50,150,50);


    p.end();
    picture.save("../picturesave.png");
    QPicture pic;
    pic.load("../picturesave.png");
    QPainter p1(this);
    p1.drawPicture(0,0,pic);
}
