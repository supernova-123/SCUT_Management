#pragma once
#include <QWidget>
#include<qmessagebox.h>
#include<qfile.h>
#include <QObject>
#include <QString>
#include "ui_AddAdmin.h"
#include"Login.h"
#include"path.h"
class AddAdmin : public QWidget
{
	Q_OBJECT

public:
	AddAdmin(QWidget *parent = Q_NULLPTR);
	~AddAdmin();

private:
	Ui::AddAdmin ui;
private slots:
	void on_yesBtn_clicked();
	void on_noBtn_clicked();
	void on_delBtn_clicked();
};
