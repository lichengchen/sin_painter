#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "math.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("sin_painter : )");
    this->showMaximized();
    ui->stackedWidget_3->setCurrentIndex(0);

    len=1;
    spacing=20;
    dencity=16;
    v=1;
    show_value();
    on_radioButton_clicked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    paintSin(painter, s, 2, 350);

    if(ui->radioButton_2->isChecked()){
        paintSin(painter, c, 2, 550);
    }
    if(ui->checkBox->isChecked()){  //绘制求和结果
        paintSum(painter,s,c,2,750);
    }
    else if(ui->checkBox_2->isChecked()){   //绘制求积结果
        paintMul(painter,s,c,2,750);
    }

    if(ui->checkBox_3->isChecked()){    //绘制游标
        paintVernier(painter,v-1);
    }
}

void MainWindow::show_value()
{
    ui->doubleSpinBox->setValue(s.A);
    ui->doubleSpinBox_2->setValue(s.w);
    ui->doubleSpinBox_3->setValue(s.b);
    ui->doubleSpinBox_4->setValue(s.A);
    ui->doubleSpinBox_5->setValue(s.w);
    ui->doubleSpinBox_6->setValue(s.b);
    ui->horizontalScrollBar_4->setMaximum(len);
}

void MainWindow::paintSin(QPainter &painter, Sin si, int basex, int basey)
{
    QPen mypen;
    mypen.setWidth(1);
    mypen.setColor(Qt::blue);
    painter.setPen(mypen);

    QString name="";
    if(si.A!=1){
        name=QString::number(si.A)+"*";
    }
    name+="sin(";
    if(si.w!=1){
        name=name+QString::number(si.w)+"*";
    }
    name+="x";
    if(si.b!=0){
        name=name+"+"+QString::number(si.b);
    }
    name+=")";

    painter.drawText(basex,basey-10,name);

    QPointF pointf[len];
    for(int i=0;i<len;i++){
        pointf[i].setX(basex+spacing*i*M_PI/dencity);
        pointf[i].setY(basey-si.A*spacing*sin(i*M_PI/dencity*si.w+si.b));
        painter.drawPoint(basex+spacing*i*M_PI/dencity,basey);
    }

    mypen.setWidth(2);
    mypen.setColor(Qt::black);
    painter.setPen(mypen);
    painter.drawPoints(pointf,len);

    //updating
    if(ui->checkBox_3->isChecked()){    //绘制游标焦点
        int index=v-1;
        mypen.setColor(Qt::red);
        mypen.setWidth(5);
        painter.setPen(mypen);
        painter.drawPoint(basex+spacing*index*M_PI/dencity,basey-si.A*spacing*sin(index*M_PI/dencity*si.w+si.b));
        QString pointxy="(";
        if(index!=0){
            pointxy+=QString::number((double)index/dencity)+"π";
        }
        else{   //index=0
            pointxy+="0";
        }
        pointxy=pointxy+","+QString::number(si.A*sin(index*M_PI/dencity*si.w+si.b))+")";

        painter.drawText(pointf[index].x(),pointf[index].y(),pointxy);
    }
}

void MainWindow::paintSum(QPainter &painter, Sin s1, Sin s2,int basex, int basey)
{
    QPen mypen;
    mypen.setWidth(1);
    mypen.setColor(Qt::blue);
    painter.setPen(mypen);
    painter.drawText(basex,basey-10,"Sum");

    QPointF pointf[len];
    for(int i=0;i<len;i++){
        pointf[i].setX(basex+spacing*i*M_PI/dencity);
        pointf[i].setY(basey-s1.A*spacing*sin(i*M_PI/dencity*s1.w+s1.b) - s2.A*spacing*sin(i*M_PI/dencity*s2.w+s2.b));
        painter.drawPoint(basex+spacing*i*M_PI/dencity,basey);
    }

    mypen.setWidth(2);
    mypen.setColor(Qt::black);
    painter.setPen(mypen);
    painter.drawPoints(pointf,len);

    //updating
    if(ui->checkBox_3->isChecked()){    //绘制游标焦点
        int index=v-1;
        mypen.setColor(Qt::red);
        mypen.setWidth(5);
        painter.setPen(mypen);
        painter.drawPoint(basex+spacing*index*M_PI/dencity,
                          basey-s1.A*spacing*sin(index*M_PI/dencity*s1.w+s1.b) - s2.A*spacing*sin(index*M_PI/dencity*s2.w+s2.b));
        QString pointxy="(";
        if(index!=0){
            pointxy+=QString::number((double)index/dencity)+"π";
        }
        else{   //index=0
            pointxy+="0";
        }
        pointxy=pointxy+","+QString::number(s1.A*sin(index*M_PI/dencity*s1.w+s1.b)
                                            + s2.A*sin(index*M_PI/dencity*s2.w+s2.b))+")";

        painter.drawText(pointf[index].x(),pointf[index].y(),pointxy);
    }
}

