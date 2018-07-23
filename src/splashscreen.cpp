#include "splashscreen.h"
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>

SplashScreen::SplashScreen(QWidget *parent) : QSplashScreen(parent)
{
    startPosX = geometry().center().x();
    startPosY = geometry().center().y();

    setSplashScreen();
    generatePos();
}

SplashScreen::SplashScreen(QWidget *parent, int posX, int posY) : QSplashScreen(parent)
{
    startPosX = posX;
    startPosY = posY;

    setSplashScreen();
    moveSplashScreen();
}

void SplashScreen::whenTimeout()
{
    if(!screenSize.contains(startPosX + movePosX, startPosY + movePosY)) {
        emit reachingBorder(startPosX + movePosX, startPosY + movePosY);
    }

    moveSplashScreen();
}

void SplashScreen::generatePos()
{
    movePosX = 0, movePosY = 0;
    while(movePosX == 0 && movePosY == 0) {
        movePosX = rand() % 11 - 5;
        movePosY = rand() % 11 - 5;
    }
}

void SplashScreen::setSplashScreen()
{
    QPixmap pixmap(":/icons/comicFace.png");
    setPixmap(pixmap);

    screenSize.setRect(0, 0, QApplication::desktop()->screenGeometry().width() - 80, QApplication::desktop()->screenGeometry().height() - 120);

    timer = new QTimer(this);
    timer->start(10);
    connect(timer, &QTimer::timeout, this, &SplashScreen::whenTimeout);

    this->show();
}

void SplashScreen::moveSplashScreen()
{
    while(!screenSize.contains(startPosX + movePosX, startPosY + movePosY)) {
        generatePos();
    }
    startPosX += movePosX;
    startPosY += movePosY;
    move(startPosX, startPosY);
}
