#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "laborexchange.h"
#include <QFileDialog>


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
    QFileDialog choose;
  //  QMessageBox::information(0, "", ui->comboBox->currentText());
    ui->comboBox->clear();
  //  QMessageBox::information(0, "", "OK");
    laborExchange.listCandidate.clear();
   // QMessageBox::information(0, "", "OK");
    laborExchange.addCandidatesFromFile(choose.getOpenFileName(this, "Выбор списка кандидатов", "D://study//qt//lab2", "*txt"));
   // QMessageBox::information(0, "", "OK");
    for (int i = 0; i<(int)laborExchange.listCandidate.size(); i++)
    {
        ui->comboBox->addItem(laborExchange.listCandidate[i].fullName);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == -1) return;
    if (ui->comboBox->currentText() == "Add new...")
    {
        ui->comboBox->setCurrentText("Ivanov Ivan Ivanovich");
        candidatesRewriteInfo(index);
        laborExchange.addNewEmptyCandidate();
        updateCombo(index);
    }
    ui->c_bday->setText(laborExchange.listCandidate[index].dateOfBirth);
    ui->c_salary->setText(QString::number(laborExchange.listCandidate[index].minSalary));
    if (laborExchange.listCandidate[index].higherEducation == 1)
    {
        ui->c_higheduc->setText("Да");
    }
    else
    {
        ui->c_higheduc->setText("Отсутствует");
    }
    ui->c_pos->setText(laborExchange.listCandidate[index].desirePosition);
    ui->c_spec->setText(laborExchange.listCandidate[index].specialty);
}



void MainWindow::on_pushButton_2_clicked() // get vacancy for candidat
{
    ui->textBrowser->setText(laborExchange.getAvailablePositions(ui->comboBox->currentIndex()));
    QMessageBox::information(0, "Возраст", QString::number(laborExchange.getAge(laborExchange.listCandidate[ui->comboBox->currentIndex()].dateOfBirth)));
}

void MainWindow::candidatesRewriteInfo(int index)
{
    if (index == -1) return;
    laborExchange.listCandidate[index].fullName = ui->comboBox->currentText();
    laborExchange.listCandidate[index].dateOfBirth = ui->c_bday->text();
    laborExchange.listCandidate[index].minSalary = ui->c_salary->text().toDouble();
    laborExchange.listCandidate[index].higherEducation = ui->c_higheduc->text().toInt();
    laborExchange.listCandidate[index].desirePosition = ui->c_pos->text();
    laborExchange.listCandidate[index].specialty = ui->c_spec->text();

    if (ui->c_higheduc->text() == "Да") laborExchange.listCandidate[index].higherEducation = 1;
}

void MainWindow::on_pushButton_4_clicked() // save file candidat
{
    QFileDialog choose;
    candidatesRewriteInfo(ui->comboBox->currentIndex());
    laborExchange.rewriteCandidates(choose.getOpenFileName(0, "Выбор файла сохранения", "D://study//qt//lab2", "*txt"));
}

void MainWindow::updateCombo(int lastIndex) // update combobox
{
    ui->comboBox->clear();
    for (int i = 0; i<(int)laborExchange.listCandidate.size(); i++)
    {
        ui->comboBox->addItem(laborExchange.listCandidate[i].fullName);
    }
    ui->comboBox->setCurrentIndex(lastIndex);
}

void MainWindow::on_pushButton_6_clicked() // SAVE candidat
{
    candidatesRewriteInfo(ui->comboBox->currentIndex());
    updateCombo(ui->comboBox->currentIndex());
}

void MainWindow::on_pushButton_5_clicked() // DELETE candidate
{
    QMessageBox::StandardButton choose;
    choose = QMessageBox::question(0, "Удаление кандидата", "Вы действительно хотите удалить кандидата " + ui->comboBox->currentText() + "?", QMessageBox::Yes | QMessageBox::No);
    if (choose == QMessageBox::Yes)
    {
        laborExchange.deleteCandidate(ui->comboBox->currentIndex());
        updateCombo(0);
    }
}

