#include "mainwindow.h"
#include <QApplication>
#include <QMediaPlaylist>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QMediaPlaylist l;
    return a.exec();
}
