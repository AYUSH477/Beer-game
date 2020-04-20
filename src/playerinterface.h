#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <QDialog>
#include <QJsonObject>
#include <QTcpSocket>

#include "game.h"
#include "player.h"

class Game;
class Player;

namespace Ui {
class PlayerInterface;
}

class PlayerInterface : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerInterface(QWidget *parent = nullptr);
    ~PlayerInterface();

    virtual void receiveOrder(int);
    virtual void receiveShipment(int);
    virtual void placeOrder(int);
    virtual void placeShipment(int);
    virtual void updateUi();

    void sendOrderToPlayer(int);

    virtual void setPlayer(Player* player);
    virtual void setGame(Game* game);
    virtual int getRole();
    Game* getGame() {return game;};

protected:
    Ui::PlayerInterface *ui;
    Game* game = nullptr;
    Player* player = nullptr;

private slots:
    void on_orderBtn_clicked();

};


#endif // PLAYERINTERFACE_
