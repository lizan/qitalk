#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QtGui>

class ServerDialog : public QDialog
{
public:
    ServerDialog();
    ~ServerDialog();
private:
    QFormLayout *mainLayout;
    QLineEdit *serverInput;
    QLineEdit *portInput;
    QLineEdit *nickInput;
};

#endif // SERVERDIALOG_H
