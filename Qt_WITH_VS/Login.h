#pragma once
//login.h
#include<iostream>
#include<fstream>
#include<string>
#include <conio.h>
#include<qdatastream.h>
#include<ctime>
#include <QString>
#include<qfile.h>
#include <QObject>
#include<qmessagebox.h>
#include<qchar.h>
#include<qwidget.h>
#include <QWidget>
#include<vector>
#include<set>
#include"path.h"
using namespace std;
#if defined(_MSC_VER) && (_MSC_VER >= 1600)    
# pragma execution_character_set("utf-8")    
#endif
#define SIZE 505//����û�����
class User
{
private:
	QString Username;//�û���
	QString Password;//����
	QString Name;//����
	QString Age;//����
	QString Id;//ѧ�š����š����֤�� 
	QString Building;//¥��
	QString Room;//����
	QString Address;//��ͥ��ַ�������
	QString Phone;//��ϵ��ʽ
	QString StartTime;//��У��ʼʱ��
	QString FinTime;//��У����ʱ��
	QString stay_reason;//��Уԭ�������ԭ��
	QString Class;//���
	QString code;//������
public://�ӿں���ԭ��
	QString getClass()const;
	void setClass(const QString& value);

	QString getName() const;
	void setName(const QString& value);

	QString getId() const;
	void setId(const QString& value);

	QString getAge() const;
	void setAge(const QString& value);

	QString getBuilding() const;
	void setBuilding(const QString& value);

	QString getRoom() const;
	void setRoom(const QString& value);

	QString getAddress() const;
	void setAddress(const QString& value);

	QString getPhone() const;
	void setPhone(const QString& value);

	QString getStartTime() const;
	void setStartTime(const QString& value);

	QString getFinTime()const;
	void setFinTime(const QString& value);

	QString getStayReason() const;
	void setStayReason(const QString& value);

	QString getUsername() const;
	void setUsername(const QString& value);

	QString getPassword() const;
	void setPassword(const QString& value);

	QString getCode()const;
	void setCode(const QString& value);
	
	virtual int save();//���棬�൱�ڰ�����������ݵ����ļ�
	virtual int read();//��ȡ���൱�ڰ��ļ������ݴ�������
	virtual bool UserIsExisted(const QString& value);//�ж��û��Ƿ����
	virtual bool IdIsExisted(const QString& value);//�ж�֤�����Ƿ����
};
//����Ա��������
class ADMIN_User
{
private:
	QString Username;//�û���
	QString Password;//����
public:
	QString getUsername() const;
	void setUsername(const QString& value);
	QString getPassword() const;
	void setPassword(const QString& value);
	void save();//�������ļ�ĩβ�������
	void total_save();//��save�������ǣ��������ļ��������ݣ���ȫ��ɾ����
	int read();
	int UserIsExisted(const QString& value);
};
//ѧ�������û���Ļ���
class STUDENT_User :public User
{
public:
	virtual int save();
	virtual int read();
	virtual bool UserIsExisted(const QString& value);
	virtual bool IdIsExisted(const QString& value);//�ж�֤�����Ƿ����

};
//�ÿ������û���Ļ���
class VISITOR_User :public User
{
public:
	virtual int save();
	virtual int read();
	virtual bool UserIsExisted(const QString& value);
	virtual bool IdIsExisted(const QString& value);//�ж�֤�����Ƿ����

};
//��ְ�������û���Ļ���
class TEACHER_User :public User
{
public:
	virtual int save();
	virtual int read();
	virtual bool UserIsExisted(const QString& value);
	virtual bool IdIsExisted(const QString& value);//�ж�֤�����Ƿ����

};
class Login : public QObject
{
	Q_OBJECT

public:
	Login(QObject *parent);
	~Login();
};
