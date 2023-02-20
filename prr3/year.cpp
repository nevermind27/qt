#include "year.h"
#include "ui_year.h"
#include <QFile>
#include <QString>
#include <QListWidgetItem>
#include <QListWidget>
#include <QLineEdit>
year::year(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::year)
{
    ui->setupUi(this);
}

year::~year()
{
    delete ui;
}

void year::on_pushButton_clicked()
{
    QFile file("baza.txt");
    QString t,k;
    int count=1;
    QString fio;
    QString year_tek;
    QString year_f=ui->lineEdit->text();
    QString year_norm=year_f.trimmed();
     if (file.open(QIODevice::ReadOnly)){
         while (!file.atEnd()){
             k=file.readLine();
             t=k.trimmed();
             if (count%4==1) {
                 fio=t;
              //new QListWidgetItem(t,ui->listWidget);

               }
             if (count%4==3){
              if (t==year_f)
                    new QListWidgetItem(fio,ui->listWidget);

             }

             count++;
              // QStringList lst = str.split(" ");
              //ui->listWidget->addItem(t);
          }
    file.close();
 }
}

