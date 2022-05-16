#pragma once
#include <QWidget>
#include "ui_TeacherInformation.h"
#include"AdminWidgets.h"
#include"ChangePassword.h"
#include"ChangeUsername.h"
class TeacherInformation : public QWidget
{
	Q_OBJECT

public:
	TeacherInformation(QWidget *parent = Q_NULLPTR);
	~TeacherInformation();
private:
	Ui::TeacherInformation ui;
private slots:
	void on_changeusername_clicked();
	void on_changepassword_clicked();
	void on_flushBtn_clicked();
};
