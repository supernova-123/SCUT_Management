#pragma once

#include <QWidget>
#include "ui_ChangeOtherAdmin.h"
#include"path.h"
#include"Login.h"
class ChangeOtherAdmin : public QWidget
{
	Q_OBJECT

public:
	ChangeOtherAdmin(QWidget *parent = Q_NULLPTR);
	~ChangeOtherAdmin();

private:
	Ui::ChangeOtherAdmin ui;
private slots:
	void on_ok_clicked();
	void on_no_clicked();
};
