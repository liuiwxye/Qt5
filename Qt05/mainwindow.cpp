#include "mainwindow.h"
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);

    //菜单栏
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);

    QMenu *pFile = mBar->addMenu("文件");
    QAction *p1 = pFile->addAction("模态对话框");

    connect(p1,&QAction::triggered,
            [=](){
                QDialog dlg;
                dlg.resize(300,300);
                dlg.exec();  //阻塞，函数在这里等待
                qDebug()<<"hello";
            }
            );


    QAction *p2 = pFile->addAction("非模态对话框");
    connect(p2,&QAction::triggered,
            [=](){
                QDialog *dlg = new QDialog(this);
                dlg->show();
                dlg->resize(300,300);

                /*
                 * 这里动态分配，如果多次调用，就会多次分配，所以不是很好的解决办法
                 * QDialog dlg
                 * dlg.show()* error 不会发生阻塞，函数不会等待，直接运行到函数体外，dlg局部对象销毁，所以窗口只会闪一下
                 *更好的一个解决办法是将dlg当作成员变量,这样至始至终只会有一个对话窗口
                 *
                 * 不指定父对象 --->QDialog *dlg = new QDialog();
                 *                dlg->show();
                 *                dlg->setAttribute(Qt::WA_DeleteOnClose); 关闭dlg窗口时就调用析构删除内存空间
                 *
                 */

                qDebug()<<"hello";
            }
            );



    //标准对话框
    QAction *p3 = pFile->addAction("关于对话");

    connect(p3,&QAction::triggered,
            [=](){
                QMessageBox::about(this,"about","hello");

            }
            );

    //

    QAction *p4 = pFile->addAction("问题对话");

    connect(p4,&QAction::triggered,
            [=](){
                int ret = QMessageBox::question(this,"question","hello",
                                                QMessageBox::Yes|
                                                QMessageBox::No|
                                                QMessageBox::Cancel);
                switch(ret){
                    case QMessageBox::Yes:
                        qDebug()<<"Yes";
                        break;
                    case QMessageBox::No:
                        qDebug()<<"No";
                        break;
                    default:
                        break;
                }

            }
            );

    //文件对话框
    QAction *p5 = pFile->addAction("文件对话");

    connect(p5,&QAction::triggered,
            [=](){
                QMessageBox::about(this,"open file","choose");

            }
            );

    connect(p5,&QAction::triggered,
            [=](){
                QString path = QFileDialog::getOpenFileName(
                            this,
                            "open",
                            "../",
                            "Source (*.cpp *.c *.hpp);;Images (*.jpg);;Text (*.txt);;all (*.*)"

                            );
                qDebug()<<path;

            }
            );


}

MainWindow::~MainWindow()
{

}
