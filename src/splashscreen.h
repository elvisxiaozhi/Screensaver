#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QWidget>
#include <QSplashScreen>
#include <QTimer>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(QWidget *parent = nullptr);

private:
    int startPosX, startPosY;
    int movePosX, movePosY;
    QTimer *timer;
    QRect screenSize;

    void whenTimeout();
};

#endif // SPLASHSCREEN_H
