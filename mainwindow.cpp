#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    serverMenu = new QMenu(tr("&Server"));
    newConnectAction = serverMenu->addAction(tr("&New Connect"));
    newConnectAction->setShortcut(QKeySequence(QKeySequence::New));
    menuBar()->addMenu(serverMenu);

    connect(newConnectAction, SIGNAL(triggered()), this, SLOT(newConnect()));

    mainTab = new QTabWidget(this);
    mainTab->setTabsClosable(true);
    setCentralWidget(mainTab);
 //   mainTab->addTab(new ItalkTab(mainTab), QString("Test"));

    setWindowTitle(tr("Qitalk"));
}

MainWindow::~MainWindow()
{
}

void MainWindow::newConnect()
{
    ServerDialog sdialog;
    if(sdialog.exec()) {
        mainTab->addTab(new ItalkTab(sdialog.info, mainTab), sdialog.info["server"].toString());
    }
}
