#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QtGui>

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    ServerDialog();
    ~ServerDialog();
private:
    QFormLayout *mainLayout;
    QLineEdit *serverInput;
    QLineEdit *portInput;
    QLineEdit *nickInput;
    QPushButton *okButton, *cancelButton;
    QHBoxLayout *buttonLayout;
};

#endif // SERVERDIALOG_H
