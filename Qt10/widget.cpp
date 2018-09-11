#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QDataStream>

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

void Widget::on_pushButton_clicked()
{

}

void Widget::on_buttonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../","(*.txt *.csv)");
    if(!path.isEmpty()){
        //文件对象
        QFile file(path);
        //打开文件
        if(file.open(QIODevice::ReadOnly)){
#if 0
            //读文件
            QByteArray arr = file.readAll();
            ui->textEdit->setText(arr);
            file.close();
#endif
            QByteArray arr;
            while(!file.atEnd()){
                arr.append(file.readLine());
            }
            ui->textEdit->setText(arr);
            file.close();

            //获取文件信息
            QFileInfo info(path);
            qDebug()<<info.fileName()<<info.suffix()<<info.size()<<info.created().toString("yyyy-MM-dd hh-mm-ss");
        }
    }
}

void Widget::on_buttonWrite_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"save","../","TXT (*.txt);;C++ (*.cpp)");
    if(!path.isEmpty()){
        QFile file;
        file.setFileName(path);
        if(file.open(QIODevice::WriteOnly)){
            //获取编辑区内容
            QString str=ui->textEdit->toPlainText();
            //写文件
            //file.write(str.toUtf8());
            file.write(str.toStdString().data());
            file.close();
        }
    }
}
