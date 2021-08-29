#ifndef QMLENGINECONTROLL_H
#define QMLENGINECONTROLL_H
#include "HelperClass/usedlibrary.h"
#include<QObject>
#include <QQuickItem>

class QmlEngineControll
{
public:
  QGuiApplication *app;
  QQmlApplicationEngine *engine = new QQmlApplicationEngine;
  QString LoadedPagePath;
  QObject *Page;
  QObject *rootObject;
  QQuickItem * BringObject(QString);
  QmlEngineControll();
  void loadpage(QUrl PageLink);
  int InvokeQmlFunction(QString FunctionName,int Msg);
  void ClosePage();
  void GiveClassToPage(QObject*,QString);


};

#endif // QMLENGINECONTROLL_H
