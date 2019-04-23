#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "datatrans.h"
#include <iostream>
#include <QQmlComponent>
#include <QQuickWindow>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));
    if(engine.rootObjects().isEmpty())
    {
        std::cout<<"rootObjects are empty"<<std::endl;
        return -1;
    }else
    {
        std::cout<<engine.rootObjects().count()<<std::endl;
    }
    QQuickWindow* window = qobject_cast<QQuickWindow*>(engine.rootObjects().at(0));
    DataTrans datatrans(window);
    return app.exec();
}
