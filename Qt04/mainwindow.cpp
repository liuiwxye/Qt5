#include "mainwindow.h"
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("应用程序");
    this->resize(800,600);

    //菜单栏
    QMenuBar *mBar = menuBar();
    //QMenuBar *mBar = new QMenuBar();
    //mBar->setParent(this);

    //添加菜单
    QMenu *pFile = mBar->addMenu("文件");
    QMenu *pEdit = mBar->addMenu("编辑");


    //添加菜单项，添加动作
    QAction *pnew = pFile->addAction("新建");
    connect(pnew,&QAction::triggered,
            [=](){
                    qDebug()<<QString("新建被按").toUtf8().data();
            }

            );
    pFile->addSeparator(); //添加分割线
    QAction *pOpen = pFile->addAction("打开");


    //工具栏
    QToolBar *toolBar = addToolBar("toolBar"); // 新建一个工具栏

    //工具栏添加快捷键
    toolBar->addAction(pnew);


    QPushButton *b = new QPushButton(this);
    b->setText("^-^");
    //添加小控件
    toolBar->addWidget(b);

    connect(b,&QPushButton::clicked,
            [=](){
                    b->setText("123");
            }

            );


    //状态栏
    QStatusBar *sBar = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("Normal text file");
    sBar->addWidget(label);


    //核心控件
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);



    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    QPushButton *showDock = new QPushButton(this);
    showDock->setText("showDock");
    toolBar->addWidget(showDock);

    //QTextEdit *textEdit1 = new QTextEdit(this);
    //dock->setWidget(textEdit1);


    //添加一个按钮在toolBar中，如果dock被关闭了，用以重新显示
    connect(showDock,&QPushButton::clicked,
            [=](){
                if(dock->close()==true)  //如果dock被关闭了
                {
                    dock->show();  //一个问题是不能悬浮了，怀疑不是一个对象
                }

            }

            );

}

MainWindow::~MainWindow()
{

}
