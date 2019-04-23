#include "datatrans.h"

DataTrans::DataTrans(QQuickWindow* window,QObject *parent) : QObject(parent)
{
    m_window_ = window;
    QObject::connect(m_window_, SIGNAL(convertNumber(QString)),
                     this, SLOT(GetInputDecimalNumber(QString)));
    m_pstack_ = new SequenceStack;
    m_pstack_->Create();
}

DataTrans::~DataTrans()
{
    if(nullptr != m_pstack_)
    {
        m_pstack_->Destroy();
        delete m_pstack_;
        m_pstack_ = nullptr;
    }
}

void DataTrans::ConvertDecimal2Octal(int decimal_number)
{
    int temp_number_dec = decimal_number;
    while(temp_number_dec)
    {
        m_pstack_->Push(temp_number_dec%8);
        temp_number_dec=temp_number_dec/8;
    }
}

void DataTrans::GetInputDecimalNumber(QString decimal_number)
{
   int temp_decimal_number = decimal_number.toInt();
   ConvertDecimal2Octal(temp_decimal_number);
   QMetaObject::invokeMethod(m_window_,"showOctalNumber",Q_ARG(QVariant, GetOctalNumber()));
}

QString DataTrans::GetOctalNumber()
{
    QString str_octal_number;
    while(!m_pstack_->Empty())
    {
        str_octal_number.append(QString::number(m_pstack_->Pop()));
    }
    return str_octal_number;
}
