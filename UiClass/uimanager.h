#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "HelperClass/usedlibrary.h"
#include "HelperClass/qmlenginecontroll.h"
#include "UiClass/Home/home.h"
class UiManager
{
    QQmlApplicationEngine *engine = new QQmlApplicationEngine;
    QString LoadedPagePath;


public:

    QmlEngineControll *Qmlflow=new QmlEngineControll;


    UiManager();
    void GiveCppClassToQMl(QObject *,QString );
    void OpenPage(QObject,QString);

};

#endif // UIMANAGER_H
