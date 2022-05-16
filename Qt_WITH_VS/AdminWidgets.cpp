#include "AdminWidgets.h"
#include<qdebug.h>
#include<qboxlayout.h>
#include<qgroupbox.h>
#include<qstatusbar.h>
#include<qmessagebox.h>
#include<qmainwindow.h>
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
extern int type;//=1则为管理员 =2则为学生 =3则为教职工 =4则为访客 =5则为未注册的访客
extern int Pos;
extern int checkList;
AdminWidgets::AdminWidgets()
{
	ui.setupUi(this);
	/*
	 * 主界面利用 QHBoxLayout 布局为两个区域，左边区域用 Left_Table_Box 实现，右边由 Right_Table_Box 实现
	*/
	setWindowTitle("离校人员管理系统");
	//在标题显示当前用户名
	switch (type)
	{
	case 1:
		setWindowTitle(QLabel::tr("当前用户：%1").arg(AdminUser[Pos].getUsername()));
		break;
	case 2:
		setWindowTitle(QLabel::tr("当前用户：%1").arg(StudentUser[Pos].getUsername()));
		break;
	case 3:
		setWindowTitle(QLabel::tr("当前用户：%1").arg(TeacherUser[Pos].getUsername()));
		break;
	case 4:
		setWindowTitle(QLabel::tr("当前用户：%1").arg(VisitorUser[Pos].getUsername()));
	default:
		break;
	}
	this->resize(1000, 600);
	QHBoxLayout* HBoxLayout = new QHBoxLayout(this);

	QGroupBox* Left_Table_Box = createMess();
	QGroupBox* Right_Table_Box = createMenu();

	HBoxLayout->addWidget(Left_Table_Box, 4);
	HBoxLayout->addWidget(Right_Table_Box, 2);

}
//构建人员信息面板
/*Left_Table_Box 中只包含一个 QTableWidget 表格控件，
为了使表格尺寸自适应整个窗口，将表格添加到了 QHBoxLayout 布局工具中。*/
QGroupBox* AdminWidgets::createMess()
{
	QGroupBox* box = new QGroupBox("人员信息");
	TableWidget = new QTableWidget;
	TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//按行尾为单位选择
	if (type == 1)//管理员设置为均可见
	{
		TableWidget->setColumnCount(14);
		if (checkList == 1)//学生
			TableWidget->setHorizontalHeaderLabels(QStringList() << "身份" << "姓名" << "学号/身份证号" << "年龄" << "楼栋" << "房号" <<
				"家庭住址" << "联系方式" << "留校起始时间" << "离校时间" << "留校原因" << "健康码状态" << "用户名" << "密码");
		else if (checkList == 2)//教职工
			TableWidget->setHorizontalHeaderLabels(QStringList() << "身份" << "姓名" << "工号/身份证号" << "年龄" << "所属机构" << "校内住址/办公室" <<
				"家庭地址" << "联系方式" << "留校起始时间" << "离校时间" << "留校原因" << "健康码状态" << "用户名" << "密码");
		else if (checkList == 3)//访客
			TableWidget->setHorizontalHeaderLabels(QStringList() << "身份" << "姓名" << "身份证号" << "年龄" << "所属机构/楼栋" << "校内住址/办公室" <<
				"家庭地址" << "联系方式" << "留校起始时间" << "离校时间" << "来访原因" << "健康码状态" << "用户名" << "密码");
	}
	else//其他人只能看到姓名、楼栋、留校起始时间、离校时间、用户名、身份、联系方式
	{
		TableWidget->setColumnCount(7);
		if (checkList == 1)//学生
			TableWidget->setHorizontalHeaderLabels(QStringList() << "身份" << "姓名" << "楼栋号" << "联系方式" << "留校起始时间" << "离校时间" << "用户名");
		else if (checkList == 2)//教职工
			TableWidget->setHorizontalHeaderLabels(QStringList() << "身份" << "姓名" << "所属机构"  << "联系方式" << "留校起始时间" << "离校时间" << "用户名");
		else if (checkList == 3)//访客
			TableWidget->setHorizontalHeaderLabels(QStringList() << "身份" << "姓名" << "所属机构/楼栋"  << "联系方式" << "留校起始时间" << "离校时间"  << "用户名");
	}
	TableWidget->setSortingEnabled(true);//设置表头的排序属性
	flushTable();
	QHBoxLayout* AutoHBoxLayout = new QHBoxLayout;
	AutoHBoxLayout->addWidget(TableWidget);
	box->setLayout(AutoHBoxLayout);
	//管理员才能更改单元格内容，这样一来更新信息的功能也不需要了

	//当用户点击某个单元格时，更新列表中显示的信息
	connect(TableWidget, &QTableWidget::cellClicked, this, &AdminWidgets::flushListWidget);
	//当用户更改某个单元格内的内容时，调用 changeMess() 函数处理 目前只有管理员可以这么做
	if(type == 1)
		connect(TableWidget, &QTableWidget::cellChanged, this, &AdminWidgets::changeMess);
	//将用户更改某个单元格内的内容时，同时还要更新表格中显示的信息
	connect(TableWidget, &QTableWidget::cellChanged, this, &AdminWidgets::flushListWidget);
	return box;
}
/* 构建功能面板
 * 最外层有 QGroupBox 分组框，内部用 QVBoxLayout 将整个区域分为上下两部分，分别嵌入 QListWidget 和 QGridLayout
 * QGridLayout 内包含添加、删除、保存、退出按钮和 1 个实现查找功能的单行输入框。
*/
QGroupBox* AdminWidgets::createMenu()
{
	QGroupBox* box = new QGroupBox("功能面板");
	QVBoxLayout* VBoxLayout = new QVBoxLayout;
	//控件的组装和样式调整
	ListWidget = new QListWidget;
	QGridLayout* Buts = new QGridLayout;
	AddBtn = new QPushButton("添加");
	DelBtn = new QPushButton("删除");
	SaveBtn = new QPushButton("保存");
	ExitBtn = new QPushButton("退出");
	if (type != 1)
	{
		AddBtn->setEnabled(false);
		DelBtn->setEnabled(false);
		SaveBtn->setEnabled(false);
	}
	FindEdit = new QLineEdit;
	if(type != 1)
		FindEdit->setPlaceholderText("输入姓名查找...(按Enter键结束)");
	else
		FindEdit->setPlaceholderText("输入姓名或证件号查找...(按Enter键结束)");
	FindEdit->setClearButtonEnabled(true);
	FindEdit->setStyleSheet("QLineEdit{padding:3,3,3,3;}");
	Buts->addWidget(AddBtn, 0, 0);
	Buts->addWidget(DelBtn, 0, 1);
	Buts->addWidget(FindEdit, 1, 0, 1, 0);
	Buts->addWidget(SaveBtn, 2, 0);
	Buts->addWidget(ExitBtn, 2, 1);

	VBoxLayout->addWidget(ListWidget, 4);
	VBoxLayout->addLayout(Buts, 2);
	//槽和信号的连接设置
	box->setLayout(VBoxLayout);
	//点击添加按钮，执行 addBox() 
	connect(AddBtn, &QPushButton::clicked, this, &AdminWidgets::AddBox);
	//点击删除按钮，执行 delFun() 
	connect(DelBtn, &QPushButton::clicked, this, &AdminWidgets::delFun);
	//当向输入框内输入信息后，执行 findMess() 
	connect(FindEdit, &QLineEdit::returnPressed, this, &AdminWidgets::findMess);
	//点击退出按钮，关闭主窗口
	connect(ExitBtn, &QPushButton::clicked, this, &AdminWidgets::close);
	//点击保存按钮，执行 saveMess() 
	connect(SaveBtn, &QPushButton::clicked, this, &AdminWidgets::saveMess);
	return box;
}
//当点击添加按钮时，弹出添加信息的子窗口
void AdminWidgets::AddBox() {
	messBox = new EditMessBox;
	//当添加学生信息窗口关闭时，更新表格，同时清空列表中显示的信息
	QObject::connect(messBox, &EditMessBox::closeBox, this, &AdminWidgets::flushTable);
	QObject::connect(messBox, &EditMessBox::closeBox, ListWidget, &QListWidget::clear);
	messBox->exec();
}

