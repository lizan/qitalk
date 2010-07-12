#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "serverdialog.h"
#include "italktab.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~MainWindow();

public slots:
    void newConnect();
    void zoomIn();
    void zoomOut();

private:
    ItalkTab* currentItalkTab() const;

    QTabWidget *mainTab;
    QMenu *serverMenu, *zoomMenu;
    QAction *newConnectAction, *zoomInAction, *zoomOutAction;
    QInputDialog *serverDialog;
};

#endif // MAINWINDOW_H
