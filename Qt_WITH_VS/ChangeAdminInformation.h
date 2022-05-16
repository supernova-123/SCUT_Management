#pragma once
#include <QWidget>
#include "ui_ChangeAdminInformation.h"
#include"Login.h"
#include"path.h"
class ChangeAdminInformation : public QWidget
{
	Q_OBJECT

public:
	ChangeAdminInformation(QWidget *parent = Q_NULLPTR);
	~ChangeAdminInformation();

private:
	Ui::ChangeAdminInformation ui;
private slots:
	void on_OK_clicked();
	void on_NO_clicked();
};
