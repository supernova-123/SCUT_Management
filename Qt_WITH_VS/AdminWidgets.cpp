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
extern int type;//=1��Ϊ����Ա =2��Ϊѧ�� =3��Ϊ��ְ�� =4��Ϊ�ÿ� =5��Ϊδע��ķÿ�
extern int Pos;
extern int checkList;
AdminWidgets::AdminWidgets()
{
	ui.setupUi(this);
	/*
	 * ���������� QHBoxLayout ����Ϊ����������������� Left_Table_Box ʵ�֣��ұ��� Right_Table_Box ʵ��
	*/
	setWindowTitle("��У��Ա����ϵͳ");
	//�ڱ�����ʾ��ǰ�û���
	switch (type)
	{
	case 1:
		setWindowTitle(QLabel::tr("��ǰ�û���%1").arg(AdminUser[Pos].getUsername()));
		break;
	case 2:
		setWindowTitle(QLabel::tr("��ǰ�û���%1").arg(StudentUser[Pos].getUsername()));
		break;
	case 3:
		setWindowTitle(QLabel::tr("��ǰ�û���%1").arg(TeacherUser[Pos].getUsername()));
		break;
	case 4:
		setWindowTitle(QLabel::tr("��ǰ�û���%1").arg(VisitorUser[Pos].getUsername()));
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
//������Ա��Ϣ���
/*Left_Table_Box ��ֻ����һ�� QTableWidget ���ؼ���
Ϊ��ʹ���ߴ�����Ӧ�������ڣ��������ӵ��� QHBoxLayout ���ֹ����С�*/
QGroupBox* AdminWidgets::createMess()
{
	QGroupBox* box = new QGroupBox("��Ա��Ϣ");
	TableWidget = new QTableWidget;
	TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//����βΪ��λѡ��
	if (type == 1)//����Ա����Ϊ���ɼ�
	{
		TableWidget->setColumnCount(14);
		if (checkList == 1)//ѧ��
			TableWidget->setHorizontalHeaderLabels(QStringList() << "���" << "����" << "ѧ��/���֤��" << "����" << "¥��" << "����" <<
				"��ͥסַ" << "��ϵ��ʽ" << "��У��ʼʱ��" << "��Уʱ��" << "��Уԭ��" << "������״̬" << "�û���" << "����");
		else if (checkList == 2)//��ְ��
			TableWidget->setHorizontalHeaderLabels(QStringList() << "���" << "����" << "����/���֤��" << "����" << "��������" << "У��סַ/�칫��" <<
				"��ͥ��ַ" << "��ϵ��ʽ" << "��У��ʼʱ��" << "��Уʱ��" << "��Уԭ��" << "������״̬" << "�û���" << "����");
		else if (checkList == 3)//�ÿ�
			TableWidget->setHorizontalHeaderLabels(QStringList() << "���" << "����" << "���֤��" << "����" << "��������/¥��" << "У��סַ/�칫��" <<
				"��ͥ��ַ" << "��ϵ��ʽ" << "��У��ʼʱ��" << "��Уʱ��" << "����ԭ��" << "������״̬" << "�û���" << "����");
	}
	else//������ֻ�ܿ���������¥������У��ʼʱ�䡢��Уʱ�䡢�û�������ݡ���ϵ��ʽ
	{
		TableWidget->setColumnCount(7);
		if (checkList == 1)//ѧ��
			TableWidget->setHorizontalHeaderLabels(QStringList() << "���" << "����" << "¥����" << "��ϵ��ʽ" << "��У��ʼʱ��" << "��Уʱ��" << "�û���");
		else if (checkList == 2)//��ְ��
			TableWidget->setHorizontalHeaderLabels(QStringList() << "���" << "����" << "��������"  << "��ϵ��ʽ" << "��У��ʼʱ��" << "��Уʱ��" << "�û���");
		else if (checkList == 3)//�ÿ�
			TableWidget->setHorizontalHeaderLabels(QStringList() << "���" << "����" << "��������/¥��"  << "��ϵ��ʽ" << "��У��ʼʱ��" << "��Уʱ��"  << "�û���");
	}
	TableWidget->setSortingEnabled(true);//���ñ�ͷ����������
	flushTable();
	QHBoxLayout* AutoHBoxLayout = new QHBoxLayout;
	AutoHBoxLayout->addWidget(TableWidget);
	box->setLayout(AutoHBoxLayout);
	//����Ա���ܸ��ĵ�Ԫ�����ݣ�����һ��������Ϣ�Ĺ���Ҳ����Ҫ��

	//���û����ĳ����Ԫ��ʱ�������б�����ʾ����Ϣ
	connect(TableWidget, &QTableWidget::cellClicked, this, &AdminWidgets::flushListWidget);
	//���û�����ĳ����Ԫ���ڵ�����ʱ������ changeMess() �������� Ŀǰֻ�й���Ա������ô��
	if(type == 1)
		connect(TableWidget, &QTableWidget::cellChanged, this, &AdminWidgets::changeMess);
	//���û�����ĳ����Ԫ���ڵ�����ʱ��ͬʱ��Ҫ���±������ʾ����Ϣ
	connect(TableWidget, &QTableWidget::cellChanged, this, &AdminWidgets::flushListWidget);
	return box;
}
/* �����������
 * ������� QGroupBox ������ڲ��� QVBoxLayout �����������Ϊ���������֣��ֱ�Ƕ�� QListWidget �� QGridLayout
 * QGridLayout �ڰ�����ӡ�ɾ�������桢�˳���ť�� 1 ��ʵ�ֲ��ҹ��ܵĵ��������
*/
QGroupBox* AdminWidgets::createMenu()
{
	QGroupBox* box = new QGroupBox("�������");
	QVBoxLayout* VBoxLayout = new QVBoxLayout;
	//�ؼ�����װ����ʽ����
	ListWidget = new QListWidget;
	QGridLayout* Buts = new QGridLayout;
	AddBtn = new QPushButton("���");
	DelBtn = new QPushButton("ɾ��");
	SaveBtn = new QPushButton("����");
	ExitBtn = new QPushButton("�˳�");
	if (type != 1)
	{
		AddBtn->setEnabled(false);
		DelBtn->setEnabled(false);
		SaveBtn->setEnabled(false);
	}
	FindEdit = new QLineEdit;
	if(type != 1)
		FindEdit->setPlaceholderText("������������...(��Enter������)");
	else
		FindEdit->setPlaceholderText("����������֤���Ų���...(��Enter������)");
	FindEdit->setClearButtonEnabled(true);
	FindEdit->setStyleSheet("QLineEdit{padding:3,3,3,3;}");
	Buts->addWidget(AddBtn, 0, 0);
	Buts->addWidget(DelBtn, 0, 1);
	Buts->addWidget(FindEdit, 1, 0, 1, 0);
	Buts->addWidget(SaveBtn, 2, 0);
	Buts->addWidget(ExitBtn, 2, 1);

	VBoxLayout->addWidget(ListWidget, 4);
	VBoxLayout->addLayout(Buts, 2);
	//�ۺ��źŵ���������
	box->setLayout(VBoxLayout);
	//�����Ӱ�ť��ִ�� addBox() 
	connect(AddBtn, &QPushButton::clicked, this, &AdminWidgets::AddBox);
	//���ɾ����ť��ִ�� delFun() 
	connect(DelBtn, &QPushButton::clicked, this, &AdminWidgets::delFun);
	//�����������������Ϣ��ִ�� findMess() 
	connect(FindEdit, &QLineEdit::returnPressed, this, &AdminWidgets::findMess);
	//����˳���ť���ر�������
	connect(ExitBtn, &QPushButton::clicked, this, &AdminWidgets::close);
	//������水ť��ִ�� saveMess() 
	connect(SaveBtn, &QPushButton::clicked, this, &AdminWidgets::saveMess);
	return box;
}
//�������Ӱ�ťʱ�����������Ϣ���Ӵ���
void AdminWidgets::AddBox() {
	messBox = new EditMessBox;
	//�����ѧ����Ϣ���ڹر�ʱ�����±��ͬʱ����б�����ʾ����Ϣ
	QObject::connect(messBox, &EditMessBox::closeBox, this, &AdminWidgets::flushTable);
	QObject::connect(messBox, &EditMessBox::closeBox, ListWidget, &QListWidget::clear);
	messBox->exec();
}

//ˢ�±���е����ݣ��������ʼ������Ӻ�ɾ����Ϣ�󣬶���Ҫ�Ա�����ݽ��и���
void AdminWidgets::flushTable() {
	//���±������ǰ��Ҫ�Ͽ��� cellChanged �źŹ��������вۣ�����ᵼ�³�������
	disconnect(TableWidget, &QTableWidget::cellChanged, 0, 0);
	//ͬʱ�ڴ��ڼ佫�������Ϊ�������򣬷����ڶ�ȡ�ļ���ʱ�����Ϊ�ļ�˳��ͱ��˳�����⵼���ڴ��д��ͻ
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
	//ѧ���͹���Ա��ͬ
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
	//��ɸ��±�����������¹����� cellChanged ��صĲۡ�
	TableWidget->setSortingEnabled(true);
	if (type == 1)
	{
		connect(TableWidget, &QTableWidget::cellChanged, this, &AdminWidgets::changeMess);
		connect(TableWidget, &QTableWidget::cellChanged, this, &AdminWidgets::flushListWidget);
	}
}
//�����б�����ʾ����Ϣ
void AdminWidgets::flushListWidget(int row) {
	//���б�������Ϣʱ��ֱ���޸ļ���
	if (type == 1)
	{
		if (checkList == 1)
		{
			if (ListWidget->count() > 0) {
				ListWidget->item(0)->setText("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("������" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("ѧ��/���֤�ţ�" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("���䣺" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("¥���ţ�" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("���ţ�" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("��ͥ��ַ��" + TableWidget->item(row, 6)->text());
				ListWidget->item(7)->setText("��ϵ��ʽ��" + TableWidget->item(row, 7)->text());
				ListWidget->item(8)->setText("��У��ʼʱ�䣺" + TableWidget->item(row, 8)->text());
				ListWidget->item(9)->setText("��Уʱ�䣺" + TableWidget->item(row, 9)->text());
				ListWidget->item(10)->setText("��Уԭ��" + TableWidget->item(row, 10)->text());
				ListWidget->item(11)->setText("������״̬��" + TableWidget->item(row, 11)->text());
				ListWidget->item(12)->setText("�û�����" + TableWidget->item(row, 12)->text());
				ListWidget->item(13)->setText("���룺" + TableWidget->item(row, 13)->text());
			}
			else {
				ListWidget->addItem("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("������" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("ѧ��/���֤�ţ�" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("���䣺" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("¥���ţ�" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("���ţ�" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("��ͥ��ַ��" + TableWidget->item(row, 6)->text());
				ListWidget->addItem("��ϵ��ʽ��" + TableWidget->item(row, 7)->text());
				ListWidget->addItem("��У��ʼʱ�䣺" + TableWidget->item(row, 8)->text());
				ListWidget->addItem("��Уʱ�䣺" + TableWidget->item(row, 9)->text());
				ListWidget->addItem("��Уԭ��" + TableWidget->item(row, 10)->text());
				ListWidget->addItem("������״̬��" + TableWidget->item(row, 11)->text());
				ListWidget->addItem("�û�����" + TableWidget->item(row, 12)->text());
				ListWidget->addItem("���룺" + TableWidget->item(row, 13)->text());
			}
		}
		else if (checkList == 2)
		{
			if (ListWidget->count() > 0) {
				ListWidget->item(0)->setText("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("������" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("����/���֤�ţ�" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("���䣺" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("������λ��" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("У��סַ/�칫�ң�" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("��ͥסַ��" + TableWidget->item(row, 6)->text());
				ListWidget->item(7)->setText("��ϵ��ʽ��" + TableWidget->item(row, 7)->text());
				ListWidget->item(8)->setText("��У��ʼʱ�䣺" + TableWidget->item(row, 8)->text());
				ListWidget->item(9)->setText("��Уʱ�䣺" + TableWidget->item(row, 9)->text());
				ListWidget->item(10)->setText("��Уԭ��" + TableWidget->item(row, 10)->text());
				ListWidget->item(11)->setText("������״̬��" + TableWidget->item(row, 11)->text());
				ListWidget->item(12)->setText("�û�����" + TableWidget->item(row, 12)->text());
				ListWidget->item(13)->setText("���룺" + TableWidget->item(row, 13)->text());
			}
			else {
				ListWidget->addItem("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("������" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("ѧ��/���֤�ţ�" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("���䣺" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("������λ��" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("У��סַ/�칫�ң�" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("��ͥ��ַ��" + TableWidget->item(row, 6)->text());
				ListWidget->addItem("��ϵ��ʽ��" + TableWidget->item(row, 7)->text());
				ListWidget->addItem("��У��ʼʱ�䣺" + TableWidget->item(row, 8)->text());
				ListWidget->addItem("��Уʱ�䣺" + TableWidget->item(row, 9)->text());
				ListWidget->addItem("��Уԭ��" + TableWidget->item(row, 10)->text());
				ListWidget->addItem("������״̬��" + TableWidget->item(row, 11)->text());
				ListWidget->addItem("�û�����" + TableWidget->item(row, 12)->text());
				ListWidget->addItem("���룺" + TableWidget->item(row, 13)->text());
			}
		}
		else if (checkList == 3)
		{
			if (ListWidget->count() > 0) {
				ListWidget->item(0)->setText("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("������" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("���֤�ţ�" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("���䣺" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("������λ/¥����" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("У��סַ/�칫�ң�" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("��ͥסַ��" + TableWidget->item(row, 6)->text());
				ListWidget->item(7)->setText("��ϵ��ʽ��" + TableWidget->item(row, 7)->text());
				ListWidget->item(8)->setText("��У��ʼʱ�䣺" + TableWidget->item(row, 8)->text());
				ListWidget->item(9)->setText("��Уʱ�䣺" + TableWidget->item(row, 9)->text());
				ListWidget->item(10)->setText("����ԭ��" + TableWidget->item(row, 10)->text());
				ListWidget->item(11)->setText("������״̬��" + TableWidget->item(row, 11)->text());
				ListWidget->item(12)->setText("�û�����" + TableWidget->item(row, 12)->text());
				ListWidget->item(13)->setText("���룺" + TableWidget->item(row, 13)->text());
			}
			else {
				ListWidget->addItem("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("������" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("���֤�ţ�" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("���䣺" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("������λ/¥����" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("У��סַ/�칫�ң�" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("��ͥ��ַ��" + TableWidget->item(row, 6)->text());
				ListWidget->addItem("��ϵ��ʽ��" + TableWidget->item(row, 7)->text());
				ListWidget->addItem("��У��ʼʱ�䣺" + TableWidget->item(row, 8)->text());
				ListWidget->addItem("��Уʱ�䣺" + TableWidget->item(row, 9)->text());
				ListWidget->addItem("����ԭ��" + TableWidget->item(row, 10)->text());
				ListWidget->addItem("������״̬��" + TableWidget->item(row, 11)->text());
				ListWidget->addItem("�û�����" + TableWidget->item(row, 12)->text());
				ListWidget->addItem("���룺" + TableWidget->item(row, 13)->text());
			}
		}
	}
	else
	{
		if (checkList == 3)
		{
			if (ListWidget->count() > 0)
			{
				ListWidget->item(0)->setText("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("������" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("������λ/¥����" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("��ϵ��ʽ��" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("��У��ʼʱ�䣺" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("��Уʱ�䣺" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("�û�����" + TableWidget->item(row, 6)->text());
			}
			else {
				ListWidget->addItem("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("������" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("������λ/¥����" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("��ϵ��ʽ��" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("��У��ʼʱ�䣺" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("��Уʱ�䣺" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("�û�����" + TableWidget->item(row, 6)->text());
			}
		}
		else if (checkList == 1)
		{
			if (ListWidget->count() > 0)
			{
				ListWidget->item(0)->setText("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("������" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("¥���ţ�" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("��ϵ��ʽ��" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("��У��ʼʱ�䣺" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("��Уʱ�䣺" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("�û�����" + TableWidget->item(row, 6)->text());
			}
			else {
				ListWidget->addItem("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("������" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("¥���ţ�" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("��ϵ��ʽ��" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("��У��ʼʱ�䣺" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("��Уʱ�䣺" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("�û�����" + TableWidget->item(row, 6)->text());
			}
		}
		else if (checkList == 2)
		{
			if (ListWidget->count() > 0)
			{
				ListWidget->item(0)->setText("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->item(1)->setText("������" + TableWidget->item(row, 1)->text());
				ListWidget->item(2)->setText("������λ��" + TableWidget->item(row, 2)->text());
				ListWidget->item(3)->setText("��ϵ��ʽ��" + TableWidget->item(row, 3)->text());
				ListWidget->item(4)->setText("��У��ʼʱ�䣺" + TableWidget->item(row, 4)->text());
				ListWidget->item(5)->setText("��Уʱ�䣺" + TableWidget->item(row, 5)->text());
				ListWidget->item(6)->setText("�û�����" + TableWidget->item(row, 6)->text());
			}
			else {
				ListWidget->addItem("��ݣ�" + TableWidget->item(row, 0)->text());
				ListWidget->addItem("������" + TableWidget->item(row, 1)->text());
				ListWidget->addItem("������λ��" + TableWidget->item(row, 2)->text());
				ListWidget->addItem("��ϵ��ʽ��" + TableWidget->item(row, 3)->text());
				ListWidget->addItem("��У��ʼʱ�䣺" + TableWidget->item(row, 4)->text());
				ListWidget->addItem("��Уʱ�䣺" + TableWidget->item(row, 5)->text());
				ListWidget->addItem("�û�����" + TableWidget->item(row, 6)->text());
			}
		}
	}
	//TableWidget->setSortingEnabled(true);
}
/* ɾ����Ա��Ϣ
 * ˼·������Ŀ����Ա�⣬�����˵���Ϣ������һ����ʱ�ļ��У�Ȼ��ɾ��ԭ�����ļ���������ʱ�ļ����ļ�����Ϊ��ԭ�ļ���ͬ�����ơ�
*/
void AdminWidgets::delFun()
{
	QList<QTableWidgetItem*>items = TableWidget->selectedItems();
	//�ж��û��Ƿ��ڱ����ѡ����ĳ���˵���Ϣ��ֻ��ѡ��֮�󣬲���ִ��ɾ������
	if (items.count() > 0) {
		QMessageBox::StandardButton result = QMessageBox::question(this, "ɾ��", "ȷ��Ҫɾ������Ϊ��" + items.at(1)->text() + "������Ա��");
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
			//ɾ��ԭ�ļ�������ʱ�ļ�������Ϊ��ԭ�ļ���ͬ������
			file->remove();
			tempFile->rename(currentFile);
			//��������
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
		QMessageBox::warning(this, "��ʾ", "��ѡ��Ҫɾ������Ա");
	}
}

//����������е��������ڱ���в���Ŀ����Ա
void AdminWidgets::findMess()
{
	qint32 count = TableWidget->rowCount();
	bool findSuccess = false;
	if (count > 0) {
		for (qint32 i = 0; i < count; i++) {
			QString name = TableWidget->item(i, 1)->text();
			QString id = TableWidget->item(i, 2)->text();
			if (name == FindEdit->text() || (id == FindEdit->text() && type == 1)) //����Ա����ͨ��������֤���Ų�����Ա�������û�ֻ��ͨ����������
			{
				findSuccess = true;
				TableWidget->selectRow(i);
				flushListWidget(i);
				break;
			}
		}
		if (findSuccess == false) {
			QMessageBox::information(this, "����ʧ��", "��ǰ�����û�С�" + FindEdit->text() + "��");
		}
	}

}


/* ������Ϣ
 * ˼·����һ����Ϣ��������һ����ʱ�ļ��У�����ȡ��Ҫ���ĵ���Ϣʱ�������ĺ����Ϣд����ʱ�ļ������գ���ʱ�ļ��д洢���Ǹ��ĺ������˵���Ϣ��
 * ������ɺ�ɾ��ԭ�ļ�������ʱ�ļ������Ƹ�Ϊ��ԭ�ļ�һ����
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
	//���������е�����
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

//������Ϣ��������е���Ϣ���´洢���ļ���
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
	QMessageBox::information(this, "����", "����ɹ���");
}


AdminWidgets::~AdminWidgets()
{
}