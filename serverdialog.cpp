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

    setLayout(mainLayout);
    setWindowTitle(tr("New Connection"));
}

ServerDialog::~ServerDialog()
{
}