void MainWindow::paintMul(QPainter &painter, Sin s1, Sin s2,int basex, int basey)
{
    QPen mypen;
    mypen.setWidth(1);
    mypen.setColor(Qt::blue);
    painter.setPen(mypen);
    painter.drawText(basex,basey-10,"Mul");

    QPointF pointf[len];
    for(int i=0;i<len;i++){
        pointf[i].setX(basex+spacing*i*M_PI/dencity);
        pointf[i].setY(basey-s1.A*spacing*sin(i*M_PI/dencity*s1.w+s1.b) * s2.A*sin(i*M_PI/dencity*s2.w+s2.b));
        painter.drawPoint(basex+spacing*i*M_PI/dencity,basey);
    }

    mypen.setWidth(2);
    mypen.setColor(Qt::black);
    painter.setPen(mypen);
    painter.drawPoints(pointf,len);

    if(ui->checkBox_3->isChecked()){    //绘制游标焦点
        int index=v-1;
        mypen.setColor(Qt::red);
        mypen.setWidth(5);
        painter.setPen(mypen);
        painter.drawPoint(basex+spacing*index*M_PI/dencity,
                          basey-s1.A*spacing*sin(index*M_PI/dencity*s1.w+s1.b) * s2.A*sin(index*M_PI/dencity*s2.w+s2.b));
        QString pointxy="(";
        if(index!=0){
            pointxy+=QString::number((double)index/dencity)+"π";
        }
        else{   //index=0
            pointxy+="0";
        }
        pointxy=pointxy+","+QString::number(s1.A*sin(index*M_PI/dencity*s1.w+s1.b)
                                            * s2.A*sin(index*M_PI/dencity*s2.w+s2.b))+")";

        painter.drawText(pointf[index].x(),pointf[index].y(),pointxy);
    }
}


void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    len=value;
    update();
    ui->horizontalScrollBar_4->setMaximum(len);
}

void MainWindow::on_horizontalScrollBar_2_valueChanged(int value)
{
    spacing=value;
     update();
}

void MainWindow::on_horizontalScrollBar_3_valueChanged(int value)
{
    dencity=value;
    update();
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    if(checked){
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
    }
    update();
}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if(checked){
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_2->setCurrentIndex(1);
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
    }
    update();
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked){
        ui->checkBox_2->setChecked(false);
    }
    update();
}

void MainWindow::on_checkBox_2_clicked(bool checked)
{
    if(checked){
        ui->checkBox->setChecked(false);
    }
    update();
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    s.A=arg1;
    update();
}

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    s.w=arg1;
    update();
}

void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
    s.b=arg1;
    update();
}

void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    c.A=arg1;
    update();
}

void MainWindow::on_doubleSpinBox_5_valueChanged(double arg1)
{
    c.w=arg1;
    update();
}

void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1)
{
    c.b=arg1;
    update();
}

void MainWindow::paintVernier(QPainter & painter, int pos)
{
    QPen mypen;
    mypen.setWidth(1);
    mypen.setColor(Qt::gray);
    painter.setPen(mypen);

    painter.drawLine(QPoint(2+spacing*pos*M_PI/dencity,150),QPoint(2+spacing*pos*M_PI/dencity,1000));
}

void MainWindow::on_horizontalScrollBar_4_valueChanged(int value)
{
    v=value;
    update();
}

void MainWindow::on_checkBox_3_clicked(bool checked)
{
    if(checked){
        ui->stackedWidget_3->setCurrentIndex(1);
    }
    else{
        ui->stackedWidget_3->setCurrentIndex(0);
    }
    update();
}

void MainWindow::on_maxButton_clicked()
{
    ui->horizontalScrollBar->setValue(ui->horizontalScrollBar->maximum());
    ui->horizontalScrollBar_2->setValue(ui->horizontalScrollBar_2->maximum());
    ui->horizontalScrollBar_3->setValue(ui->horizontalScrollBar_3->maximum());
}
