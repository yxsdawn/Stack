#ifndef DATATRANS_H
#define DATATRANS_H

#include <QObject>
#include "sequence_stack.h"
#include<QQuickWindow>

class DataTrans : public QObject
{
    Q_OBJECT
public:
    explicit DataTrans(QQuickWindow* window=0,QObject *parent = 0);
    ~DataTrans();
signals:
    void showOctalResult(QString octal_number);
public slots:
    void GetInputDecimalNumber(QString decimal_number);
public:
    void ConvertDecimal2Octal(int decimal_number);
    QString GetOctalNumber();
private:
    IYStack<int>* m_pstack_;
    QQuickWindow* m_window_;
};

#endif // DATATRANS_H
