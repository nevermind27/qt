#ifndef YEAR_H
#define YEAR_H

#include <QDialog>

namespace Ui {
class year;
}

class year : public QDialog
{
    Q_OBJECT

public:
    explicit year(QWidget *parent = nullptr);
    ~year();

private slots:
    void on_pushButton_clicked();

private:
    Ui::year *ui;
};

#endif // YEAR_H
