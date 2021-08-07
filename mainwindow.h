#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sin.h"
#include "qpainter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
    void paintSin(QPainter& painter, Sin si, int basex, int basey);
    void paintSum(QPainter& painter,Sin s1,Sin s2,int basex,int basey);
    void paintMul(QPainter& painter,Sin s1,Sin s2,int basex,int basey);
    void show_value();

    void paintVernier(QPainter& painter,int pos);

private slots:
    void on_horizontalScrollBar_valueChanged(int value);

    void on_horizontalScrollBar_2_valueChanged(int value);

    void on_horizontalScrollBar_3_valueChanged(int value);


    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);


    void on_checkBox_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_doubleSpinBox_6_valueChanged(double arg1);

    void on_horizontalScrollBar_4_valueChanged(int value);

    void on_checkBox_3_clicked(bool checked);

    void on_maxButton_clicked();

private:
    Ui::MainWindow *ui;

    int len;        //绘制多少点
    int spacing;    //缩放
    int dencity;    //密度--1个周期的闭区间内绘制的点个数为2*dencity+1
    Sin s;
    Sin c;

    int v;          //游标位置
};

#endif // MAINWINDOW_H
