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
	//构建主窗口界面
	AdminWidgets();
	~AdminWidgets();
	//当用户点击添加按钮时，弹出添加人员信息窗口
	void AddBox();
	//QStatusBar* statusBar;
public slots:
	//更新表格中罗列的信息
	void flushTable();
	//更新表格中显示的人员信息
	void flushListWidget(int row);
	//实现删除信息的功能
	void delFun();
	//实现查找信息功能
	void findMess();
	//实现修改信息功能
	void changeMess(int row);
	//实现保存信息功能
	void saveMess();
private:
	Ui::AdminWidgets ui;
	//创建主窗口中的信息面板
	QGroupBox* createMess();
	//创建主窗口中的功能面板
	QGroupBox* createMenu();
private:
	//主窗口中的表格控件
	QTableWidget* TableWidget;
	//主窗口中的列表控件
	QListWidget* ListWidget;
	//主窗口中的添加、删除、保存、退出按钮和查找文本框控件
	QPushButton* AddBtn;
	QPushButton* DelBtn;
	QLineEdit* FindEdit;
	QPushButton* SaveBtn;
	QPushButton* ExitBtn;
	//弹出的添加信息窗口
	EditMessBox* messBox;
};
