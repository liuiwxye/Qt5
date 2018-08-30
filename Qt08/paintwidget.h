#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H
#include <QPushButton>
#include <QWidget>

class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    PaintWidget(QWidget *parent = 0);
    ~PaintWidget();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    QPushButton *button;
    int x;
};

#endif // PAINTWIDGET_H
