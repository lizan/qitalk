#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    serverMenu = new QMenu(tr("&Server"));
    newConnectAction = serverMenu->addAction(tr("&New Connect"));
    newConnectAction->setShortcut(QKeySequence(QKeySequence::New));
    menuBar()->addMenu(serverMenu);

    zoomMenu = new QMenu(tr("&Zoom"));
    zoomInAction = zoomMenu->addAction(tr("&ZoomIn"));
    zoomInAction->setShortcut(QKeySequence(QKeySequence::ZoomIn));
    zoomOutAction = zoomMenu->addAction(tr("&ZoomOut"));
    zoomOutAction->setShortcut(QKeySequence(QKeySequence::ZoomOut));
    menuBar()->addMenu(zoomMenu);

    connect(newConnectAction, SIGNAL(triggered()), this, SLOT(newConnect()));
    connect(zoomInAction, SIGNAL(triggered()), this, SLOT(zoomIn()));
    connect(zoomOutAction, SIGNAL(triggered()), this, SLOT(zoomOut()));

    mainTab = new QTabWidget(this);
    mainTab->setTabsClosable(true);
    setCentralWidget(mainTab);
    this->resize(300, 600);

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

void MainWindow::zoomIn()
{
  ItalkTab* current = currentItalkTab();
  if (current != NULL) current->zoomIn();
}

void MainWindow::zoomOut()
{
  ItalkTab* current = currentItalkTab();
  if (current != NULL) current->zoomOut();
}

ItalkTab* MainWindow::currentItalkTab() const {
  if (mainTab->currentIndex() == -1) return NULL;
  QWidget* current = mainTab->currentWidget();
  return dynamic_cast<ItalkTab*>(current);
}

