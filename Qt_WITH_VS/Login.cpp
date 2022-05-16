//Login.cpp
#include"Login.h"
using namespace std;
//管理人员保存
//ADMIN_User AdminUser[SIZE];
STUDENT_User StudentUser[SIZE];
VISITOR_User VisitorUser[SIZE];
TEACHER_User TeacherUser[SIZE];
vector<ADMIN_User>AdminUser(SIZE);//此处设置为vector类型的原因是方便后续删除管理员，数组类型的插入和删除效率是很低的
extern int Pos;
//对基类方法的瞎定义

int User::read()
{
	return 1;
}
bool User::UserIsExisted(const QString& value)
{
	return 1;
}
int User::save()
{
	return 1;
}
//对管理员save/read/UserisExisted方法的定义
void ADMIN_User::save()
{
	ofstream ofile;
	ofile.open(adminList, ios::app | ios::out);
	ofile << this->getUsername().toStdString() << "\n" 
		<< this->getPassword().toStdString() << "\n";
	ofile.close();
}

void ADMIN_User::total_save()
{
	ofstream ofile;
	ofile.open(adminList, ios::out | ios::trunc);//直接清空文件重新写入
	for (int i = 0; i < SIZE && !AdminUser[i].getUsername().isEmpty(); ++i) 
	{
		ofile << AdminUser[i].getUsername().toStdString() << "\n" <<
			AdminUser[i].getPassword().toStdString() << "\n";
	}
	ofile.close();
}

int ADMIN_User::read()
{
	ifstream ifile;
	ifile.open(adminList, ios::in);
	int adscount = 0;
	for (int i = 0; !ifile.eof(); i++)
	{
		string us, ps;
		us = AdminUser[i].getUsername().toStdString();
		ps = AdminUser[i].getPassword().toStdString();
		ifile >> us;
		ifile >> ps;
		AdminUser[i].setUsername(QString::fromStdString(us));
		AdminUser[i].setPassword(QString::fromStdString(ps));
		adscount++;
	}
	ifile.close();
	return adscount;
}
bool ADMIN_User::UserIsExisted(const QString& value)
{
	ifstream ifile;
	ifile.open(adminList, ios::in);
	for (int i = 0; !ifile.eof(); ++i)
	{
		string us, ps;
		us = AdminUser[i].getUsername().toStdString();
		ps = AdminUser[i].getPassword().toStdString();
		ifile >> us;
		ifile >> ps;
		if (AdminUser[i].getUsername() == value)
		{
			ifile.close();
			return true;
		}
	}
	ifile.close();
	return false;
}

//对学生
int STUDENT_User::save()
{
	QFile* tempFile;
	QFile* File;
	QString currentTempFile = temp_studentList;
	QString currentFile = studentList;

	tempFile = new QFile(currentTempFile);
	File = new QFile(currentFile);
	tempFile->open(QIODevice::WriteOnly);

	QDataStream writeDataStr(tempFile);
	for (int i = 0; i < SIZE && !StudentUser[i].getName().isEmpty(); ++i)
	{
		writeDataStr << StudentUser[i].getClass() << StudentUser[i].getName() << StudentUser[i].getId() << StudentUser[i].getAge() << StudentUser[i].getBuilding()
			<< StudentUser[i].getRoom() << StudentUser[i].getAddress() << StudentUser[i].getPhone() << StudentUser[i].getStartTime()
			<< StudentUser[i].getFinTime() << StudentUser[i].getStayReason() << StudentUser[i].getCode() << StudentUser[i].getUsername() << StudentUser[i].getPassword();
	}
	tempFile->close();
	File->close();
	File->remove();//移除原文档
	tempFile->rename(currentFile);//临时文档代替原文档
	return 1;
}
int STUDENT_User::read()
{
	//先读学生
	QFile* file = new QFile(studentList);
	file->open(QIODevice::ReadOnly);
	QDataStream dataStr(file);
	int stucount = 0;
	QString qid, qname, qage, qusername, qroom, qbuilding, qpassword, qphone, qstart_time, qstay_reason, qaddress, qclass, qfin_time, qcode;
	while (!dataStr.atEnd())//把文件里的学生信息写到里面
	{
		dataStr >> qclass >> qname >> qid >> qage >> qbuilding >> qroom >> qaddress >> qphone >> qstart_time >> qfin_time >> qstay_reason >> qcode >> qusername >> qpassword;
		StudentUser[stucount].setClass(qclass);
		StudentUser[stucount].setName(qname);
		StudentUser[stucount].setId(qid);
		StudentUser[stucount].setAge(qage);
		StudentUser[stucount].setBuilding(qbuilding);
		StudentUser[stucount].setRoom(qroom);
		StudentUser[stucount].setAddress(qaddress);
		StudentUser[stucount].setPhone(qphone);
		StudentUser[stucount].setStartTime(qstart_time);
		StudentUser[stucount].setFinTime(qfin_time);
		StudentUser[stucount].setStayReason(qstay_reason);
		StudentUser[stucount].setCode(qcode);
		StudentUser[stucount].setUsername(qusername);
		StudentUser[stucount].setPassword(qpassword);
		stucount++;
	}
	file->close();
	return stucount;
}
bool STUDENT_User::UserIsExisted(const QString& value)
{
	for (int i = 0; StudentUser[i].getUsername() != ""; ++i)
	{
		if (StudentUser[i].getUsername() == value)
		{
			return true;
		}
	}
	return false;
}

