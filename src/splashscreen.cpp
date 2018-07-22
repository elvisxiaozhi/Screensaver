#include "splashscreen.h"
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>

SplashScreen::SplashScreen(QWidget *parent) : QSplashScreen(parent)
{
    QPixmap pixmap(":/icons/test.png");
    setPixmap(pixmap);

    startPosX = geometry().center().x();
    startPosY = geometry().center().y();

    movePosX = rand() % 11 - 5;
    movePosY = rand() % 11 - 5;

    screenSize.setRect(0, 0, QApplication::desktop()->screenGeometry().width() - 80, QApplication::desktop()->screenGeometry().height() - 120);

    timer = new QTimer(this);
    timer->start(10);
    connect(timer, &QTimer::timeout, this, &SplashScreen::whenTimeout);
}

void SplashScreen::whenTimeout()
{
    while(!screenSize.contains(startPosX += movePosX, startPosY += movePosY)) {
        movePosX = rand() % 11 - 5;
        movePosY = rand() % 11 - 5;
    }
    startPosX += movePosX;
    startPosY += movePosY;
    move(startPosX, startPosY);
}
