// IHM_TP6-7_EX1_Chronometer/widget.h
// Exercice 1 : Chronometer
// BODIN Maxime C2
// 08/04/2022

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QTimer>
#include <QKeyEvent>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

public slots:
    void gameLoop();
    void start();

private:
    int itsCounter = 0;
    QLCDNumber * itsDisplay = new QLCDNumber(this);
    QTimer * itsTimer = new QTimer(this);
    QPushButton * itsStartButton = new QPushButton(this);

    QIcon itsPauseIcon;
    QIcon itsStartIcon;

    void keyPressEvent(QKeyEvent * event);

};
#endif // WIDGET_H
