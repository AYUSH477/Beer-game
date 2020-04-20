#ifndef BEERGAMESERVER_H
#define BEERGAMESERVER_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QWidget>
#include <QObject>
#include <vector>

#include "../playerinterface.h"
#include "../player.h"
#include "../game.h"

#include "playerinterfaceserver.h"

class PlayerInterfaceServer;
class Player;
class Game;

class BeerGameServer : public QTcpServer {
    Q_OBJECT
    Q_DISABLE_COPY(BeerGameServer)
    public:
        explicit BeerGameServer(QObject* parent = nullptr);

    protected:
        void incomingConnection(qintptr socketDescriptor) override;

    signals:
        void logMessageServer(const QString& msg);

    public slots:
        void stopServer();
        void displayLogMessage(const QString& msg);

    private slots:
        void receiveJson(PlayerInterfaceServer* sender, const QJsonObject& doc);
        void playerDisconnected(PlayerInterfaceServer* sender);
        void playerError(PlayerInterfaceServer* sender);

    private:
        void sendJson(PlayerInterfaceServer* destination, const QJsonObject& message);
        void jsonFromLoggedOut(PlayerInterfaceServer* sender, const QJsonObject& doc);
        void jsonFromLoggedIn(PlayerInterfaceServer* sender, const QJsonObject& doc);

    private:
        QVector<PlayerInterfaceServer*> m_clients;
        QVector<Game*> m_games;
//        std::vector<Game *>* m_games = new std::vector<Game*>(10);
};

#endif // BEERGAMESERVER_H
