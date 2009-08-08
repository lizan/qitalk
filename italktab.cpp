#include "italktab.h"

ItalkTab::ItalkTab(QWidget *parent)
        : QSplitter(Qt::Vertical, parent)
{
    logView = new QWebView(this);
    inputBox = new QTextEdit(this);
    logView->setHtml(tr("<html><body><h1>Test</h1></body></html>"), tr(""));
}

ItalkTab::~ItalkTab()
{
}
