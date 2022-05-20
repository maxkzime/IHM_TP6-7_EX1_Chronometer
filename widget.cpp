// IHM_TP6-7_EX1_Chronometer/widget.cpp
// Exercice 1 : Chronometer
// BODIN Maxime C2
// 08/04/2022

#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Chronometer");

    setMinimumSize(600,300);
    setMaximumSize(600,300);

    connect(itsTimer,&QTimer::timeout,this,&Widget::gameLoop);

    QHBoxLayout * layout = new QHBoxLayout(this);

    // Counter initialization
    itsDisplay->display(0);
    itsDisplay->setMinimumSize(250,250);
    itsDisplay->setDigitCount(5);
    layout->addWidget(itsDisplay);


    itsPauseIcon.addPixmap(QPixmap(":/imgs/pause.png").scaled(QSize(156,156)));
    itsStartIcon.addPixmap(QPixmap(":/imgs/start.png").scaled(QSize(156,156)));

    setWindowIcon(itsStartIcon);

    // Button initialization
    itsStartButton->setMinimumSize(250,250);
    itsStartButton->setIcon(itsStartIcon);
    //itsStartButton->setText("Start");
    itsStartButton->setIconSize(QSize(250,250));
    layout->addWidget(itsStartButton);

    connect(itsStartButton,SIGNAL(clicked()),this,SLOT(start()));


    setLayout(layout);
}


void Widget::gameLoop()
{
    itsCounter++;
    itsDisplay->display(itsCounter);
}


/* If the chronometer is already running we stop it,
 * else we start it. We update the icon of the widget and of the button accordingly.
 */
void Widget::start()
{
    if(itsTimer->isActive()){
        itsTimer->stop();
        //itsStartButton->setText("Start");
        itsStartButton->setIcon(itsStartIcon);
        setWindowIcon(itsStartIcon);
    }else{
        itsTimer->start(1000);
        //itsStartButton->setText("Pause");
        itsStartButton->setIcon(itsPauseIcon);
        setWindowIcon(itsPauseIcon);
    }
}


/* Press enter or space to start the chronometer or stop it.
 * Press R to reset the chronometer.
 */
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Space)
        start();

    else if(event->key() == Qt::Key_R){
        start();
        itsCounter = 0;
        itsDisplay->display(itsCounter);
    }
}
