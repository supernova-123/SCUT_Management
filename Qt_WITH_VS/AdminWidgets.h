#pragma once
#include<qgroupbox.h>
#include <QWidget>
#include "ui_AdminWidgets.h"
#include<qtablewidget.h>
#include<qlistwidget.h>
#include<qpushbutton.h>
#include<qlineedit.h>
#include <QFile>
#include <QDataStream>
#include"Login.h"
#include"EditMessBox.h"
#include<qlabel.h>
#include<qstatusbar.h>
#include<qtimer.h>
#include<qdatetime.h>
#include"path.h"
class AdminWidgets : public QWidget
{
	Q_OBJECT

public:
	//���������ڽ���
	AdminWidgets();
	~AdminWidgets();
	//���û������Ӱ�ťʱ�����������Ա��Ϣ����
	void AddBox();
	//QStatusBar* statusBar;
public slots:
	//���±�������е���Ϣ
	void flushTable();
	//���±������ʾ����Ա��Ϣ
	void flushListWidget(int row);
	//ʵ��ɾ����Ϣ�Ĺ���
	void delFun();
	//ʵ�ֲ�����Ϣ����
	void findMess();
	//ʵ���޸���Ϣ����
	void changeMess(int row);
	//ʵ�ֱ�����Ϣ����
	void saveMess();
private:
	Ui::AdminWidgets ui;
	//�����������е���Ϣ���
	QGroupBox* createMess();
	//�����������еĹ������
	QGroupBox* createMenu();
private:
	//�������еı��ؼ�
	QTableWidget* TableWidget;
	//�������е��б�ؼ�
	QListWidget* ListWidget;
	//�������е���ӡ�ɾ�������桢�˳���ť�Ͳ����ı���ؼ�
	QPushButton* AddBtn;
	QPushButton* DelBtn;
	QLineEdit* FindEdit;
	QPushButton* SaveBtn;
	QPushButton* ExitBtn;
	//�����������Ϣ����
	EditMessBox* messBox;
};
