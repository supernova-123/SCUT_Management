/********************************************************************************
** Form generated from reading UI file 'EditMessBox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITMESSBOX_H
#define UI_EDITMESSBOX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_EditMessBox
{
public:

    void setupUi(QDialog *EditMessBox)
    {
        if (EditMessBox->objectName().isEmpty())
            EditMessBox->setObjectName(QString::fromUtf8("EditMessBox"));
        EditMessBox->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/addNewFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditMessBox->setWindowIcon(icon);

        retranslateUi(EditMessBox);

        QMetaObject::connectSlotsByName(EditMessBox);
    } // setupUi

    void retranslateUi(QDialog *EditMessBox)
    {
        EditMessBox->setWindowTitle(QCoreApplication::translate("EditMessBox", "EditMessBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditMessBox: public Ui_EditMessBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMESSBOX_H
