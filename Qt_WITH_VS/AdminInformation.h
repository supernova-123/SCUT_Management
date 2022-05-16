#pragma once
#include <QWidget>
#include "ui_AdminInformation.h"
#include"path.h"
#include"Login.h"
#include"ChangeAdminInformation.h"
class AdminInformation : public QWidget
{
	Q_OBJECT

public:
	AdminInformation(QWidget* parent = Q_NULLPTR);
	~AdminInformation();

private:
	Ui::AdminInformation ui;
private slots:
	void on_pwdCheck_clicked();
	void on_changeInformation_clicked();
	void on_flushBtn_clicked();
};
