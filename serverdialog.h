#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QtGui>
#include <QtNetwork>

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    ServerDialog();
    ~ServerDialog();
    QHash<QString, QVariant> info;

public slots:
    void accept();

private:
    QFormLayout *mainLayout;
    QLineEdit *serverInput;
    QLineEdit *portInput;
    QLineEdit *nickInput;
    QPushButton *okButton, *cancelButton;
    QHBoxLayout *buttonLayout;
};

#endif // SERVERDIALOG_H
