#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QWidget>
#include <QSystemTrayIcon>
#include "splashscreen.h"
#include <QTimer>

class SysTray : public QWidget
{
    Q_OBJECT
public:
    explicit SysTray(QWidget *parent = nullptr);
    ~SysTray();

private:
    QSystemTrayIcon *sysTray;
    SplashScreen *splashScreen;
    QTimer *timer;
    QRect screenSize;
    int posX;
    int posY;

    void createSysTray();
    void createSplashScr();

private slots:
    void whenTimeout();
};

#endif // SYSTRAY_H
