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

    void bounceBack();

private:
    int startPosX, startPosY;
    int movePosX, movePosY;
    QTimer *timer;
    QRect screenSize;

    void whenTimeout();
    void generatePos();
};

#endif // SPLASHSCREEN_H
