#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include "ui_EditMessBox.h"
#include"Login.h"
#include<qcombobox.h>
#include<qdatetime.h>
#include<qdatetimeedit.h>
#include"path.h"
class EditMessBox : public QDialog
{
	Q_OBJECT

public:
	//构建添加信息界面
	EditMessBox();
	~EditMessBox();
signals:
	//自定义信号，当添加信息完成后，更新主界面上的表格
	void closeBox();
public slots:
	//将新人员的信息写入到文件中
	void saveMess();
public:
	//发出 closeBox 信号
	void emitCloseBox();
private:
	Ui::EditMessBox ui;
	QLineEdit* qid;
	QLineEdit* qname;
	QLineEdit* qbuilding;
	QLineEdit* qroom;
	QLineEdit* qage;
	QLineEdit* qaddress;
	QComboBox* qstayReason;
	QLineEdit* qvisReason;
	QDateEdit* qstartTime;
	QDateEdit* qfinTime;
	QLineEdit* qphone;
	QLineEdit* qusername;
	QLineEdit* qpassword;
	QPushButton* submit;
	QPushButton* cancel;
	QComboBox* qclass;
	QComboBox* qcode;
};