void MainWindow::on_pushButton_10_clicked() // SAVE firm
{
    firmsRewriteInfo(ui->comboBox_2->currentIndex());
    updateCombo_2(ui->comboBox_2->currentIndex());
}

void MainWindow::on_pushButton_7_clicked() // open file firm
{
    QFileDialog choose;
    ui->comboBox_2->clear();
    laborExchange.listFirm.clear();
    laborExchange.addFirmFromFile(choose.getOpenFileName(this, "Выбор списка фирм", "D://study//qt//lab2", "*txt"));
    for (int i = 0; i<(int)laborExchange.listFirm.size(); i++)
    {
        ui->comboBox_2->addItem(laborExchange.listFirm[i].name);
    }
}


void MainWindow::on_pushButton_8_clicked() // save file firm
{
    QFileDialog choose;
    firmsRewriteInfo(ui->comboBox_2->currentIndex());
    laborExchange.rewriteFirms(choose.getOpenFileName(0, "Выбор файла сохранения", "D://study//qt//lab2", "*txt"));
}


void MainWindow::firmsRewriteInfo(int index)
{
    if (index == -1) return;
    laborExchange.listFirm[index].name = ui->comboBox_2->currentText();
    laborExchange.listFirm[index].needHigherEducation = ui->f_higheduc->text().toInt();
    laborExchange.listFirm[index].needMaxAge = ui->f_maxAge->text().toInt();
    laborExchange.listFirm[index].needMinAge = ui->f_minage->text().toInt();
    laborExchange.listFirm[index].position = ui->f_pos->text();
    laborExchange.listFirm[index].salary = ui->f_salary->text().toDouble();
    laborExchange.listFirm[index].specialty = ui->f_spec->text();
    laborExchange.listFirm[index].vacationDays = ui->f_vacation->text().toInt();

    if (ui->f_higheduc->text() == "Требуется") laborExchange.listFirm[index].needHigherEducation = 1;
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    if (index == -1) return;
    if (ui->comboBox_2->currentText() == "Add new...")
    {
        ui->comboBox_2->setCurrentText("ООО \"Дефолт\"");
        firmsRewriteInfo(index);
        laborExchange.addNewEmptyFirm();
        updateCombo_2(index);
    }
    ui->f_maxAge->setText(QString::number(laborExchange.listFirm[index].needMaxAge));
    ui->f_minage->setText(QString::number(laborExchange.listFirm[index].needMinAge));
    ui->f_pos->setText(laborExchange.listFirm[index].position);
    ui->f_salary->setText(QString::number(laborExchange.listFirm[index].salary));
    ui->f_spec->setText(laborExchange.listFirm[index].specialty);
    ui->f_vacation->setText(QString::number(laborExchange.listFirm[index].vacationDays));
    if (laborExchange.listFirm[index].needHigherEducation == 1)
    {
        ui->f_higheduc->setText("Требуется");
    }
    else
    {
        ui->f_higheduc->setText("Не требуется");
    }
}

void MainWindow::updateCombo_2(int lastIndex)
{
    ui->comboBox_2->clear();
    for (int i = 0; i<(int)laborExchange.listFirm.size(); i++)
    {
        ui->comboBox_2->addItem(laborExchange.listFirm[i].name);
    }
    ui->comboBox_2->setCurrentIndex(lastIndex);
}

void MainWindow::on_pushButton_9_clicked()
{
    QMessageBox::StandardButton choose;
    choose = QMessageBox::question(0, "Удаление фирмы", "Вы действительно хотите удалить фирму " + ui->comboBox_2->currentText() + "?", QMessageBox::Yes | QMessageBox::No);
    if (choose == QMessageBox::Yes)
    {
        laborExchange.deleteFirm(ui->comboBox_2->currentIndex());
        updateCombo_2(0);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textBrowser->setText(laborExchange.getScarceJobs());
}

void MainWindow::on_pushButton_11_clicked()
{
    laborExchange.sortCandidatesByName();
    updateCombo(0);
}

void MainWindow::on_pushButton_12_clicked()
{
    laborExchange.sortFirmsByName();
    updateCombo_2(0);
}
