#include "italktab.h"

ItalkTab::ItalkTab(QWidget *parent)
        : QSplitter(Qt::Vertical, parent)
{
    logView = new QWebView(this);
    inputBox = new QTextEdit(this);
    logView->setHtml(tr("<html><body><a href=\"http://www.google.com/\">Google</a></body></html>"), tr(""));
}

ItalkTab::~ItalkTab()
{
}

void ItalkTab::openLink(const QUrl& url)
{
}
