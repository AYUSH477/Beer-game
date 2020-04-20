#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>

#include "playerinterface.h"

class PlayerInterface;

/**
 * @brief what does this class do?
*/
#define CONSUMER 0
#define RETAILER 1
#define WHOLESALER 2
#define DISTRIBUTOR 3
#define FACTORY 4

const std::string PLAYER_NAMES[] = {
    "Consumer",
    "Retailer",
    "Wholesaler",
    "Distributor",
    "Factory"
};

class Player
{
private:
    int pId;
    int role;

    int oldInventory;
    int oldBackOrder;
    int inventory = 12;
    int backOrder = 0;
    int incomingOrder = 0;
    int incomingShipment = 0;
    int outgoingShipment = 0;
    int demand;
    
    double holdingCost = 0.5;
    double backOrderCost = 1;
    double cost = 0;
    double totalCost = 0;

    bool orderReceived = false;
    bool shipmentReceived = false;
    bool orderPlaced = false;
    bool shipmentPlaced = false;

    void updateData();
    int getAvailableShipment(int numberOfBeers);

    PlayerInterface* playerInterface = nullptr;

public: // every function here has been made void just for making template, change it accordingly
    Player() {}

    Player(int role);

    void setInterface(PlayerInterface*);

    void placeOrder(int);

    void placeShipment(int);

    int getIncomingShipment();

    int getOutgoingShipment();

    void startTransaction(int nOrders);

    bool transactionReceived();

    /**
     * @brief Based on the demand from the downstrea, it make changes to the inventory, and returns the number of beers that are available for 
     * shipments
     */

    void receiveShipment(int);

    void receiveOrder(int);

    int decreaseInventory(int numberOfBeers);

    int increaseInventory(int numberOfBeers);

    void setPId(int);

    void setDemand(int);

    void setRole(int);

    void setInventory(int);

    void setBackorder(int);

    void setOutgoingShipment(int);

    void setOrderPlaced(int);

    void setTotalCost(double);

    void setIncomingShipment(int);

    void setCost(double);

    int getPId();

    bool isOrderPlaced();

    bool isShipmentPlaced();

    int getRole() const {return role;};

    int getBackorder();

    int getOldBackOrder();

    int getDemand();

    int getCost();

    int getTotalCost();

    int getInventory();

    int getOldInventory();

    bool isOrderReceived();

    bool isShipmentReceived();
};

#endif //PLAYER_H
