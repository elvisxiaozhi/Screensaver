#include "systray.h"
#include <QMenu>
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>

SysTray::SysTray(QWidget *parent) : QWidget(parent)
{
    posX = 100;
    posY = 100;
    screenSize.setRect(0, 0, QApplication::desktop()->screenGeometry().width() - 80, QApplication::desktop()->screenGeometry().height() - 120);

    createSysTray();
    createSplashScr();

    timer = new QTimer(this);
    timer->start(20);
    connect(timer, &QTimer::timeout, this, &SysTray::whenTimeout);
}

SysTray::~SysTray()
{
    delete splashScreen;
}

void SysTray::createSysTray()
{
    sysTray = new QSystemTrayIcon(QIcon(":/icons/test.png"), this);
    sysTray->show();

    QMenu *menu = new QMenu(this);

    QAction *quitAct = new QAction(tr("Quit"), menu);

    menu->addAction(quitAct);
    sysTray->setContextMenu(menu);

    connect(quitAct, &QAction::triggered, [this](){ this->close(); });
}

void SysTray::createSplashScr()
{
    splashScreen = new SplashScreen();
    splashScreen->move(QPoint(posX, posY));
    splashScreen->show();
}

void SysTray::whenTimeout()
{
    if(screenSize.contains(posX, posY)) {
        posX += 5;
        posY += 3;
        splashScreen->move(posX, posY);
    }
    else {
        qDebug() << "No";
        timer->stop();
        qDebug() << posY << posX;
    }
}
