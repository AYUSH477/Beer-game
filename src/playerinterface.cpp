#include <QIntValidator>
#include <QRegExpValidator>

#include <string>
#include <iostream>

#include "playerinterface.h"
#include "ui_playerinterface.h"


using namespace std;

PlayerInterface::PlayerInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerInterface)
{
    player = nullptr;
    ui->setupUi(this);

    // make textbox accpet numbers only
    ui->orderIn->setValidator(new QIntValidator(0, 1000, this));
}

void PlayerInterface::on_orderBtn_clicked()
{
    QString nOrder = ui->orderIn->text();
    if(nOrder.isEmpty()) {
        ui->orderIn->focusWidget();
        ui->orderIn->setStyleSheet("QLineEdit { background-color: red; }");
    } else {
        ui->orderIn->setStyleSheet("QLineEdit { background-color: white; }");
        ui->orderBtn->setDisabled(true);
        this->sendOrderToPlayer(nOrder.toUInt());
    }
}

void PlayerInterface::sendOrderToPlayer(int nBeers) {
    player->startTransaction(nBeers);
}


PlayerInterface::~PlayerInterface()
{
    delete ui;
}

void PlayerInterface::receiveOrder(int numberOfBeers) {
    player->receiveOrder(numberOfBeers);

    if(player->transactionReceived()) {
        updateUi();
    }
}

void PlayerInterface::receiveShipment(int numberOfBeers) {
    player->receiveShipment(numberOfBeers);

    if(player->getRole() == CONSUMER) {
        ui->orderIn->setText(QString::number(game->getConsumerOrderForWeek()));
        placeOrder(game->getConsumerOrderForWeek());
    }

    if(player->transactionReceived()) {
        updateUi();
    }
}

void PlayerInterface::placeOrder(int numberOfBeers) {
    game->addOrder(numberOfBeers, player->getRole());
}

void PlayerInterface::placeShipment(int numberOfBeers){
    game->addShipment(numberOfBeers, player->getRole());
}

void PlayerInterface::setGame(Game *p_game) {
    this->game = p_game;
}

void PlayerInterface::setPlayer(Player *player) {
    this->player = player;
    player->setInterface(this);

    // disable input field for CONSUMER
    if(player->getRole() == CONSUMER)
        ui->orderIn->setEnabled(false);

    string playerName = PLAYER_NAMES[player->getRole()];
    string downstreamName = PLAYER_NAMES[player->getRole() - 1];
    string upstreamName = PLAYER_NAMES[player->getRole() + 1];

    this->setWindowTitle(QString::fromStdString(playerName));
    ui->PlayerArea->setTitle(QString::fromStdString(playerName));
    ui->DownstreamGraph->setTitle(QString::fromStdString("To " + downstreamName + ": Order and Shipment Graph"));
    ui->UpstreamGraph->setTitle(QString::fromStdString("From " + upstreamName + ": Order and Shipment Graph"));
}

int PlayerInterface::getRole() {
    if(player == nullptr) {
        return -1;
    }
    return player->getRole();
}

void PlayerInterface::updateUi() {
    // enable button
    ui->orderBtn->setEnabled(true);
    ui->week->setNum(game->getCurrentWeek());

    ui->incomingOrder->setNum(player->getDemand());

    ui->totalCost->setNum(player->getTotalCost());

    // older
    ui->inventory->setNum(player->getOldInventory());
    ui->backLog->setNum(player->getOldBackOrder());

    // set outgoing and incoming  shipments
    ui->outgoingShipment->setNum(player->getOutgoingShipment());
    ui->incomingShipment->setNum(player->getIncomingShipment());

    // display inventory after transactions
    ui->inventoryAfter->setNum(player->getInventory());
    ui->backlogAfter->setNum(player->getBackorder());
}
