/********************************************************************************
** Form generated from reading UI file 'information.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_H
#define UI_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Information
{
public:
    QListWidget *listeAime;
    QLabel *lb_nom;

    void setupUi(QWidget *Information)
    {
        if (Information->objectName().isEmpty())
            Information->setObjectName("Information");
        Information->resize(377, 248);
        listeAime = new QListWidget(Information);
        listeAime->setObjectName("listeAime");
        listeAime->setGeometry(QRect(10, 40, 221, 192));
        lb_nom = new QLabel(Information);
        lb_nom->setObjectName("lb_nom");
        lb_nom->setGeometry(QRect(10, 10, 221, 16));

        retranslateUi(Information);

        QMetaObject::connectSlotsByName(Information);
    } // setupUi

    void retranslateUi(QWidget *Information)
    {
        Information->setWindowTitle(QCoreApplication::translate("Information", "Form", nullptr));
        lb_nom->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Information: public Ui_Information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_H
