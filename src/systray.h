#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QWidget>
#include <QSystemTrayIcon>
#include "splashscreen.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class SysTray : public QWidget
{
    Q_OBJECT
public:
    explicit SysTray(QWidget *parent = nullptr);
    ~SysTray();

private:
    QSystemTrayIcon *sysTray;
    QVector<SplashScreen *> splashVec;
    QLineEdit *lineEdit;
    QPushButton *btn;
    QVBoxLayout *vLayout;

    void createWindowLayout();
    void createSysTray();
    void createSplashScr(int);
};

#endif // SYSTRAY_H
