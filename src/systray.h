#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QWidget>
#include <QSystemTrayIcon>
#include "splashscreen.h"

class SysTray : public QWidget
{
    Q_OBJECT
public:
    explicit SysTray(QWidget *parent = nullptr);
    ~SysTray();

private:
    QSystemTrayIcon *sysTray;
    SplashScreen *splashScreen;

    void createSysTray();
    void createSplashScr();
};

#endif // SYSTRAY_H
