#pragma once

#include <QWidget>
#include "ui_ChangePassword.h"
#include"Login.h"
class ChangePassword : public QWidget
{
	Q_OBJECT

public:
	ChangePassword(QWidget *parent = Q_NULLPTR);
	~ChangePassword();

private:
	Ui::ChangePassword ui;
private slots:
	void on_OK_clicked();
	void on_NO_clicked();
};
