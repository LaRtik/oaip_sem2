#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <laborexchange.h>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    LaborExchange laborExchange;
    void updateCombo(int lastIndex);

private slots:

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void candidatesRewriteInfo(int index);

    void firmsRewriteInfo(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void updateCombo_2(int lastIndex);

    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
