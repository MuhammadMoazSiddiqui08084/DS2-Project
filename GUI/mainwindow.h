#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QDir>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    // void on_comboBox_activated(int index);

    void on_comboBoxSpecies1_activated(int index);

    void on_comboBoxSpecies2_activated(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
