#include "home.h"





#include<fstream>

#include <QVariant>
#include <stdio.h>





homepage::homepage()
{




}

void homepage::GetInitialValue(std::string line)
{
    line=  line.substr(0,line.length()-1);
    QString Line(line.c_str());
    if (Line.contains("arm_freq")) {
        int Postion= line.find_first_of("arm_freq")+9;
        line=line.substr(Postion,line.length());
        Qmlflow->BringObject("frequencySlider")->setProperty("value",line.c_str());
    }
    if (Line.contains("over_voltage")) {
        int Postion= line.find_first_of("over_voltage")+13;
        line=line.substr(Postion,line.length());

        Qmlflow->BringObject("voltageSlider")->setProperty("value",line.c_str());
    }
}

void homepage::GetConfigContnet()
{
    std::ifstream reader("/boot/config.txt");
    if(!reader.good())
    {
        QMessageBox msgBox;
        msgBox.setText("Cant Find the Config file");
        msgBox.exec();
        delete Qmlflow->engine->children()[0];
    }
    std::string line;
    while (std::getline(reader,line))
    {
        line.append("\n");

        Lines.append(line.c_str());
        GetInitialValue(line);
    }
    reader.close();
}

void homepage::_ChangeVoltage(QString Voltage)
{

    EditTextInFile("over_voltage",Voltage);
}

void homepage::_ChangeFrequency(QString Frequency)
{
    EditTextInFile("arm_freq",Frequency);
}

bool homepage::EditTextInFile(QString OrginalText, QString NewValue)
{
    try
    {



        std::ofstream writer("/boot/config.txt");
        for(int Index=0;Index<Lines.count();Index++){
            if(Lines[Index].contains(OrginalText.toStdString().c_str())){

                QString line;
                line.append(OrginalText.toStdString().c_str());
                line.append("=");
                line.append(NewValue.toStdString().c_str());
                line.append("\n");
                Lines[Index]=line;

            }
            writer<<Lines[Index].toStdString().c_str();

        }
        writer.close();

    }
    catch (...)
    {

    }
}
