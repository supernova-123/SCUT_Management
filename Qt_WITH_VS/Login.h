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
#define SIZE 505//最大用户容量
class User
{
private:
	QString Username;//用户名
	QString Password;//密码
	QString Name;//姓名
	QString Age;//年龄
	QString Id;//学号、工号、身份证号 
	QString Building;//楼栋
	QString Room;//房号
	QString Address;//家庭地址或出发地
	QString Phone;//联系方式
	QString StartTime;//留校起始时间
	QString FinTime;//留校结束时间
	QString stay_reason;//留校原因或来访原因
	QString Class;//身份
	QString code;//健康码
public://接口函数原型
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
	
	virtual int save();//保存，相当于把数组里的内容导入文件
	virtual int read();//读取，相当于把文件的内容存入数组
	virtual bool UserIsExisted(const QString& value);//判断用户是否存在
	virtual bool IdIsExisted(const QString& value);//判断证件号是否存在
};
//管理员独立出来
class ADMIN_User
{
private:
	QString Username;//用户名
	QString Password;//密码
public:
	QString getUsername() const;
	void setUsername(const QString& value);
	QString getPassword() const;
	void setPassword(const QString& value);
	void save();//用来往文件末尾添加数据
	void total_save();//和save的区别是，重新往文件再如数据（先全部删除）
	int read();
	int UserIsExisted(const QString& value);
};
//学生类是用户类的基类
class STUDENT_User :public User
{
public:
	virtual int save();
	virtual int read();
	virtual bool UserIsExisted(const QString& value);
	virtual bool IdIsExisted(const QString& value);//判断证件号是否存在

};
//访客类是用户类的基类
class VISITOR_User :public User
{
public:
	virtual int save();
	virtual int read();
	virtual bool UserIsExisted(const QString& value);
	virtual bool IdIsExisted(const QString& value);//判断证件号是否存在

};
//教职工类是用户类的基类
class TEACHER_User :public User
{
public:
	virtual int save();
	virtual int read();
	virtual bool UserIsExisted(const QString& value);
	virtual bool IdIsExisted(const QString& value);//判断证件号是否存在

};
class Login : public QObject
{
	Q_OBJECT

public:
	Login(QObject *parent);
	~Login();
};
