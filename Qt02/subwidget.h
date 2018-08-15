#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget:public QWidget{

    Q_OBJECT

public:
    SubWidget(QWidget *parent=nullptr);
    void sendSlot();
signals:
    void toMainWin();

private:
    QPushButton b;
};

#endif // SUBWIDGET_H
