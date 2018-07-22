#include "splashscreen.h"

SplashScreen::SplashScreen(QWidget *parent) : QSplashScreen(parent)
{
    QPixmap pixmap(":/icons/test.png");
    setPixmap(pixmap);
}
