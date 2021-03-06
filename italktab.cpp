#include "italktab.h"

ItalkTab::ItalkTab(QHash<QString, QVariant> info, QWidget *parent)
        : QSplitter(Qt::Vertical, parent), info(info)
{
    logView = new QTextBrowser(this);
    inputBox = new QLineEdit(this);
    connect(logView, SIGNAL(anchorClicked(const QUrl&)), this, SLOT(openLink(const QUrl&)));
    connect(inputBox, SIGNAL(returnPressed()), this, SLOT(sendMessage()));

    logView->setHtml(tr(""));
    logView->setStyleSheet(tr("* { font-family: Monaco, monospace; }"));
    logView->setOpenLinks(false);

    eucJPcodec = QTextCodec::codecForName("EUC-JP");

    connection = new QTcpSocket(this);
    connect(connection, SIGNAL(connected()), this, SLOT(established()));
    connect(connection, SIGNAL(readyRead()), this, SLOT(getLog()));
    connect(connection, SIGNAL(disconnected()), this, SLOT(disconnected()));

    connection->connectToHost(info["server"].toString(), info["port"].toInt());
}

ItalkTab::~ItalkTab()
{
}

void ItalkTab::openLink(const QUrl& url)
{
    QDesktopServices::openUrl(url);
}

void ItalkTab::sendMessage()
{
    if(connection->state() == QAbstractSocket::ConnectedState) {
        if(!inputBox->text().isEmpty()) {
            connection->write(eucJPcodec->fromUnicode(inputBox->text()) + "\r\n");
            connection->flush();
            inputBox->setText(tr(""));
        }
    }
}

void ItalkTab::appendLog(QString message)
{
    static QRegExp timestamp("^(\\([^\\(]*\\))"); // minimal
    static QRegExp nickname("(\\[[^\\[]*\\])"); // minimal
    static QRegExp info("^(\\(\\[.*)$");
    static QRegExp system("^(#.*)$");
    static QRegExp urlexp("(https?:\\/\\/[-_.!~*'()a-zA-Z0-9;/?:@&=+$,%#]+)");

    if(info.exactMatch(message)) {
        message = message.replace(info, "<span style=\"color: #ff0000;\">\\1</span>");
    } else if (system.exactMatch(message)) {
        message = message.replace(system, "<span style=\"color: #7f007f;\">\\1</span>");
    } else {
        timestamp.setMinimal(true);
        nickname.setMinimal(true);

        message = message.replace(urlexp, "<a href=\"\\1\">\\1</a>");
        message = message.replace(timestamp, "<span style=\"color: #0000ff;\">\\1</span>");
        message = message.replace(nickname, "<span style=\"color: #007f00;\">\\1</span>");
    }
    logView->append(message);
}

void ItalkTab::established()
{
    if(connection->state() == QAbstractSocket::ConnectedState) {
        connection->write(eucJPcodec->fromUnicode(info["nick"].toString()) + "\r\n");
        connection->flush();
    }
}

void ItalkTab::disconnected()
{
    logView->append("# disconnected\n");
}

void ItalkTab::getLog()
{
    while(connection->canReadLine()) {
        QString log = eucJPcodec->toUnicode(connection->readLine());
        appendLog(Qt::escape(log.trimmed()));
        if(log.contains(QString("ping ") + info["nick"].toString())) {
            QApplication::alert(topLevelWidget());
        }
    }
}

void ItalkTab::zoomIn()
{
    logView->zoomIn();
}

void ItalkTab::zoomOut()
{
    logView->zoomOut();
}

