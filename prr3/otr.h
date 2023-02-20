#ifndef OTR_H
#define OTR_H
#include<QFile>
#include<QString>
#include <QDialog>

namespace Ui {
class otr;
}

class otr : public QDialog
{
    Q_OBJECT

public:
    explicit otr(QWidget *parent = nullptr);
    ~otr();

private slots:
    void on_pushButton_clicked();

private:
    Ui::otr *ui;
};

#endif // OTR_H
