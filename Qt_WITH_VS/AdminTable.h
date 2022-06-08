#pragma once
#include"ChangeAdminInformation.h"
#include <QWidget>
#include<istream>
#include<ostream>
#include<fstream>
#include "ui_AdminTable.h"
#include"Login.h"
#include"path.h"
#include"AddAdmin.h"
#include"ChangeOtherAdmin.h"
class AdminTable : public QWidget
{
	Q_OBJECT

public:
	AdminTable(QWidget *parent = Q_NULLPTR);
	~AdminTable();

private:
	Ui::AdminTable ui;
private slots:
	void on_ExitBtn_clicked();
	void on_addNdelBtn_clicked();
	void on_flushBtn_clicked();
	void on_modifyBtn_clicked();
public slots:
	void flushTable();
	void findMess();
private:
	ChangeAdminInformation* chg;
};
