#ifndef ITALKTAB_H
#define ITALKTAB_H

#include <QtGui>
#include <QtWebKit>

class ItalkTab : public QSplitter
{
public:
    ItalkTab(QWidget *parent = 0);
    ~ItalkTab();

private:
    QTextEdit *inputBox;
    QWebView *logView;
};

#endif // ITALKTAB_H
