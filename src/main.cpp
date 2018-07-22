#include <QApplication>
#include "systray.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SysTray sysTray;
//    sysTray.show();

    return app.exec();
}
