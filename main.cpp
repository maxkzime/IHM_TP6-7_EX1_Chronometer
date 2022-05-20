// IHM_TP6-7_EX1_Chronometer/main.cpp
// Exercice 1 : Chronometer
// BODIN Maxime C2
// 08/04/2022

#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}


