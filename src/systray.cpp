#include "systray.h"
#include <QMenu>

SysTray::SysTray(QWidget *parent) : QWidget(parent)
{
    createSysTray();
    createSplashScr();
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
    splashScreen->show();
}
