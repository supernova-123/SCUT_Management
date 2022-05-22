#include "EditMessBox.h"
extern int checkList;
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
extern int Pos;
extern int type;//=1��Ϊ����Ա =2��Ϊѧ�� =3��Ϊ��ְ�� =4��Ϊ�ÿ� =5��Ϊδע��ķÿ�
EditMessBox::EditMessBox()
{
    ui.setupUi(this);
    /*
     * QVBoxLayout �ֲ������з��� QFormLayout �� QHBoxLayout
     * QFormLayout �з��ö�����������
     * QHBoxLayout �з���������ť
    */
    setWindowTitle("�����Ա��Ϣ");
    QVBoxLayout* VBox = new QVBoxLayout;
    QFormLayout* FormLayout = new QFormLayout;
    qclass = new QComboBox;
    qclass->addItem("ѧ��");
    qclass->addItem("��ְ��");
    qclass->addItem("�ÿ�");
    //���Ի�������ѡ��ͬ����ݣ����������Ϣʱ�л���ݵĳ�ʼ��
    switch (checkList)
    {
    case 1:
        qclass->setCurrentIndex(0); break;
    case 2:
        qclass->setCurrentIndex(1); break;
    default:
        qclass->setCurrentIndex(2);
        break;
    }
    qclass->setEnabled(false);//��������������ֻ��ѡ������������
    qid = new QLineEdit;
    qname = new QLineEdit;
    qbuilding = new QLineEdit;
    qroom = new QLineEdit;
    qphone = new QLineEdit;
    qaddress = new QLineEdit;
    qpassword = new QLineEdit;
    qusername = new QLineEdit;
    qage = new QLineEdit;
    if (checkList != 3)
    {
        qstayReason = new QComboBox;
        qstayReason->addItem("��Ը��У");
        qstayReason->addItem("����");
        qstayReason->addItem("��ס�������޷���У");
    }
    else
    {
        qvisReason = new QLineEdit;
    }
    qstartTime = new QDateEdit(QDate::currentDate(), this);
    qstartTime->setMinimumDate(QDate::currentDate().addDays(-365 * 3));
    qstartTime->setMaximumDate(QDate::currentDate().addDays(365 * 3));
    qfinTime = new QDateEdit(QDate::currentDate().addDays(1), this);
    qfinTime->setMinimumDate(QDate::currentDate().addDays(-365 * 3));
    qfinTime->setMaximumDate(QDate::currentDate().addDays(365 * 3));
    qcode = new QComboBox;
    qcode->addItem("����");
    qcode->addItem("����");
    qcode->addItem("����24Сʱ����");
    qcode->addItem("����48Сʱ����");
    qcode->addItem("����72Сʱ����");
    qcode->addItem("����");
    qcode->setCurrentIndex(5);
    FormLayout->addRow("��ݣ�", qclass);
    FormLayout->addRow("������", qname);
    if (checkList == 1)
        FormLayout->addRow("ѧ��/���֤�ţ�", qid);
    else if (checkList == 2)FormLayout->addRow("����/���֤�ţ�", qid);
    else FormLayout->addRow("���֤�ţ�", qid);
    FormLayout->addRow("���䣺", qage);
    if (checkList == 1)
    {
        FormLayout->addRow("¥����", qbuilding);
        FormLayout->addRow("���ţ�", qroom);
    }
    else if(checkList == 2)
    {
        FormLayout->addRow("����������", qbuilding);
        FormLayout->addRow("У��סַ/�칫�ң�", qroom);
    }
    else
    {
        FormLayout->addRow("��������/¥����", qbuilding);
        FormLayout->addRow("У��סַ/�칫�ң�", qroom);
    }
    FormLayout->addRow("��ͥ��ַ��", qaddress);
    FormLayout->addRow("��ϵ��ʽ��", qphone);
    FormLayout->addRow("��У��ʼʱ�䣺", qstartTime);
    FormLayout->addRow("��Уʱ�䣺", qfinTime);
    if (checkList == 2 || checkList == 1)
        FormLayout->addRow("��Уԭ��", qstayReason);
    else
        FormLayout->addRow("����ԭ��", qvisReason);
    FormLayout->addRow("������״̬��", qcode);
    FormLayout->addRow("�û�����", qusername);
    FormLayout->addRow("���룺", qpassword);
    FormLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
    QHBoxLayout* HBox = new QHBoxLayout;
    submit = new QPushButton("�ύ");
    cancel = new QPushButton("ȡ��");
    HBox->addWidget(submit);
    HBox->addWidget(cancel);
    VBox->addLayout(FormLayout, 4);
    VBox->addLayout(HBox, 1);
    this->setLayout(VBox);
    //����ύ��ťʱ��������Ա��Ϣ���浽�ļ���
    QObject::connect(submit, &QPushButton::clicked, this, &EditMessBox::saveMess);
    //���ȡ����ťʱ���ر������Ϣ����
    QObject::connect(cancel, &QPushButton::clicked, this, &EditMessBox::close);
}
// ���û�����ύ��ťʱ��������Ϣ
void EditMessBox::saveMess() {
    
    User* us;
    switch (checkList)
    {
    case 1:
        us = new STUDENT_User; break;
    case 2:
        us = new TEACHER_User; break;
    default:
        us = new VISITOR_User;
        break;
    }
    if (this->qname->text().isEmpty() || this->qbuilding->text().isEmpty() || this->qaddress->text().isEmpty() ||
        this->qusername->text().isEmpty() || this->qpassword->text().isEmpty() || this->qroom->text().isEmpty() || 
        this->qphone->text().isEmpty() || this->qid->text().isEmpty() || this->qage->text().isEmpty())
    {
        QMessageBox::warning(this, tr("��ʾ"), tr("�뽫��Ϣ��д������"), QMessageBox::Yes);
        return;
    }
    us->setClass(this->qclass->currentText());
    us->setId(this->qid->text());
    us->setName(this->qname->text());
    us->setAge(this->qage->text());
    //�жϸ�����������������ѧ������Ҫ���룬�������סC4������Ҫ�ֶ��޸� �����ѧ��֮�����Ҫ���룬������ס��ѧ�����ľƵ�
    if (this->qbuilding->text() != "C4" && this->qclass->currentText() == "ѧ��" && (this->qstayReason
        ->currentText() == "����" || this->qcode->currentText() == "����"))
    {
        int click = QMessageBox::warning(this, tr("��ʾ"),
            tr("���������ѧ����Ҫ��סC4\nѡ���ǡ���ȷ�����棬ϵͳ�Զ��޸�ΪC4�͸���״̬\n"
                "ѡ�񡰷񡱽�������дҳ��"),
            QMessageBox::Yes, QMessageBox::No);
        if (click == QMessageBox::Yes)
        {
            us->setBuilding("C4");
            us->setStayReason("����");
        }
        else return;
    }
    else if (this->qclass->currentText() != "ѧ��" && (this->qstayReason
        ->currentText() == "����" || this->qcode->currentText() == "����") && this->qbuilding->text() != "��ѧ�����ľƵ�")
    {
        int click = QMessageBox::warning(this, tr("��ʾ"),
            tr("��������Ľ�ְ���ͷÿ���Ҫ��ס��ѧ�����ľƵ�\nѡ���ǡ���ȷ�����棬ϵͳ�Զ��޸�Ϊ���ľƵ�͸���״̬\n"
                "ѡ�񡰷񡱽�������дҳ��"),
            QMessageBox::Yes, QMessageBox::No);
        if (click == QMessageBox::Yes)
        {
            us->setBuilding("��ѧ�����ľƵ�");
            us->setStayReason("����");
        }
        else return;
    }
    else us->setBuilding(this->qbuilding->text());
    us->setRoom(this->qroom->text());
    us->setPhone(this->qphone->text());
    us->setAddress(this->qaddress->text());
    us->setStartTime(this->qstartTime->date().toString(Qt::ISODate));
    //�����������У��ʼʱ��Ƚ���ʱ�仹��ģ���Ϊ�߼����������û�������д
    if (this->qstartTime->date().toString(Qt::ISODate) > this->qfinTime->date().toString(Qt::ISODate))
    {
        QMessageBox::warning(this, tr("���棡"),
            tr("��ѡ����ʵ���У���ڣ�"),
            QMessageBox::Yes);
        return;
    }
    else us->setFinTime(this->qfinTime->date().toString(Qt::ISODate));
    if (checkList != 3)
        us->setStayReason(this->qstayReason->currentText());
    else us->setStayReason(this->qvisReason->text());
    us->setCode(this->qcode->currentText());
    if (us->UserIsExisted(this->qusername->text()))
    {
        QMessageBox::warning(this, tr("��ʾ��δ�ܳɹ�ע��"),
            tr("�û����ظ�������������û���"),
            QMessageBox::Yes);
        return;
    }
    us->setUsername(this->qusername->text());
    us->setPassword(this->qpassword->text());
    QFile* file;
    //���ݲ�ͬ���ͷ��벻ͬ���ļ�
    if (checkList == 1)
        file = new QFile(studentList);
    else if (checkList == 2)
        file = new QFile(teacherList);
    else if (checkList == 3)
        file = new QFile(visitorList);
    else file = new QFile(others);
    file->open(QIODevice::WriteOnly | QIODevice::Append);
    QDataStream dataStr(file);
    dataStr << us->getClass() << us->getName() << us->getId() << us->getAge() << us->getBuilding()
        << us->getRoom() << us->getAddress() << us->getPhone() << us->getStartTime() << us->getFinTime() << us->getStayReason()
        << us->getCode() << us->getUsername() << us->getPassword();
    //���¶�������
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
    file->close();
    this->close();
    emitCloseBox();
}
void EditMessBox::emitCloseBox()
{
    emit closeBox();
}
EditMessBox::~EditMessBox()
{
}
