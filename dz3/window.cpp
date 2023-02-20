#include "window.h"
#include "ui_window.h"
#include "area.h"
#include <QVBoxLayout>
#include <QPushButton>
Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)

{
    ui->setupUi(this);this->setWindowTitle("Обработка событий");
    area = new Area( this );
     QPushButton *btnexit = new QPushButton("Выход", this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btnexit);
    connect(btnexit, SIGNAL(clicked(bool)),this,SLOT(close()));

}

Window::~Window()
{
    delete ui;
}

