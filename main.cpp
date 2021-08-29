#include "HelperClass/usedlibrary.h"
#include "UiClass/uimanager.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{


     QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/Assets/Icons/Logo.png"));


    UiManager Ui;
    Ui.Qmlflow->app=&app;




    return app.exec();
}
