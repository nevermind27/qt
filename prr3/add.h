#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <QListWidgetItem>
namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_3_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_4_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_pushButton_2_clicked();

private:
    Ui::add *ui;
};

#endif // ADD_H
