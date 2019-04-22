/****************************************************************************
** Copyright(c) 2019 HOMAY INFORMATION.
** All rights reserved.
** Contact: homay@homaytech.com
**
** File: sequence_stack.h
** Brief: Sequential implementation of the Stack
**
** Create Date: 2019-04-22
** Author: xiaoshuangYin
** Description:
**
** Update Date:
** Author:
** Description:
*******************************************************************************/
#ifndef SEQUENCE_STACK_H
#define SEQUENCE_STACK_H

#include "iystack.h"
#define STACK_SIZE 200

class SequenceStack : public IYStack<int>
{
public:
    SequenceStack();
    ~SequenceStack();
public:
    void Create();
    void Destroy();
    void Clear();
    bool Empty();
    int GetTop();
    int Pop();
    void Push(const int& elem);
    int GetLength();

private:
    int m_top_index_;
    int m_size_;
    int* m_pdata_;
    bool m_binited;
};

#endif // SEQUENCE_STACK_H
