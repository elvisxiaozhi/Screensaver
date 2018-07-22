#include <QApplication>
#include "systray.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication app(argc, argv);

    SysTray sysTray;
    sysTray.show();

    return app.exec();
}
