#include "mainUI.h"
#include "LoginDialog.h"
#include <QtWidgets/QApplication>
#include<qsavefile.h>
#include<qdialog.h>
#include<qstring.h>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include"qlineedit.h"
#include"Login.h"
#include "AdminWidgets.h"
#include"MyInformation.h"
#if defined(_MSC_VER) && (_MSC_VER >= 1600)    
# pragma execution_character_set("utf-8")    
#endif
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
extern int type;//=1��Ϊ����Ա =2��Ϊѧ�� =3��Ϊ��ְ�� =4��Ϊ�ÿ� =5��Ϊδע��ķÿ�
extern int Pos;
int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    LoginDialog dlg;
    dlg.setWindowTitle("��¼����");
    ADMIN_User adus;
    STUDENT_User nmus;
    if (dlg.exec() == QDialog::Accepted)
    {
        mainUI w;
        w.show();
        return a.exec();
    }
    else return 0;
}
