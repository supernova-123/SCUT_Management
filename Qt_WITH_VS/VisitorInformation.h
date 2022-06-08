#pragma once
#include <QWidget>
#include "ui_VisitorInformation.h"
#include"AdminWidgets.h"
#include"path.h"
#include"ChangeUsername.h"
#include"ChangePassword.h"
class VisitorInformation : public QWidget
{
	Q_OBJECT

public:
	VisitorInformation(QWidget *parent = Q_NULLPTR);
	~VisitorInformation();

private:
	Ui::VisitorInformation ui;
private slots:
	void on_changeusername_clicked();
	void on_changepassword_clicked();
	void on_flushBtn_clicked();
};
