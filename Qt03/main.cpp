#include <QApplication>
#include <QWidget>
#include <QDebug>
#include "mainwidget.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWidget w;
    w.show();
    //qDebug()<<QString("hello,中国").toUtf8().data()<<endl;

    return app.exec();
}
