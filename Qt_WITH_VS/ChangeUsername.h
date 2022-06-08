#pragma once
#include <QWidget>
#include"Login.h"
#include "ui_ChangeUsername.h"

class ChangeUsername : public QWidget
{
	Q_OBJECT

public:
	ChangeUsername(QWidget *parent = Q_NULLPTR);
	~ChangeUsername();

private:
	Ui::ChangeUsername ui;
private slots:
	void on_OK_clicked();
	void on_NO_clicked();
};
