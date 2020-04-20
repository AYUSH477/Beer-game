#include "clientinterface.h"
#include "ui_ClientInterface.h"
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QHostAddress>
#include <QLabel>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QDebug>
#include <QJsonArray>

ClientInterface::ClientInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientInterface) // create the elements defined in the .ui file
    , m_PlayerClient(new PlayerClient(this)) // create the chat client
{
    // set up of the .ui file
    ui->setupUi(this);
    ui->orderBtn->setDisabled(true);
    connect(m_PlayerClient, &PlayerClient::connected, this, &ClientInterface::connectedToServer);
    connect(m_PlayerClient, &PlayerClient::loggedIn, this, &ClientInterface::loggedIn);
    connect(m_PlayerClient, &PlayerClient::loginError, this, &ClientInterface::loginFailed);
    connect(m_PlayerClient, &PlayerClient::messageReceived, this, &ClientInterface::messageReceived);

    connect(ui->Connect, &QPushButton::clicked, this, &ClientInterface::attemptConnection);
    connect(ui->orderBtn, &QPushButton::clicked, this, &ClientInterface::sendMessage);

}

ClientInterface::~ClientInterface()
{
    // delete the elements created from the .ui file
    delete ui;
}

void ClientInterface::attemptConnection()
{
    // We ask the user for the address of the server, we use 127.0.0.1 (aka localhost) as default
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields

    // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;
    int portNum;
    QString list[2] = {QStringLiteral("IP Address"), QStringLiteral("Port number")};
    for(int i = 0; i < 2; ++i) {

        QLineEdit *lineEdit = new QLineEdit(&dialog);
        if(i==0){
            lineEdit->setText("127.0.0.1");
         }
        if(i==1)
            lineEdit->setText("8888");
        QString label = list[i];
        form.addRow(label, lineEdit);

        fields << lineEdit;
    }

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                              Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
    QString hostAddress;


    if (dialog.exec() == QDialog::Accepted) {

        // If the user didn't dismiss the dialog, do something with the fields
            hostAddress = fields[0]->text();
            portNum = fields[1]->text().toInt();

    }
    else
        return;
    ui->Connect->setEnabled(false);
    // tell the client to connect to the host using the port 1967
    m_PlayerClient->connectToServer(QHostAddress(hostAddress), portNum);
}

void ClientInterface::connectedToServer()
{
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;
    int GameId;
    int role;
    QString list[2] = {QStringLiteral("Game ID"), QStringLiteral("Role")};
    for(int i = 0; i < 2; ++i) {
        QLineEdit *lineEdit = new QLineEdit(&dialog);
        if(i==0){
            lineEdit->setText("1");
         }
        QString label = list[i];
        form.addRow(label, lineEdit);

        fields << lineEdit;
    }


    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                              Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        // If the user didn't dismiss the dialog, do something with the fields
            GameId = fields[0]->text().toInt();
            role = fields[1]->text().toInt();

    }
    else
        return;
    // try to login with the given username
    attemptLogin(GameId, role);
}

void ClientInterface::attemptLogin(const int &GameId, const int &role)
{
    // use the client to attempt a log in with the given username
    m_PlayerClient->login(GameId, role);
}

void ClientInterface::loggedIn()
{
    // once we successully log in we enable the ui to display and send messages
//    ui->orderIn->setEnabled(true);
    ui->PlayerArea->setTitle(m_PlayerClient->playerName);

    // clear the user name record
    m_lastUserName.clear();
}

void ClientInterface::loginFailed(const QString &reason)
{
    // the server rejected the login attempt
    // display the reason for the rejection in a message box
    QMessageBox::critical(this, tr("Error"), reason);
    // allow the user to retry, execute the same slot as when just connected
    connectedToServer();
}

void ClientInterface::messageReceived(const QString &text, const QString &sender)
{
//    this->findChild<QLabel>(sender).setText(text);
    ui->orderBtn->setEnabled(true);
    QLabel* q =  this->findChild<QLabel*>(sender);   // store the index of the new row to append to the model containing the messages
    if(q==nullptr)
           return;
    q->setText(text);
}

void ClientInterface::sendMessage()
{
    ui->orderBtn->setDisabled(true);
     m_PlayerClient->sendMessage(ui->orderIn->text());
    // we use the client to send the message that the user typed

}
void ClientInterface::disconnectedFromServer()
{
    // if the client loses connection to the server

}
