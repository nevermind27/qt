#include "otr.h"
#include "ui_otr.h"

otr::otr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otr)
{
    ui->setupUi(this);
    QFile file("baza.txt");
    QString t="kk";
    int count=1;
    int count_otr=0;
     if (file.open(QIODevice::ReadOnly)){
         while (!file.atEnd()){
             t=file.readLine();

             if (count%4==0){
                 if (t[0]=='-'){
                     count_otr+=1;
                 }
             }
             count++;

          }
    file.close();
 }
 ui->label_2->setText(QString::number(count_otr));
     //ui->label_2->text()=;
}

otr::~otr()
{
    delete ui;
}

void otr::on_pushButton_clicked()
{
    hide();
}

