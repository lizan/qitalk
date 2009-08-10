#include "serverdialog.h"

ServerDialog::ServerDialog()
{
    mainLayout = new QFormLayout(this);
    serverInput = new QLineEdit(this);
    portInput = new QLineEdit(this);
    portInput->setValidator(new QIntValidator(0, 65535, serverInput));
    nickInput = new QLineEdit(this);

    mainLayout->addRow(tr("Server:"), serverInput);
    mainLayout->addRow(tr("Port:"), portInput);
    mainLayout->addRow(tr("Nick:"), nickInput);

    buttonLayout = new QHBoxLayout(this);
    okButton = new QPushButton(tr("&OK"), this);
    connect(okButton, SIGNAL(pressed()), this, SLOT(accept()));
    buttonLayout->addWidget(okButton);
    cancelButton = new QPushButton(tr("&Cancel"), this);
    connect(cancelButton, SIGNAL(pressed()), this, SLOT(reject()));
    buttonLayout->addWidget(cancelButton);

    mainLayout->addRow(buttonLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("New Connection"));
}

ServerDialog::~ServerDialog()
{
}

void ServerDialog::accept()
{
    info["server"] = QVariant(serverInput->text());
    info["port"] = QVariant(portInput->text().toInt());
    info["nick"] = QVariant(nickInput->text());

    QDialog::accept();
}
