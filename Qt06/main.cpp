#include <QApplication>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QMovie>
#include <QFileDialog>
#include <QDesktopServices>
#include <QProcess>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    QWidget w;
    w.resize(400,250);

    //图片
    QLabel *pImage = new QLabel(&w);
    pImage->setGeometry(10,10,50,50);
    pImage->setPixmap(QPixmap("../test/04_Image/butterfly1.png"));
    pImage->setScaledContents(true);


    //gif
    QLabel *pMovie = new QLabel(&w);
    pMovie->setGeometry(100,100,500,500);
    QMovie *newMovie = new QMovie("../test/04_Image/chatQQ.gif");
    pMovie->setMovie(newMovie);
    newMovie->start();
    //pMovie->setMovie(QMovie("../test/04_Image/chatQQ.gif"));
    pMovie->setScaledContents(true);


    //链接
    QLabel *pMyFile = new QLabel(&w);
    pMyFile->move(400,20);
    pMyFile->setText("<h1><a href=\"https://www.baidu.com\">hello</a></h1>");
    pMyFile->setOpenExternalLinks(true);

    //显示选择图片
    QLabel *map = new QLabel(&w);
    map->move(900,600);
    map->resize(40,40);
    QString path = QFileDialog::getOpenFileName(&w,"open","../");
    map->setPixmap(QPixmap(path));
    map->setScaledContents(true);


    /*
    //打开一个浏览器，返回是否打开成功
    bool is_open = QDesktopServices::openUrl(QUrl("127.0.0.1"));

    //打开一个文件夹
    QDesktopServices::openUrl(QUrl("file:///C:/Documents and Settings/All Users/Desktop"));

    //打开一个文件，以默认的方式打开
    QDesktopServices::openUrl(QUrl("file:///d://a.txt"));

    //打开外部程序的方法还可以调用QProcess
    //调用一个外部程序，以非阻塞的形式打开，第一个参数代表路径+打开程序所带参数
    proc->start("D://a.exe", QStringList()<<"-i"<<"in.txt";

    //与上面作用一样，不过是以阻塞的形式打开
    proc->execute("D://a.exe", QStringList()<<"-i"<<"in.txt";
    */

    return app.exec();
}
