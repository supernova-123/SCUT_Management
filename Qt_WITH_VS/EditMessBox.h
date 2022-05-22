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
	//���������Ϣ����
	EditMessBox();
	~EditMessBox();
signals:
	//�Զ����źţ��������Ϣ��ɺ󣬸����������ϵı��
	void closeBox();
public slots:
	//������Ա����Ϣд�뵽�ļ���
	void saveMess();
public:
	//���� closeBox �ź�
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
