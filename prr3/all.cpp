#include "all.h"
#include "ui_all.h"
#include <QFile>
#include <QString>
#include <QListWidgetItem>
#include <QListWidget>
#include <QLineEdit>
all::all(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::all)
{
    ui->setupUi(this);
}

all::~all()
{
    delete ui;
}

void all::on_pushButton_2_clicked()
{
    QFile file("baza.txt");
    QString t,k;
    int count=1;


    int flag=0;
     QString fio_f=ui->lineEdit->text();
      flag=0;
     QString fio_norm=fio_f.trimmed();
     if (file.open(QIODevice::ReadOnly)){
         while (!file.atEnd()){

             k=file.readLine();
             t=k.simplified();

             if (count%4==1) {
                 if (t==fio_norm)
                     flag=1;
             // new QListWidgetItem(t,ui->listWidget);

               }
             if (count%4==2){
              if (flag==1)
                new QListWidgetItem(t,ui->listWidget);

             }

             count++;
              // QStringList lst = str.split(" ");
              //ui->listWidget->addItem(t);
          }
    file.close();
 }
}

