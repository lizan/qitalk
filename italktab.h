#ifndef ITALKTAB_H
#define ITALKTAB_H

#include <QtGui>
#include <QtNetwork>

class ItalkTab : public QSplitter
{
    Q_OBJECT

public:
    ItalkTab(QWidget *parent = 0);
    ~ItalkTab();

public slots:
    void openLink(const QUrl& url);
    void sendMessage();
    void appendLog(QString message);
    void established();
    void getLog();

private:
    QLineEdit *inputBox;
    QTextBrowser *logView;
    QTextCodec *eucJPcodec;
    QTcpSocket *connection;
};

#endif // ITALKTAB_H
