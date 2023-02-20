#include "graf.h"
#include "ui_graf.h"
#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <QChart>
#include <QChartView>
#include <QHBoxLayout>
#include <QCategoryAxis>
#include <math.h>
#include <QFile>
using namespace QtCharts;


graf::graf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graf)
{
    ui->setupUi(this);





   // chartView->size();
    // Добавляем его в горизонтальный Layout
//      QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
//      horizontalLayout->addWidget(chartView);


      //данные для внесения в график
      QFile file("baza.txt");
      QString tek_year;

       QLineSeries *series=new QLineSeries();
     // int count_otr=0;
        QString tek;
         int count_tek,count;
      for (int i=2000,j=0;i<=2022;i++,j++){
           count=1;
            count_tek=0;
            tek_year= QString::number(i);
       if (file.open(QIODevice::ReadOnly)){
           while (!file.atEnd()){
               tek=file.readLine();
               //if (count%3==0){
                   if (tek.trimmed()==tek_year.trimmed())count_tek++;
               //}
               count++;

            }
      file.close();



series->append(j,count_tek);
}


}
      QChart *chart =new QChart();
      chart->legend()->hide();
      chart->addSeries(series);
      chart->createDefaultAxes();
     // horizontalLayout->addWidget(*chart);
      QPen pen(QRgb(0x008000));
      pen.setWidth(2);
      series->setPen(pen);

      chart->setAnimationOptions(QChart::AllAnimations);

     QCategoryAxis *axisX = new QCategoryAxis();
      for (int i=2000,j=0;i<=2022;i++,j++){
          axisX->append(QString::number(i),j);
      }
     chart->setAxisX(axisX,series);

      QChartView *chartView = new QChartView(chart);
      QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
         horizontalLayout->addWidget(chartView);

}
graf::~graf()
{
    delete ui;
}
