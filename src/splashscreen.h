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
    SplashScreen(QWidget *parent, int, int);

private:
    int startPosX, startPosY;
    int movePosX, movePosY;
    QTimer *timer;
    QRect screenSize;

    void whenTimeout();
    void generatePos();
    void setSplashScreen();

signals:
    void reachingBorder(int, int);
};

#endif // SPLASHSCREEN_H
