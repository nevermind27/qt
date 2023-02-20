#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add.h"
#include "otr.h"
#include "year.h"
#include "graf.h"
#include "all.h"
#include <string>
#include <fstream>
#include<iostream>
#include <QObject>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QListWidget>
#include <QFile>
#include <QString>
#include <QByteArray>
#include "graph.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   QFile file("baza.txt");
   QString t="kk";
   int count=1;
    if (file.open(QIODevice::ReadOnly)){
        while (!file.atEnd()){
            t=file.readLine();
            if (count%4==1) {
             new QListWidgetItem(t,ui->listWidget);}
            if (count%4==2){
                new QListWidgetItem(t,ui->listWidget_2);
            }
            if (count%4==3){
                new QListWidgetItem(t,ui->listWidget_3);
            }
            if (count%4==0){
                new QListWidgetItem(t,ui->listWidget_4);
            }
            count++;
             // QStringList lst = str.split(" ");
             //ui->listWidget->addItem(t);
         }
   file.close();
}
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    add * addWindow = new add(this);
//    addWindow->show();
    add addWindow;
    addWindow.setModal(true);
    addWindow.exec();
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    ui->listWidget_3->clear();
    ui->listWidget_4->clear();
    QFile file("baza.txt");
    QString t="kk";
    int count=1;
     if (file.open(QIODevice::ReadOnly)){
         while (!file.atEnd()){
             t=file.readLine();
             if (count%4==1) {
              new QListWidgetItem(t,ui->listWidget);}
             if (count%4==2){
                 new QListWidgetItem(t,ui->listWidget_2);
             }
             if (count%4==3){
                 new QListWidgetItem(t,ui->listWidget_3);
             }
             if (count%4==0){
                 new QListWidgetItem(t,ui->listWidget_4);
             }
             count++;
              // QStringList lst = str.split(" ");
              //ui->listWidget->addItem(t);
          }
    file.close();
 }
}


void MainWindow::on_pushButton_4_clicked()
{
    //hide();
    otr otrWindow;
    otrWindow.setModal(true);
    otrWindow.exec();
   // otr *otrWindow = new otr(this);
   // otrWindow.setModal(true);
   // otrWindow.exec();
    //SotrWindow->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    year yearWindow;
    yearWindow.setModal(true);
    yearWindow.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    all allWindow;
    allWindow.setModal(true);
   allWindow.exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    graf *gW = new graf();
    gW->setWindowTitle("График распределения абонента по годам");
    gW->show();
   // delete gW;
}

