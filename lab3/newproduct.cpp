#include "ui_newproduct.h"
#include "newproduct.h"
#include <QMessageBox>

NewProduct::NewProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProduct)
{
    ui->setupUi(this);
}

NewProduct::~NewProduct()
{
    delete ui;
}


void NewProduct::on_buttonBox_accepted()
{
    Product* result = new Product();
    result->name = ui->line_productName->text();
    result->cost = ui->line_productCost->text().toDouble();
    result->count = ui->line_productCount->text().toInt();
    result->date = QDateTime::fromString(ui->line_productCount->text(), "dd.mm.yyyy");
    result->next = nullptr;
    MainWindow::addNew(result);
    QMessageBox::information(0, "", result->toString());
   // listProducts->push(result);
}
