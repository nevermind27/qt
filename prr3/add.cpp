#include "add.h"
#include "ui_add.h"
#include <QTranslator>
#include <QListWidget>
#include <QFile>
#include <QString>
#include <QTextStream>
#include<QLabel>
#include<QListWidgetItem>
#include <QFileInfo>
add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
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

add::~add()
{
    delete ui;
}



void add::on_pushButton_3_clicked()
{

    hide();
}

//реализация добавления
void add::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() ||ui->lineEdit_3->text().isEmpty() ||ui->lineEdit_4->text().isEmpty()){
        QLabel *label= new QLabel("Ошибка: одно или несколько полей не заполнены");
        label->show();
    } else{
    QString fio=ui->lineEdit->text();
    QString number= ui->lineEdit_2->text();
     QString year= ui->lineEdit_3->text();
     QString balance=ui->lineEdit_4->text();
    QFile file("baza.txt");
    file.open(QFile::Append);
   QTextStream out(&file);
//   out << fio<<" ";
//   out << number<<" ";
//   out << year<<" ";
//   out <<balance<<" ";
    out << fio<<Qt::endl;
    out << number<<Qt::endl;
    out << year<<Qt::endl;
    out <<balance<<Qt::endl;
    file.close();
    new QListWidgetItem(fio,ui->listWidget);
    new QListWidgetItem(number,ui->listWidget_2);
    new QListWidgetItem(year,ui->listWidget_3);
    new QListWidgetItem(balance,ui->listWidget_4);}
    ui->lineEdit->clear();
     ui->lineEdit_2->clear();
      ui->lineEdit_3->clear();
       ui->lineEdit_4->clear();
}

//выбор удаляемого абонента
void add::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    int i=ui-> listWidget->currentRow();
    ui->listWidget_2->setCurrentRow(i);
    ui->listWidget_3->setCurrentRow(i);
    ui->listWidget_4->setCurrentRow(i);
}


void add::on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    int i=ui-> listWidget_2->currentRow();
    ui->listWidget->setCurrentRow(i);
    ui->listWidget_3->setCurrentRow(i);
    ui->listWidget_4->setCurrentRow(i);
}



void add::on_listWidget_3_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    int i=ui->listWidget_3->currentRow();
    ui->listWidget->setCurrentRow(i);
    ui->listWidget_2->setCurrentRow(i);
    ui->listWidget_4->setCurrentRow(i);
}





void add::on_listWidget_4_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    int i=ui->listWidget_4->currentRow();
    ui->listWidget->setCurrentRow(i);
    ui->listWidget_3->setCurrentRow(i);
    ui->listWidget_2->setCurrentRow(i);
}

//реализация удаления
void add::on_pushButton_2_clicked()
{
    //int i=ui-> listWidget_4->currentRow();
    QListWidgetItem *item = ui->listWidget->currentItem();
    QString del =item->text();
    QFile fileIn("baza.txt"), fileOut("baza2.txt");
    fileIn.open(QFile::ReadOnly); // check result
    fileOut.open(QFile::WriteOnly); // check result
    QTextStream streamIn(&fileIn), streamOut(&fileOut);
    int count =0;
    ui->listWidget->takeItem(ui->listWidget->currentRow());
    ui->listWidget_2->takeItem(ui->listWidget->currentRow());
    ui->listWidget_3->takeItem(ui->listWidget->currentRow());
    ui->listWidget_4->takeItem(ui->listWidget->currentRow());
    while (!streamIn.atEnd())
    {
        QString t = fileIn.readLine();
        if (t!=del && count!=1002 && count!=1003 && count!=1004){
            streamOut<<t;

        }
        else{
            count=1001;
        }
        count++;
    }
    fileIn.close();
    fileOut.close();

    fileIn.remove(); // check result
    fileOut.rename(QFileInfo(fileIn).absoluteFilePath()); // check result

}

