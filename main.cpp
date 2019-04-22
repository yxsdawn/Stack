#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "sequence_stack.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    IYStack<int>* pstack = new SequenceStack;
    pstack->Create();
    int number_dec = 1348;
    int temp_number_dec = number_dec;
    while(temp_number_dec)
    {
        pstack->Push(temp_number_dec%8);
        temp_number_dec=temp_number_dec/8;
    }

    std::cout<<"the octal number of the decimal number "<<number_dec<< " is ";
    while(!pstack->Empty())
    {
        std::cout<<pstack->Pop();
    }
    std::cout<<std::endl;
    pstack->Destroy();
    return app.exec();
}
