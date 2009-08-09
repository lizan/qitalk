#include "italktab.h"

ItalkTab::ItalkTab(QWidget *parent)
        : QSplitter(Qt::Vertical, parent)
{
    logView = new QTextBrowser(this);
    inputBox = new QTextEdit(this);
    connect(logView, SIGNAL(anchorClicked(const QUrl&)), this, SLOT(openLink(const QUrl&)));
    logView->setHtml(tr(""));
    logView->append(QString::fromUtf8("(18:30:43)[lizan] こんにちは"));
    logView->setOpenLinks(false);

    QFile *styleSheet = new QFile(tr(":/css/logstyle.css"));
    styleSheet->open(QIODevice::ReadOnly);
    logView->setStyleSheet(styleSheet->readAll());
    styleSheet->close();
}

ItalkTab::~ItalkTab()
{
}

void ItalkTab::openLink(const QUrl& url)
{
    QMessageBox::information(this, tr("Inf"), url.toString());
}