int TEACHER_User::save()
{
	QFile* tempFile;
	QFile* File;
	QString currentTempFile = temp_teacherList;
	QString currentFile = teacherList;

	tempFile = new QFile(currentTempFile);
	File = new QFile(currentFile);
	tempFile->open(QIODevice::WriteOnly);

	QDataStream writeDataStr(tempFile);
	for (int i = 0; i < SIZE && !TeacherUser[i].getName().isEmpty(); ++i)
	{
		writeDataStr << TeacherUser[i].getClass() << TeacherUser[i].getName() << TeacherUser[i].getId() << TeacherUser[i].getAge() << TeacherUser[i].getBuilding()
			<< TeacherUser[i].getRoom() << TeacherUser[i].getAddress() << TeacherUser[i].getPhone() << TeacherUser[i].getStartTime()
			<< TeacherUser[i].getFinTime() << TeacherUser[i].getStayReason() << TeacherUser[i].getCode() << TeacherUser[i].getUsername() << TeacherUser[i].getPassword();
	}
	tempFile->close();
	File->close();
	File->remove();//移除原文档
	tempFile->rename(currentFile);//临时文档代替原文档
	return 1;
}
int TEACHER_User::read()
{
	QFile* file = new QFile(teacherList);
	file->open(QIODevice::ReadOnly);
	QDataStream dataStr(file);
	int teacount = 0;
	QString qid, qname, qage, qusername, qroom, qbuilding, qpassword, qphone, qstart_time, qstay_reason, qaddress, qclass, qfin_time, qcode;
	while (!dataStr.atEnd())//把文件里的访客信息写到里面
	{
		dataStr >> qclass >> qname >> qid >> qage >> qbuilding >> qroom >> qaddress >> qphone >> qstart_time >> qfin_time >> qstay_reason >> qcode >> qusername >> qpassword;
		TeacherUser[teacount].setClass(qclass);
		TeacherUser[teacount].setName(qname);
		TeacherUser[teacount].setId(qid);
		TeacherUser[teacount].setAge(qage);
		TeacherUser[teacount].setBuilding(qbuilding);
		TeacherUser[teacount].setRoom(qroom);
		TeacherUser[teacount].setAddress(qaddress);
		TeacherUser[teacount].setPhone(qphone);
		TeacherUser[teacount].setStartTime(qstart_time);
		TeacherUser[teacount].setFinTime(qfin_time);
		TeacherUser[teacount].setStayReason(qstay_reason);
		TeacherUser[teacount].setCode(qcode);
		TeacherUser[teacount].setUsername(qusername);
		TeacherUser[teacount].setPassword(qpassword);
		teacount++;
	}
	file->close();
	return teacount;
}
bool TEACHER_User::UserIsExisted(const QString& value)
{
	for (int i = 0; TeacherUser[i].getUsername() != ""; ++i)
	{
		if (TeacherUser[i].getUsername() == value)
		{
			return true;
		}
	}
	return false;
}
//对访客
int VISITOR_User::save()
{
	QFile* tempFile;
	QFile* File;
	QString currentTempFile = temp_visitorList;
	QString currentFile = visitorList;

	tempFile = new QFile(currentTempFile);
	File = new QFile(currentFile);
	tempFile->open(QIODevice::WriteOnly);

	QDataStream writeDataStr(tempFile);
	for (int i = 0; i < SIZE && !VisitorUser[i].getName().isEmpty(); ++i)
	{
		writeDataStr << VisitorUser[i].getClass() << VisitorUser[i].getName() << VisitorUser[i].getId() << VisitorUser[i].getAge() << VisitorUser[i].getBuilding()
			<< VisitorUser[i].getRoom() << VisitorUser[i].getAddress() << VisitorUser[i].getPhone() << VisitorUser[i].getStartTime()
			<< VisitorUser[i].getFinTime() << VisitorUser[i].getStayReason() << VisitorUser[i].getCode() << VisitorUser[i].getUsername() << VisitorUser[i].getPassword();
	}
	tempFile->close();
	File->close();
	File->remove();//移除原文档
	tempFile->rename(currentFile);//临时文档代替原文档
	return 1;
}
int VISITOR_User::read()
{
	QFile* file = new QFile(visitorList);
	file->open(QIODevice::ReadOnly);
	QDataStream dataStr(file);
	int viscount = 0;
	QString qid, qname, qage, qusername, qroom, qbuilding, qpassword, qphone, qstart_time, qstay_reason, qaddress, qclass, qfin_time, qcode;
	while (!dataStr.atEnd())//把文件里的访客信息写到里面
	{
		dataStr >> qclass >> qname >> qid >> qage >> qbuilding >> qroom >> qaddress >> qphone >> qstart_time >> qfin_time >> qstay_reason >> qcode >> qusername >> qpassword;
		VisitorUser[viscount].setClass(qclass);
		VisitorUser[viscount].setName(qname);
		VisitorUser[viscount].setId(qid);
		VisitorUser[viscount].setAge(qage);
		VisitorUser[viscount].setBuilding(qbuilding);
		VisitorUser[viscount].setRoom(qroom);
		VisitorUser[viscount].setAddress(qaddress);
		VisitorUser[viscount].setPhone(qphone);
		VisitorUser[viscount].setStartTime(qstart_time);
		VisitorUser[viscount].setFinTime(qfin_time);
		VisitorUser[viscount].setStayReason(qstay_reason);
		VisitorUser[viscount].setCode(qcode);
		VisitorUser[viscount].setUsername(qusername);
		VisitorUser[viscount].setPassword(qpassword);
		viscount++;
	}
	file->close();
	return viscount;
}
bool VISITOR_User::UserIsExisted(const QString& value)
{
	for (int i = 0; VisitorUser[i].getUsername() != ""; ++i)
	{
		if (VisitorUser[i].getUsername() == value)
		{
			return true;
		}
	}
	return false;
}


