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

QT_BEGIN_NAMESPACE

class Ui_DialogRun
{
public:
    QLabel *labelNofP;
    QLabel *labelInputNofP;

    void setupUi(QDialog *DialogRun)
    {
        if (DialogRun->objectName().isEmpty())
            DialogRun->setObjectName(QString::fromUtf8("DialogRun"));
        DialogRun->resize(640, 480);
        labelNofP = new QLabel(DialogRun);
        labelNofP->setObjectName(QString::fromUtf8("labelNofP"));
        labelNofP->setGeometry(QRect(10, 0, 101, 16));
        labelInputNofP = new QLabel(DialogRun);
        labelInputNofP->setObjectName(QString::fromUtf8("labelInputNofP"));
        labelInputNofP->setGeometry(QRect(110, 0, 101, 16));

        retranslateUi(DialogRun);

        QMetaObject::connectSlotsByName(DialogRun);
    } // setupUi

    void retranslateUi(QDialog *DialogRun)
    {
        DialogRun->setWindowTitle(QCoreApplication::translate("DialogRun", "Dialog", nullptr));
        labelNofP->setText(QCoreApplication::translate("DialogRun", "Number of process:", nullptr));
        labelInputNofP->setText(QCoreApplication::translate("DialogRun", "text label", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogRun: public Ui_DialogRun {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRUN_H
