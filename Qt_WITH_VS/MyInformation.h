#pragma once
#include<qgroupbox.h>
#include <QWidget>
#include<qtablewidget.h>
#include<qlistwidget.h>
#include<qpushbutton.h>
#include<qlineedit.h>
#include <QFile>
#include <QDataStream>
#include"Login.h"
#include<qlabel.h>
#include<qstatusbar.h>
#include<qtimer.h>
#include<qdatetime.h>
#include <QWidget>
#include "ui_MyInformation.h"
#include"AdminWidgets.h"
#include"path.h"
#include"ChangeUsername.h"
#include"ChangePassword.h"
class MyInformation : public QWidget
{
	Q_OBJECT

public:
	MyInformation(QWidget* parent = Q_NULLPTR);
	~MyInformation();

private:
	Ui::MyInformation ui;
private slots:
	void on_changeusername_clicked();
	void on_changepassword_clicked();
	void on_flushBtn_clicked();
};
