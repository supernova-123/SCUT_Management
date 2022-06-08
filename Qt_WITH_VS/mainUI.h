#pragma once
#include <QtWidgets/QMainWindow>
#include<qprocess.h>
#include<qdebug.h>
#include "ui_mainUI.h"
#include"AdminWidgets.h"
#include"Login.h"
#include"MyInformation.h"
#include"AdminInformation.h"
#include"TeacherInformation.h"
#include"VisitorInformation.h"
#include"AddAdmin.h"
#include"AdminTable.h"
//#include"NetworkDetect.h"
class mainUI : public QMainWindow
{
    Q_OBJECT
public:
    mainUI(QWidget* parent = Q_NULLPTR);
    bool Ping(QString strPingIP);
private:
    Ui::mainUIClass ui;
private slots:
    void on_logout_clicked();
    void on_information_clicked();
    void on_student_clicked();
    void on_visitor_clicked();
    void on_teacher_clicked();
    void on_addAdmin_clicked();
};
