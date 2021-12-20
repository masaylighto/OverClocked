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

void homepage::_RestoreDefault()
{
_ReomveVoltageFromFile();
_ReomveFrequencyFromFile();
}

void homepage::_ChangeVoltage(QString Voltage)
{

    EditTextInFile("over_voltage",Voltage);
}

void homepage::_ChangeValues(QString Voltage, QString Frequency)
{
    QMessageBox msgBox;
    msgBox.setText("Are you sure you want to save this configurtion. more also in saving case you will be in need to restart your device");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
   if( msgBox.exec()==QMessageBox::Save)
   {
       _ChangeVoltage(Voltage);
       _ChangeFrequency(Frequency);
   }

}

void homepage::_ReomveVoltageFromFile()
{
    RemoveLineFromFile("over_voltage");

}

void homepage::_ReomveFrequencyFromFile()
{
    RemoveLineFromFile("arm_freq");
}

QString homepage::PerpareAConfigLine(QString Key, QString Value)
{
    QString line=Key;
    line.append("=");
    line.append(Value.toStdString().c_str());
    line.append("\n");
    return line;
}



void homepage::_ChangeFrequency(QString Frequency)
{
    EditTextInFile("arm_freq",Frequency);
}

bool homepage::EditTextInFile(QString ConfigKey, QString Value)
{
    bool Exist=false;

    try
    {
        std::ofstream writer("/boot/config.txt");
        for(int Index=0;Index<Lines.count();Index++)
        {
            if(Lines[Index].contains(ConfigKey.toStdString().c_str()))
            {Exist=true;
                Lines[Index]=PerpareAConfigLine(ConfigKey,Value);
            }
            writer<<Lines[Index].toStdString().c_str();

        }
        if(!Exist)
        {
            Lines.append(PerpareAConfigLine(ConfigKey,Value));
            writer<<Lines.last().toStdString().c_str();
        }
        writer.close();

    }
    catch (std::exception &e)
    {
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setStandardButtons(QMessageBox::Ok);
    }
}

bool homepage::RemoveLineFromFile(QString OrginalText)
{
    try
    {

        std::ofstream writer("/boot/config.txt");
        for(int Index=0;Index<Lines.count();Index++){
            if(Lines[Index].contains(OrginalText))
            {
                Lines[Index]="";
            }
            writer<<Lines[Index].toStdString().c_str();

        }
        writer.close();

    }
    catch (std::exception &e)
    {
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setStandardButtons(QMessageBox::Ok);
    }
}

