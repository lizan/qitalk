#ifndef ITALKTAB_H
#define ITALKTAB_H

#include <QtGui>
#include <QtNetwork>

class ItalkTab : public QSplitter
{
    Q_OBJECT

public:
    ItalkTab(QHash<QString, QVariant> info, QWidget *parent = 0);
    ~ItalkTab();

public slots:
    void openLink(const QUrl& url);
    void sendMessage();
    void appendLog(QString message);
    void established();
    void disconnected();
    void getLog();
    void zoomIn();
    void zoomOut();

private:
    QLineEdit *inputBox;
    QTextBrowser *logView;
    QTextCodec *eucJPcodec;
    QTcpSocket *connection;
    QHash<QString, QVariant> info;
};

#endif // ITALKTAB_H
