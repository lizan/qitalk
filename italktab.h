#ifndef ITALKTAB_H
#define ITALKTAB_H

#include <QtGui>
#include <QtWebKit>

class ItalkTab : public QSplitter
{
    Q_OBJECT

public:
    ItalkTab(QWidget *parent = 0);
    ~ItalkTab();

public slots:
    void openLink(const QUrl& url);

private:
    QTextEdit *inputBox;
    QTextBrowser *logView;
};

#endif // ITALKTAB_H
