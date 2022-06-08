#include "mainUI.h"
#include<qsavefile.h>
#include<qdialog.h>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include"qlineedit.h"
#include<qlabel.h>
#include<ctime>
#include"LoginDialog.h"
#include<qtimer.h>
#include<qdatetime.h>
#include<string>
#if defined(_MSC_VER) && (_MSC_VER >= 1600)    
# pragma execution_character_set("utf-8")    
#endif
//extern ADMIN_User AdminUser[SIZE];
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern int superAdmin;
extern int type;//=1��Ϊ����Ա =2��Ϊѧ�� =3��Ϊ��ְ�� =4��Ϊ�ÿ� =5��Ϊδע��ķÿ�
extern int Pos;
int checkList;//��ʾ������ĸ���ť:1��ʾѧ���б� 2��ʾ��ְ���б� 3��ʾ�ÿ��б� 4��ʾ�ҵ���Ϣ 5��ʾ��ӹ���Ա 6��ʾ�˳�
mainUI::mainUI(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //���ô�����
    setWindowTitle("Designed by ZhuJinhong&ChaiHao version2.09(Beta)");
    //�ڹ��캯�����һ����ʾʱ���װ��
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    QLabel* permanent = new QLabel;
    permanent->setFrameStyle(QFrame::Box | QFrame::Plain);
    permanent->setText(tr("���ε�¼��ʱ��Ϊ %1").arg(str));
    permanent->setTextFormat(Qt::RichText);
    permanent->setOpenExternalLinks(true);

    //�ŵ�״̬����
    ui.statusBar->addPermanentWidget(permanent);

    //����Ȩ��
    if (superAdmin != -1)
    {
        ui.addAdmin->setEnabled(false);
    }
    if (type == 5)
    {
        ui.information->setEnabled(false);//δע���û�û����Ϣ
    }
    //չʾ���չ㶫�¹�����״�� ʹ�����������GetTodayData.py�������.exe
    //���û�����ӵ�����Ͳ�ִ�г�����ʾ����δ���ӣ���Ȼ��ʾ����֮ǰ������״��
    bool NetworkIsConnected = Ping("www.baidu.com");
    if (NetworkIsConnected)
    {
        QProcess process(this);
        process.startDetached("GetTodayData.exe");
    }
    else
    {
        ui.label->setText(tr("���չ㶫���飨δ���ӵ����磩"));
    }
    ifstream ifile;
    ifile.open("today_province_.txt", ios::in);
    string strs;
    QString target;
    for (int i = 0; !ifile.eof(); ++i)
    {
        ifile >> strs;
        target = QString::fromStdString(strs);
        if (target.contains("�㶫"))
        {
            break;
        }
    }
    QString Total_confirm = target.section(',', 2, 2);
    QString Total_heal = target.section(',', 4, 4);
    QString Total_dead = target.section(',', 5, 5);
    QString New_confirm = target.section(',', 11, 11);
    QString Today_storeConfirm = target.section(',', 16, 16);
    QString Today_heal = target.section(',', 13, 13);
    ui.Data->setText(tr("����ȷ���� %1 ��\n������������ %2 ��\n������������ %3 ��\n�ۼ�ȷ������ %4 ��\n�ۼ��������� %5 ��\n�ۼ��������� %6 ��").arg(New_confirm).arg(Today_storeConfirm).arg(Today_heal).arg(Total_confirm).arg(Total_heal).arg(Total_dead));
    ifile.close();
    
}

bool mainUI::Ping(QString strPingIP)
{
    QProcess pingProcess;
    //��ping��������Ӱٶ� 
    QString strArg = "ping " + strPingIP + " -w 500 -n 2";  //strPingIP Ϊ�ٶȵ�ַ
    pingProcess.start(strArg, QIODevice::ReadOnly);
    pingProcess.waitForFinished(-1);

    QString p_stdout = QString::fromLocal8Bit(pingProcess.readAllStandardOutput());

    qDebug() << p_stdout;
    bool bPingSuccess = false;

    if (p_stdout.contains("TTL=")) //ͨ�������ַ��������ж�ping�Ƿ�ɹ� ��TTL������˵���������ӳɹ� ��֮��û��
    {
        bPingSuccess = true;
    }
    //ʧ��ʱ p_stdoutΪ��Ping �����Ҳ������� www.baidu.com����������ƣ�Ȼ�����ԡ���
    else
    {
        bPingSuccess = false;
    }
    return bPingSuccess;
}
//�˳��¼�
void mainUI::on_logout_clicked()
{
    checkList = 6;
    qApp->quit();
}
//����ѧ���б�
void mainUI::on_student_clicked()
{
    checkList = 1;
    AdminWidgets* adwid = new AdminWidgets;
    adwid->show();
}
//���������Ϣ�б�
void mainUI::on_information_clicked()
{
    checkList = 4;
    if (type == 2)//ѧ��
    {
        MyInformation* stu_infor = new MyInformation;
        stu_infor->show();
    }
    else if (type == 1)//����Ա
    {
        AdminInformation* admin_infor = new AdminInformation;
        admin_infor->show();
    }
    else if(type == 4)//�ÿ�
    {
        VisitorInformation* vis_infor = new VisitorInformation;
        vis_infor->show();
    }
    else if (type == 3)//��ְ��
    {
        TeacherInformation* tea_infor = new TeacherInformation;
        tea_infor->show();
    }
    else if (type == 5)//δע��ÿ�
    {
        QMessageBox::warning(this, tr("����"),
            tr("�㱾��Ӧ��������"),
            QMessageBox::Yes);
    }
}
//�����ְ���б�
void mainUI::on_teacher_clicked()
{
    checkList = 2;
    AdminWidgets* adwid = new AdminWidgets;
    adwid->show();
}
//����ÿ��б�
void mainUI::on_visitor_clicked()
{
    checkList = 3;
    AdminWidgets* adwid = new AdminWidgets;
    adwid->show();
}
//������ӹ���Ա�б�
void mainUI::on_addAdmin_clicked()
{
    checkList = 5;
    AdminTable* add = new AdminTable;
    add->show();
}