QString User::getName()const
{
	return Name;
}

QString User::getAge()const
{
	return Age;
}

QString User::getId()const
{
	return Id;
}

QString User::getBuilding()const
{
	return Building;
}

QString User::getRoom()const
{
	return Room;
}

QString User::getAddress()const
{
	return Address;
}

QString User::getPhone()const
{
	return Phone;
}

QString User::getStartTime()const
{
	return StartTime;
}

QString User::getFinTime()const
{
	return FinTime;
}

QString User::getStayReason()const
{
	return stay_reason;
}

QString User::getUsername()const
{
	return Username;
}

QString User::getPassword()const
{
	return Password;
}

QString User::getClass()const
{
	return Class;
}

QString User::getCode()const
{
	return code;
}

void User::setName(const QString& value)
{
	Name = value;
}

void User::setAge(const QString& value)
{
	Age = value;
}

void User::setId(const QString& value)
{
	Id = value;
}

void User::setBuilding(const QString& value)
{
	Building = value;
}

void User::setRoom(const QString& value)
{
	Room = value;
}

void User::setAddress(const QString& value)
{
	Address = value;
}

void User::setPhone(const QString& value)
{
	Phone = value;
}

void User::setStartTime(const QString& value)
{
	StartTime = value;
}

void User::setFinTime(const QString& value)
{
	FinTime = value;
}

void User::setStayReason(const QString& value)
{
	stay_reason = value;
}

void User::setUsername(const QString& value)
{
	Username = value;
}

void User::setPassword(const QString& value)
{
	Password = value;
}

void User::setClass(const QString& value)
{
	Class = value;
}

void User::setCode(const QString& value)
{
	code = value;
}

QString ADMIN_User::getUsername() const
{
	return Username;
}
void ADMIN_User::setUsername(const QString& value)
{
	Username = value;
}
QString ADMIN_User::getPassword() const
{
	return Password;
}
void ADMIN_User::setPassword(const QString& value)
{
	Password = value;
}
Login::Login(QObject *parent)
	: QObject(parent)
{
}


Login::~Login()
{
}
