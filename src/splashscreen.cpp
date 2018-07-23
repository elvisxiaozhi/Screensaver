#include "splashscreen.h"
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>

SplashScreen::SplashScreen(QWidget *parent) : QSplashScreen(parent)
{
    QPixmap pixmap(":/icons/comicFace.png");
    setPixmap(pixmap);

    startPosX = geometry().center().x();
    startPosY = geometry().center().y();

    generatePos();

    screenSize.setRect(0, 0, QApplication::desktop()->screenGeometry().width() - 80, QApplication::desktop()->screenGeometry().height() - 120);

    timer = new QTimer(this);
    timer->start(10);
    connect(timer, &QTimer::timeout, this, &SplashScreen::whenTimeout);

    this->show();
}

void SplashScreen::whenTimeout()
{
    bounceBack();
    startPosX += movePosX;
    startPosY += movePosY;
    move(startPosX, startPosY);
}

void SplashScreen::generatePos()
{
    movePosX = 0, movePosY = 0;
    while(movePosX == 0 && movePosY == 0) {
        movePosX = rand() % 11 - 5;
        movePosY = rand() % 11 - 5;
    }
}

void SplashScreen::bounceBack()
{
    while(!screenSize.contains(startPosX, startPosY)) {
        generatePos();
        startPosX += movePosX;
        startPosY += movePosY;
        if(!screenSize.contains(startPosX, startPosY)) {
            startPosX -= movePosX;
            startPosY -= movePosY;
        }
    }
}
