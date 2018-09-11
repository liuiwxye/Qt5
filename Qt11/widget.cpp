#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QBuffer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    write_data();
//    read_data();
//    write_text();
//    read_text();
    QBuffer mem_file;
    mem_file.open(QIODevice::WriteOnly);
    mem_file.write("文件");
    qDebug()<<QString(mem_file.buffer()).toUtf8().data();
    mem_file.close();


//    mem_file.open(QIODevice::WriteOnly);
//    QDataStream stream;
//    stream.setDevice(&mem_file);
//    stream<<QString("Hello");
//    mem_file.close();
//    qDebug()<<mem_file.buffer();

//    mem_file.open(QIODevice::ReadOnly);
//    QDataStream sss;
//    sss.setDevice(&mem_file);
//    QString str;
//    int a;
//    sss>>str>>a;
//    mem_file.close();
//    qDebug()<<str.toUtf8().data()<<a;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::write_data()
{
    QFile file("../test.txt");
    //打开文件，只写
    if(file.open(QIODevice::WriteOnly)){
        //创建数据流,关联file
        QDataStream stream(&file);
        stream<<QString("文件编辑构建")<<12342342343;
        file.close();
    }
}

void Widget::read_data()
{
    QFile file("../test.txt");
    if(file.open(QIODevice::ReadOnly)){
        QDataStream stream(&file);
        QString str;
        int a;
        stream>>str>>a;
        file.close();
        qDebug()<<str<<a;
    }
}

void Widget::write_text()
{
    QFile file;
    file.setFileName("../demo.txt");
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        //指定编码 可选
        //stream.setCodec("UTF-8");
        stream<<QString("文本")<<666;
        file.close();
    }
}


void Widget::read_text()
{
    QFile file;
    file.setFileName("../demo.txt");
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        //stream.setCodec("UTF-8");
        QString str;
        int a;
        stream>>str>>a;
//        qDebug()中QString 的字符有双引号，C++的string没有
//        QString s("hello");
//        const char *p="world";
        qDebug()<<str.toUtf8().data()<<a;


        file.close();
    }
}


void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../");
    if(!path.isEmpty()){
        QFile file;
        file.setFileName(path);
        if(file.open(QIODevice::ReadOnly)){
            QTextStream stream(&file);
            QString str = stream.readAll();
            ui->textEdit->setText(str);
        }
    }
}
