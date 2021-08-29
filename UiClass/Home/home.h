#ifndef HOME_H
#define HOME_H
#include "HelperClass/usedlibrary.h"

#include "HelperClass/qmlenginecontroll.h"
#include "UiClass/uimanager.h"
class homepage : public QObject
{
  Q_OBJECT
public:

       QmlEngineControll *Qmlflow;
       homepage();
       QList<QString> Lines;
        void GetInitialValue(std::string);
        void GetConfigContnet();
       Q_INVOKABLE void _ChangeVoltage(QString Voltage);
       Q_INVOKABLE void _ChangeValues(QString Voltage,QString Frequency);
       Q_INVOKABLE void _ChangeFrequency(QString Frequency);
       bool EditTextInFile(QString OrginalText,QString NewValue);

};

#endif // HOME_H
