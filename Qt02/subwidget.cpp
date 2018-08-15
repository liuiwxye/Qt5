#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent)
    :QWidget(parent)
{
    this->setWindowTitle("sub Window");
    b.setParent(this);
    b.setText("切换到主窗口");
    connect(&b,&QPushButton::released,this,&SubWidget::sendSlot);
    resize(400,400);
}

void SubWidget::sendSlot()
{
    emit toMainWin();
}
