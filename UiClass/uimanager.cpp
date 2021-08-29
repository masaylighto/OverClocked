#include "uimanager.h"

#include <QIcon>




UiManager::UiManager()
{
    homepage *page = new homepage();
    page->Qmlflow=Qmlflow;


    Qmlflow->engine=engine;

    Qmlflow->loadpage(QUrl(QStringLiteral("qrc:/Ui/Home/Home.qml")));

    GiveCppClassToQMl(page,"homeClass");
page->GetConfigContnet();

}

void UiManager::GiveCppClassToQMl(QObject *Class,QString ClassName)
{
    engine->rootContext()->setContextProperty(ClassName,Class);
}