//刷新表格中的内容，当界面初始化、添加和删除信息后，都需要对表格内容进行更新
void AdminWidgets::flushTable() {
	//更新表格内容前，要断开与 cellChanged 信号关联的所有槽，否则会导致程序闪退
	disconnect(TableWidget, &QTableWidget::cellChanged, 0, 0);
	//同时在此期间将表格设置为不可排序，否则在读取文件的时候会因为文件顺序和表格顺序问题导致内存读写冲突
	TableWidget->setSortingEnabled(false);
	QFile* file;
	if (checkList == 1)
		file = new QFile(studentList);
	else if (checkList == 2)
		file = new QFile(teacherList);
	else if (checkList == 3)
		file = new QFile(visitorList);
	file->open(QIODevice::ReadOnly);
	QDataStream dataStr(file);
	QString qid, qname, qage, qusername, qroom, qbuilding, qpassword, qphone, qstart_time, qstay_reason, qaddress, qclass, qfin_time, qcode;
	TableWidget->setRowCount(0);
	//学生和管理员不同
	if (type == 1)
	{
		while (!dataStr.atEnd()) {
			TableWidget->setRowCount(TableWidget->rowCount() + 1);
			dataStr >> qclass >> qname >> qid >> qage >> qbuilding >> qroom >> qaddress >> qphone >> qstart_time >> qfin_time >> qstay_reason >> qcode >> qusername >> qpassword;
			TableWidget->setItem(TableWidget->rowCount() - 1, 0, new QTableWidgetItem(qclass));
			TableWidget->setItem(TableWidget->rowCount() - 1, 1, new QTableWidgetItem(qname));
			TableWidget->setItem(TableWidget->rowCount() - 1, 2, new QTableWidgetItem(qid));
			TableWidget->setItem(TableWidget->rowCount() - 1, 3, new QTableWidgetItem(qage));
			TableWidget->setItem(TableWidget->rowCount() - 1, 4, new QTableWidgetItem(qbuilding));
			TableWidget->setItem(TableWidget->rowCount() - 1, 5, new QTableWidgetItem(qroom));
			TableWidget->setItem(TableWidget->rowCount() - 1, 6, new QTableWidgetItem(qaddress));
			TableWidget->setItem(TableWidget->rowCount() - 1, 7, new QTableWidgetItem(qphone));
			TableWidget->setItem(TableWidget->rowCount() - 1, 8, new QTableWidgetItem(qstart_time));
			TableWidget->setItem(TableWidget->rowCount() - 1, 9, new QTableWidgetItem(qfin_time));
			TableWidget->setItem(TableWidget->rowCount() - 1, 10, new QTableWidgetItem(qstay_reason));
			TableWidget->setItem(TableWidget->rowCount() - 1, 11, new QTableWidgetItem(qcode));
			TableWidget->setItem(TableWidget->rowCount() - 1, 12, new QTableWidgetItem(qusername));
			TableWidget->setItem(TableWidget->rowCount() - 1, 13, new QTableWidgetItem(qpassword));
		}
	}
	else
	{
		while (!dataStr.atEnd()) {
			TableWidget->setRowCount(TableWidget->rowCount() + 1);
			dataStr >> qclass >> qname >> qid >> qage >> qbuilding >> qroom >> qaddress >> qphone >> qstart_time >> qfin_time >> qstay_reason >> qcode >> qusername >> qpassword;
			TableWidget->setItem(TableWidget->rowCount() - 1, 0, new QTableWidgetItem(qclass));
			TableWidget->setItem(TableWidget->rowCount() - 1, 1, new QTableWidgetItem(qname));
			TableWidget->setItem(TableWidget->rowCount() - 1, 2, new QTableWidgetItem(qbuilding));
			TableWidget->setItem(TableWidget->rowCount() - 1, 3, new QTableWidgetItem(qphone));
			TableWidget->setItem(TableWidget->rowCount() - 1, 4, new QTableWidgetItem(qstart_time));
			TableWidget->setItem(TableWidget->rowCount() - 1, 5, new QTableWidgetItem(qfin_time));
			TableWidget->setItem(TableWidget->rowCount() - 1, 6, new QTableWidgetItem(qusername));
		}
	}
	file->close();
	//完成更新表格的任务后，重新关联与 cellChanged 相关的槽。
	TableWidget->setSortingEnabled(true);
	if (type == 1)
	{
		connect(TableWidget, &QTableWidget::cellChanged, this, &AdminWidgets::changeMess);
		connect(TableWidget, &QTableWidget::cellChanged, this, &AdminWidgets::flushListWidget);
	}
}
//更新列表中显示的信息
void AdminWidgets::flushListWidget(int row) {
	//当列表中有信息时，直接修改即可
	if (type == 1)
	{
		if (checkList == 1)
		{
			if (ListWidget->count() > 0) {
				ListWidget->item(0)->setText("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("学号/身份证号：" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("年龄：" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("楼栋号：" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("房号：" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("家庭地址：" + TableWidget->item(row, 6)->text());
				ListWidget->item(7)->setText("联系方式：" + TableWidget->item(row, 7)->text());
				ListWidget->item(8)->setText("留校起始时间：" + TableWidget->item(row, 8)->text());
				ListWidget->item(9)->setText("离校时间：" + TableWidget->item(row, 9)->text());
				ListWidget->item(10)->setText("留校原因：" + TableWidget->item(row, 10)->text());
				ListWidget->item(11)->setText("健康码状态：" + TableWidget->item(row, 11)->text());
				ListWidget->item(12)->setText("用户名：" + TableWidget->item(row, 12)->text());
				ListWidget->item(13)->setText("密码：" + TableWidget->item(row, 13)->text());
			}
			else {
				ListWidget->addItem("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("学号/身份证号：" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("年龄：" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("楼栋号：" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("房号：" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("家庭地址：" + TableWidget->item(row, 6)->text());
				ListWidget->addItem("联系方式：" + TableWidget->item(row, 7)->text());
				ListWidget->addItem("留校起始时间：" + TableWidget->item(row, 8)->text());
				ListWidget->addItem("离校时间：" + TableWidget->item(row, 9)->text());
				ListWidget->addItem("留校原因：" + TableWidget->item(row, 10)->text());
				ListWidget->addItem("健康码状态：" + TableWidget->item(row, 11)->text());
				ListWidget->addItem("用户名：" + TableWidget->item(row, 12)->text());
				ListWidget->addItem("密码：" + TableWidget->item(row, 13)->text());
			}
		}
		else if (checkList == 2)
		{
			if (ListWidget->count() > 0) {
				ListWidget->item(0)->setText("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("工号/身份证号：" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("年龄：" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("所属单位：" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("校内住址/办公室：" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("家庭住址：" + TableWidget->item(row, 6)->text());
				ListWidget->item(7)->setText("联系方式：" + TableWidget->item(row, 7)->text());
				ListWidget->item(8)->setText("留校起始时间：" + TableWidget->item(row, 8)->text());
				ListWidget->item(9)->setText("离校时间：" + TableWidget->item(row, 9)->text());
				ListWidget->item(10)->setText("留校原因：" + TableWidget->item(row, 10)->text());
				ListWidget->item(11)->setText("健康码状态：" + TableWidget->item(row, 11)->text());
				ListWidget->item(12)->setText("用户名：" + TableWidget->item(row, 12)->text());
				ListWidget->item(13)->setText("密码：" + TableWidget->item(row, 13)->text());
			}
			else {
				ListWidget->addItem("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("学号/身份证号：" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("年龄：" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("所属单位：" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("校内住址/办公室：" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("家庭地址：" + TableWidget->item(row, 6)->text());
				ListWidget->addItem("联系方式：" + TableWidget->item(row, 7)->text());
				ListWidget->addItem("留校起始时间：" + TableWidget->item(row, 8)->text());
				ListWidget->addItem("离校时间：" + TableWidget->item(row, 9)->text());
				ListWidget->addItem("留校原因：" + TableWidget->item(row, 10)->text());
				ListWidget->addItem("健康码状态：" + TableWidget->item(row, 11)->text());
				ListWidget->addItem("用户名：" + TableWidget->item(row, 12)->text());
				ListWidget->addItem("密码：" + TableWidget->item(row, 13)->text());
			}
		}
		else if (checkList == 3)
		{
			if (ListWidget->count() > 0) {
				ListWidget->item(0)->setText("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("身份证号：" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("年龄：" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("所属单位/楼栋：" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("校内住址/办公室：" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("家庭住址：" + TableWidget->item(row, 6)->text());
				ListWidget->item(7)->setText("联系方式：" + TableWidget->item(row, 7)->text());
				ListWidget->item(8)->setText("留校起始时间：" + TableWidget->item(row, 8)->text());
				ListWidget->item(9)->setText("离校时间：" + TableWidget->item(row, 9)->text());
				ListWidget->item(10)->setText("来访原因：" + TableWidget->item(row, 10)->text());
				ListWidget->item(11)->setText("健康码状态：" + TableWidget->item(row, 11)->text());
				ListWidget->item(12)->setText("用户名：" + TableWidget->item(row, 12)->text());
				ListWidget->item(13)->setText("密码：" + TableWidget->item(row, 13)->text());
			}
			else {
				ListWidget->addItem("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("身份证号：" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("年龄：" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("所属单位/楼栋：" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("校内住址/办公室：" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("家庭地址：" + TableWidget->item(row, 6)->text());
				ListWidget->addItem("联系方式：" + TableWidget->item(row, 7)->text());
				ListWidget->addItem("留校起始时间：" + TableWidget->item(row, 8)->text());
				ListWidget->addItem("离校时间：" + TableWidget->item(row, 9)->text());
				ListWidget->addItem("来访原因：" + TableWidget->item(row, 10)->text());
				ListWidget->addItem("健康码状态：" + TableWidget->item(row, 11)->text());
				ListWidget->addItem("用户名：" + TableWidget->item(row, 12)->text());
				ListWidget->addItem("密码：" + TableWidget->item(row, 13)->text());
			}
		}
	}
	else
	{
		if (checkList == 3)
		{
			if (ListWidget->count() > 0)
			{
				ListWidget->item(0)->setText("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("所属单位/楼栋：" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("联系方式：" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("留校起始时间：" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("离校时间：" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("用户名：" + TableWidget->item(row, 6)->text());
			}
			else {
				ListWidget->addItem("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("所属单位/楼栋：" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("联系方式：" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("留校起始时间：" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("离校时间：" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("用户名：" + TableWidget->item(row, 6)->text());
			}
		}
		else if (checkList == 1)
		{
			if (ListWidget->count() > 0)
			{
				ListWidget->item(0)->setText("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("楼栋号：" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("联系方式：" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("留校起始时间：" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("离校时间：" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("用户名：" + TableWidget->item(row, 6)->text());
			}
			else {
				ListWidget->addItem("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("楼栋号：" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("联系方式：" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("留校起始时间：" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("离校时间：" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("用户名：" + TableWidget->item(row, 6)->text());
			}
		}
		else if (checkList == 2)
		{
			if (ListWidget->count() > 0)
			{
				ListWidget->item(0)->setText("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("所属单位：" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("联系方式：" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("留校起始时间：" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("离校时间：" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("用户名：" + TableWidget->item(row, 6)->text());
			}
			else {
				ListWidget->addItem("身份：" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("姓名：" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("所属单位：" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("联系方式：" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("留校起始时间：" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("离校时间：" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("用户名：" + TableWidget->item(row, 6)->text());
			}
		}
	}
	//TableWidget->setSortingEnabled(true);
}
/* 删除人员信息
 * 思路：将除目标人员外，其它人的信息拷贝到一个临时文件中，然后删除原来的文件，并将临时文件的文件名改为和原文件相同的名称。
*/
void AdminWidgets::delFun()
{
	QList<QTableWidgetItem*>items = TableWidget->selectedItems();
	//判断用户是否在表格中选中了某个人的信息，只有选中之后，才能执行删除操作
	if (items.count() > 0) {
		QMessageBox::StandardButton result = QMessageBox::question(this, "删除", "确定要删除姓名为【" + items.at(1)->text() + "】的人员吗？");
		if (result == QMessageBox::Yes) {
			QString qid, qname, qage, qusername, qroom, qbuilding, qpassword, qphone, qstart_time, qstay_reason, qaddress, qclass, qfin_time, qcode;
			QString currentTempFile;
			QString currentFile;
			switch (checkList)
			{
			case 1:
				currentFile = studentList;
				currentTempFile = temp_studentList;
				break;
			case 2:
				currentFile = teacherList;
				currentTempFile = temp_teacherList;
				break;
			case 3:
				currentFile = visitorList;
				currentTempFile = temp_visitorList;
				break;
			default:
				break;
			}
			QFile* file;
			file = new QFile(currentFile);
			file->open(QIODevice::ReadOnly);
			QDataStream readDataStr(file);

			QFile* tempFile = new QFile(currentTempFile);
			tempFile->open(QIODevice::WriteOnly);
			QDataStream writeDataStr(tempFile);

			while (!readDataStr.atEnd()) 
			{
				readDataStr >> qclass >> qname >> qid >> qage >> qbuilding >> qroom >> qaddress >> qphone >> qstart_time >> qfin_time >> qstay_reason >> qcode >> qusername >> qpassword;
				if (qname != items.at(1)->text()) 
				{
					writeDataStr << qclass << qname << qid << qage << qbuilding << qroom << qaddress << qphone << qstart_time << qfin_time << qstay_reason << qcode << qusername << qpassword;
				}
			}
			tempFile->close();
			file->close();
			//删除原文件，将临时文件重命名为和原文件相同的名字
			file->remove();
			tempFile->rename(currentFile);
			//更新数组
			if (checkList == 1)
			{
				StudentUser[0].read();
			}
			else if (checkList == 2)
			{
				TeacherUser[0].read();
			}
			else
			{
				VisitorUser[0].read();
			}
			flushTable();
			ListWidget->clear();
		}
	}
	else {
		QMessageBox::warning(this, "提示", "请选择要删除的人员");
	}
}

//根据输入框中的姓名，在表格中查找目标人员
void AdminWidgets::findMess()
{
	qint32 count = TableWidget->rowCount();
	bool findSuccess = false;
	if (count > 0) {
		for (qint32 i = 0; i < count; i++) {
			QString name = TableWidget->item(i, 1)->text();
			QString id = TableWidget->item(i, 2)->text();
			if (name == FindEdit->text() || (id == FindEdit->text() && type == 1)) //管理员可以通过姓名和证件号查找人员，其他用户只能通过姓名查找
			{
				findSuccess = true;
				TableWidget->selectRow(i);
				flushListWidget(i);
				break;
			}
		}
		if (findSuccess == false) {
			QMessageBox::information(this, "查找失败", "当前表格中没有【" + FindEdit->text() + "】");
		}
	}

}


/* 更改信息
 * 思路：逐一将信息拷贝到另一个临时文件中，当读取到要更改的信息时，将更改后的信息写入临时文件。最终，临时文件中存储的是更改后所有人的信息。
 * 拷贝完成后，删除原文件，将临时文件的名称改为和原文件一样。
*/
void AdminWidgets::changeMess(int row)
{
	QString qclass, qid, qname, qage, qusername, qroom, qbuilding, qpassword, qphone, qstart_time, qstay_reason, qaddress, qfin_time, qcode;
	QString Name = TableWidget->item(row, 1)->text();
	QFile* file;
	QString currentTempFile;
	QString currentFile;
	switch (checkList)
	{
	case 1:
		currentFile = studentList;
		currentTempFile = temp_studentList;
		break;
	case 2:
		currentFile = teacherList;
		currentTempFile = temp_teacherList;
		break;
	case 3:
		currentFile = visitorList;
		currentTempFile = temp_visitorList;
		break;
	default:
		break;
	}
	//QFile file(studentList);
	file = new QFile(currentFile);
	file->open(QIODevice::ReadOnly);
	QDataStream readDataStr(file);

	//QFile tempFile(temp_studentList);
	QFile* tempFile = new QFile(currentTempFile);
	tempFile->open(QIODevice::WriteOnly);
	QDataStream writeDataStr(tempFile);

	while (!readDataStr.atEnd()) {
		readDataStr >> qclass >> qname >> qid 
			>> qage >> qbuilding >> qroom 
			>> qaddress >> qphone >> qstart_time 
			>> qfin_time >> qstay_reason >> qcode >> qusername >> qpassword;
		if (qname != Name) {
			writeDataStr << qclass << qname << qid << qage << qbuilding << qroom << qaddress << qphone << qstart_time << qfin_time << qstay_reason << qcode << qusername << qpassword;
		}
		else {
			for (int i = 0; i < TableWidget->columnCount(); i++) {
				writeDataStr << TableWidget->item(row, i)->text();
			}
		}
	}
	tempFile->close();
	file->close();
	file->remove();
	tempFile->rename(studentList);
	//更新数组中的数据
	if (checkList == 1)
	{
		StudentUser[0].read();
	}
	else if (checkList == 2)
	{
		TeacherUser[0].read();
	}
	else
	{
		VisitorUser[0].read();
	}
}

//保存信息，将表格中的信息重新存储到文件中
void AdminWidgets::saveMess()
{
	QFile* file;
	if (checkList == 1)
		file = new QFile(studentList);
	else if (checkList == 2)
		file = new QFile(teacherList);
	else if (checkList == 3)
		file = new QFile(visitorList);
	file->open(QIODevice::WriteOnly);
	QDataStream dataStr(file);

	for (int i = 0; i < TableWidget->rowCount(); i++) {
		for (int j = 0; j < TableWidget->columnCount(); j++) {
			dataStr << TableWidget->item(i, j)->text();
		}
	}
	file->close();
	QMessageBox::information(this, "保存", "保存成功！");
}


AdminWidgets::~AdminWidgets()
{
}