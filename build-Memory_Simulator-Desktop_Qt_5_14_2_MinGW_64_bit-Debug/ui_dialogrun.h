/********************************************************************************
** Form generated from reading UI file 'dialogrun.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRUN_H
#define UI_DIALOGRUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogRun
{
public:
    QLabel *labelNofP;
    QLabel *labelInputNofP;
    QLabel *labelSofM;
    QLabel *labelInputSofM;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DialogRun)
    {
        if (DialogRun->objectName().isEmpty())
            DialogRun->setObjectName(QString::fromUtf8("DialogRun"));
        DialogRun->resize(660, 330);
        DialogRun->setMinimumSize(QSize(0, 0));
        labelNofP = new QLabel(DialogRun);
        labelNofP->setObjectName(QString::fromUtf8("labelNofP"));
        labelNofP->setGeometry(QRect(10, 0, 101, 16));
        labelInputNofP = new QLabel(DialogRun);
        labelInputNofP->setObjectName(QString::fromUtf8("labelInputNofP"));
        labelInputNofP->setGeometry(QRect(110, 0, 101, 16));
        labelSofM = new QLabel(DialogRun);
        labelSofM->setObjectName(QString::fromUtf8("labelSofM"));
        labelSofM->setGeometry(QRect(10, 20, 101, 16));
        labelInputSofM = new QLabel(DialogRun);
        labelInputSofM->setObjectName(QString::fromUtf8("labelInputSofM"));
        labelInputSofM->setGeometry(QRect(90, 20, 101, 16));
        pushButton = new QPushButton(DialogRun);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(580, 10, 75, 23));
        pushButton_2 = new QPushButton(DialogRun);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 10, 75, 23));

        retranslateUi(DialogRun);
        QObject::connect(pushButton, SIGNAL(clicked()), DialogRun, SLOT(close()));

        QMetaObject::connectSlotsByName(DialogRun);
    } // setupUi

    void retranslateUi(QDialog *DialogRun)
    {
        DialogRun->setWindowTitle(QCoreApplication::translate("DialogRun", "Dialog", nullptr));
        labelNofP->setText(QCoreApplication::translate("DialogRun", "Number of process:", nullptr));
        labelInputNofP->setText(QCoreApplication::translate("DialogRun", "text label", nullptr));
        labelSofM->setText(QCoreApplication::translate("DialogRun", "Size of Memory:", nullptr));
        labelInputSofM->setText(QCoreApplication::translate("DialogRun", "text label", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogRun", "Sair", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DialogRun", "Proximo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogRun: public Ui_DialogRun {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRUN_H
