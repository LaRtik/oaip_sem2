#ifndef NEWPRODUCT_H
#define NEWPRODUCT_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class NewProduct;
}

class NewProduct : public QDialog
{
    Q_OBJECT

public:
    explicit NewProduct(QWidget *parent = nullptr);
    ~NewProduct();



private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewProduct *ui;
};

#endif // NEWPRODUCT_H
