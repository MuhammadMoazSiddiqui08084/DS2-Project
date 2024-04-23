/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QLineEdit *lineEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(778, 496);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(70, 160, 241, 32));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(440, 160, 241, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 130, 71, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arima Koshi")});
        font.setPointSize(15);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(540, 130, 61, 16));
        label_2->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 220, 151, 51));
        pushButton->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 40, 301, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arima Koshi")});
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setUnderline(true);
        label_3->setFont(font1);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(310, 300, 141, 51));
        lineEdit->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Species 1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Species 2", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Check Similarity", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Species Similarity Checker", nullptr));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
