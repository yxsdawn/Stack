/****************************************************************************
** Copyright(c) 2019 HOMAY INFORMATION.
** All rights reserved.
** Contact: homay@homaytech.com
**
** File: iystack.h
** Brief: The abstract base class of the stack
**
** Create Date: 2019-04-22
** Author: xiaoshuangYin
** Description:
**
** Update Date:
** Author:
** Description:
*******************************************************************************/

#ifndef IYSTACK_H
#define IYSTACK_H

template<class T>
class IYStack{
public:
    virtual void Create()=0;
    virtual void Destroy()=0;
    virtual void Clear()=0;
    virtual bool Empty()=0;
    virtual T GetTop()=0;
    virtual T Pop()=0;
    virtual void Push(const T& elem)=0;
    virtual int GetLength()=0;
};

#endif // IYSTACK_H
