#include "qmlenginecontroll.h"
#include<QDebug>
QmlEngineControll::QmlEngineControll()
{

}

void QmlEngineControll::loadpage(QUrl PageLink)
{
    LoadedPagePath=PageLink.toString();
    engine->load(PageLink);
    if(engine->rootObjects().isEmpty())
    {
        return ;
    }
    rootObject=engine->rootObjects().first();

}

int QmlEngineControll::InvokeQmlFunction(QString FunctionName,int Msg)
{


    int returnedValue;
    QMetaObject::invokeMethod(rootObject,FunctionName.toStdString().c_str(), Q_RETURN_ARG(int, returnedValue),
                              Q_ARG(int, Msg));
    return  returnedValue;


}

void QmlEngineControll::ClosePage()
{
    engine->deleteLater();
    engine = new QQmlApplicationEngine();
}

void QmlEngineControll::GiveClassToPage(QObject* Class,QString ClassName)
{

    engine->rootContext()->setContextProperty(ClassName,Class);


}

QQuickItem * QmlEngineControll::BringObject(QString name)
{
    return qobject_cast<QQuickItem*>(engine->rootObjects().first()->findChild<QObject*>(name,Qt::FindChildrenRecursively));
}
