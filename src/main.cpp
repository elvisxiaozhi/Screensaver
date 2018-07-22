#include <QApplication>
#include "splashscreen.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SplashScreen w;
    w.show();
    return app.exec();
}
