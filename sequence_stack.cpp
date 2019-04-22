#include "sequence_stack.h"
#include <QDebug>

SequenceStack :: SequenceStack()
{
    m_top_index_ = -1;
    m_pdata_ = nullptr;
    m_size_ = 0;
    m_binited = false;
}

SequenceStack :: ~SequenceStack()
{
    Destroy();
}

void SequenceStack :: Create()
{
    if(m_binited)
    {
        qDebug()<<QStringLiteral("�Ѿ�����");
        return;
    }

    m_pdata_ = new int[STACK_SIZE];
    if(nullptr != m_pdata_)
    {
        m_size_ = STACK_SIZE;
        m_binited = true;
    }
}

void SequenceStack :: Destroy()
{
    if(!m_binited)
    {
        qDebug()<<QStringLiteral("���ȴ���");
        return;
    }

    if(m_pdata_)
    {
        delete[] m_pdata_;
        m_pdata_ = nullptr;
        m_size_ = 0;
        m_binited = false;
    }

}

void SequenceStack :: Clear()
{
    if(!m_binited)
    {
        qDebug()<<QStringLiteral("���ȴ���");
        return;
    }

    m_top_index_ = -1;
}

bool SequenceStack :: Empty()
{
    if(!m_binited)
    {
        qDebug()<<QStringLiteral("���ȴ���");
        return false;
    }

    if(m_top_index_ == -1)
    {
        return true;
    }else
    {
        return false;
    }
}

int SequenceStack :: GetTop()
{
    if(!m_binited)
    {
        qDebug()<<QStringLiteral("���ȴ���");
        return -1;
    }

    if(m_top_index_ == -1)
    {
        qDebug()<<QStringLiteral("�ձ�,��ȡջ��ʧ��");
        return -1;
    }


    return m_pdata_[m_top_index_];
}

int SequenceStack :: Pop()
{
    if(!m_binited)
    {
        qDebug()<<QStringLiteral("���ȴ���");
        return -1;
    }

    if(m_top_index_ == -1)
    {
        qDebug()<<QStringLiteral("�ձ�,Popʧ��");
        return -1;
    }

    int n_elem = m_pdata_[m_top_index_];
    m_top_index_--;
    return n_elem;
}

void SequenceStack :: Push(const int& elem)
{
    if(!m_binited)
    {
        qDebug()<<QStringLiteral("���ȴ���");
        return;
    }

    if(m_top_index_ == STACK_SIZE-1)
    {
        qDebug()<<QStringLiteral("��ջ����");
        return;
    }


    m_top_index_++;
    m_pdata_[m_top_index_]=elem;
}

int SequenceStack :: GetLength()
{
    if(!m_binited)
    {
        qDebug()<<QStringLiteral("���ȴ���");
        return -1;
    }
    return m_top_index_+1;
}
