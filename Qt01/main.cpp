#include <QApplication>
//#include <QWidget>
#include "b.h"


/*ʵ�������������ڣ�һ������һ���ǰ�����ϵ*/
//class A:public QWidget{
//public:
//    A(QWidget *parent=0 ):QWidget(parent){}
//private:

//};

//class B:public QWidget{
//public:
//    B(QWidget *parent=0 ):QWidget(parent){
//        a.setWindowTitle("sub");
//        a.move(50,50);
//        a.show();

//    }
//private:
//    A a;
//};



int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    B b;
    b.setWindowTitle("main");
    b.show();
    return app.exec();
}
