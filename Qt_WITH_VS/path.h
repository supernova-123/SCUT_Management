#pragma once
#ifndef PATH_H
#define teacherList "teacher.txt"
#define studentList "student.txt"
#define visitorList "visitor.txt"
#define others "others.txt"
#define temp_studentList "temp_student.txt"
#define temp_teacherList "temp_teacher.txt"
#define temp_visitorList "temp_visitor.txt"
#define temp_others "temp_others.txt"
#define adminList "AdminUser.txt"
#define temp_adminList "temp_admin.txt"
#endif // PATH_H
#include <QObject>

class path : public QObject
{
	Q_OBJECT

public:
	path(QObject *parent);
	~path();
};
