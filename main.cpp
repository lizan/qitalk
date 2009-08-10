#include <QtGui>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(QObject::tr("Qitalk"));
    MainWindow w;
    w.show();
    return a.exec();
}
