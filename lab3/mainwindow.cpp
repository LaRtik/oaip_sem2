#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    try
    {
        checkInt(ui->lineCount->text());
        checkDouble(ui->lineCost->text());
        checkDate(ui->lineDate->text());
        Product * product = new Product;
        product->name = ui->lineName->text();
        product->count = ui->lineCount->text().toInt();
        product->cost = ui->lineCost->text().toDouble();
        product->date = QDateTime::fromString(ui->lineDate->text(), "dd.mm.yyyy");
        listProducts->push(product);

    }
    catch (Errors &exception)
    {
        QMessageBox::critical(0, "ERROR", "An error occured: \n" + QString(exception.what()));
    }
    catch (exception &exception)
    {
        QMessageBox::critical(0, "ERROR", "An error occured: \n" + QString(exception.what()));
    }
    QMessageBox::information(0, "Успешное добавление", "Товар " + ui->lineName->text() + " успешно добавлен!");

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->setText(listProducts->getAll());
    QMessageBox::information(0, "Весь список", "Полный список товаров успешно загружен");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textBrowser->setText(listProducts->getByName(ui->lineFindName->text()));
    if (ui->textBrowser->toPlainText().isEmpty())
    {
        QMessageBox::information(0, "", "По данному наименованию не найдено подходящих товаров!");
    }
    else
    {
        QMessageBox::information(0, "Успешно", "Товар " + ui->lineFindName->text() + " успешно найден!");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    try
    {
        checkInt(ui->lineFindDate->text());
        ui->textBrowser->setText(listProducts->getMoreThanDays(ui->lineFindDate->text().toInt()));

    }
    catch (Errors &exception)
    {
        QMessageBox::critical(0, "ERROR", "An error occured: \n" + QString(exception.what()));
    }
    catch (exception &exception)
    {
        QMessageBox::critical(0, "ERROR", "An error occured: \n" + QString(exception.what()));
    }

    if (ui->textBrowser->toPlainText().isEmpty())
    {
        QMessageBox::information(0, "", "По данному наименованию не найдено подходящих товаров!");
    }
    else
    {
        QMessageBox::information(0, "Успешно", "Товары найдены!");
    }

}

void MainWindow::on_pushButton_5_clicked()
{
    try
    {
        checkDouble(ui->lineCost->text());
        ui->textBrowser->setText(listProducts->getLowerThanPrice(ui->lineFindPrice->text().toDouble()));

    }
    catch (Errors &exception)
    {
        QMessageBox::critical(0, "ERROR", "An error occured: \n" + QString(exception.what()));
    }
    catch (exception &exception)
    {
        QMessageBox::critical(0, "ERROR", "An error occured: \n" + QString(exception.what()));
    }
    if (ui->textBrowser->toPlainText().isEmpty())
    {
        QMessageBox::information(0, "", "По данному наименованию не найдено подходящих товаров!");
    }
    else
    {
        QMessageBox::information(0, "Успешно", "Товары найдены!");
    }

}
