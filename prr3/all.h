#ifndef ALL_H
#define ALL_H

#include <QDialog>

namespace Ui {
class all;
}

class all : public QDialog
{
    Q_OBJECT

public:
    explicit all(QWidget *parent = nullptr);
    ~all();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::all *ui;
};

#endif // ALL_H
