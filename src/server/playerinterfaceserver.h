#ifndef PLAYERINTERFACESERVER_H
#define PLAYERINTERFACESERVER_H

#include <QTcpSocket>
#include <QWidget>

#include "../playerinterface.h"
#include "../player.h"

class Player;

class PlayerInterfaceServer : public PlayerInterface {
    Q_OBJECT
    public:
        explicit PlayerInterfaceServer(QWidget* parent = nullptr);
        virtual bool setSocketDescriptor(qintptr socketDescriptor);
        void sendJson(const QJsonObject& jsonData);
        void setRole(int role);
        void updateUi() override;

    signals:
        void jsonReceived(const QJsonObject& jsonDoc);
        void disconnectedFromPlayer();
        void error();
        void logMessagePlayer(const QString& msg);

    public slots:
        void disconnectFromPlayer();

    private slots:
        void receiveJson();

    private:
        QTcpSocket* m_playerSocket;
};

#endif // PLAYERINTERFACESERVER_H
