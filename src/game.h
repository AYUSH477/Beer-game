#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>

#include "order.h"
#include "shipment.h"
#include "player.h"
#include "playerinterface.h"

class Order;
class PlayerInterface;

/**
 * \brief Handles a game 
 */

class Game
{
private:
    int gId;

    std::map<int, std::vector<Order>> ordersToBeExecuted;
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted;

    std::vector<PlayerInterface*> players;
    std::vector<int> demandPerWeek =
        {6, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};

    int orderDelay = 2;
    double holdingCost = 0.5;
    double backorderCost = 1;
    int startingInventory = 12;
    int weeksToBePlayed = 26;
    int currentWeek = 0;
    int infoCode = 0;
    int factoryDelay = 1;

    int nOrdersReceived = 0;
    int nShipmentsReceived = 0;
    int nPlayers = 5;

    // test
    int instrid;
    int pFactId;
    int pDistributorId;
    int pWholesalerId;
    int pRetailerId;
    int shipmentDelay;

public:
    Game();

    /**
     * @brief Initializes a game based on supplied setters.
     * 
     * One main responsibility of this method is to create orders and shipments based on the order delay. For example, if the orderDelay is 2 weeks, orders and shipments for 
     * two weeks should be created. These values are either set by default or accessed using instructor. However, as of Sprint2, the functionality 
     * for instructor to enter these values does not exist
     */
    void initGame();

    /**
     * @brief This method is called by the instructor to start the game
     * 
     * Basically when this function is called, it starts executing orders and shipments for the 1st week
     */
    void startGame();

    /**
     * @brief Takes the order vector for the current week based on currentWeek proerty. Then loops through the vector and 
     * executes the orders by calling order.executeEvent() 
     */
    void executeOrdersForCurrentWeek();

    /**
     * @brief Takes the shipment vector for the current week based on currentWeek proerty. Then loops through the vector and 
     * executes the shipments by calling shipment.executeEvent() 
     */
    void executeShipmentsForCurrentWeek();

    /**
     * @brief This method was listed in the initial documentation, but has been deprecated
     * 
     * @deprecated
     */
    void updatePlayerInventories();

    /**
     * @brief For the current week return the consumer order.
     * 
     * The values for consumer order are set by default. These values can be overriden by values provided by the instructor. However, as of Sprint2 
     * this functionality in instructor does not exist
     * 
     * @return Consumer order for the current week.
     * 
     */
    int getConsumerOrderForWeek();

    /**
    * @brief Call executeOrderForCurrentWeek() and executeShipmentForCurrentWeek()
    */
    int advanceWeek();

    /**
     * @brief Add the parameter to the vector of orders
     * 
     * The order contains a property that says in which week it is going to be executed. Using this property, the order is placed in 
     * ordertoBeExecuted vector's correct location
     * 
     * @param order The order object that is to be added to ordersToBeExecuted
     */
    void addOrder(int numberOfBeers, int role);

    /**
     * @brief Add the parameter to the vector of shipments
     * 
     * The shipment contains a property that says in which week it is going to be executed. Using this property, the shipment is placed in 
     * shipmentsToBeExecuted vector's correct location
     * 
     * @param order The shipment object that is to be added to shipmentsToBeExecuted
     */
    void addShipment(int numberOfBeers, int role);

    /**
     * @brief Adds a player pointer to the list of player
     * 
     * Note that the order of addition matters. The order should be from downstream to upstream.
     */
    void addPlayerInterface(PlayerInterface* player);

    /**
     * @brief Returns the pointer to the downstream player for the player whose role is 'role'
     */
    PlayerInterface* getDownstream(int role);

    /**
     * @brief Returns the pointer to the upstream player for the player whose role is 'role'
     */
    PlayerInterface* getUpstream(int role);

    bool isGamePlayable();

    //////
    /// Setters
    //////

    void setGId(int gId);

    void setWeeksToBePlayed(int w);

    void setInfoCode(int code);

    void setBackorderCost(double cost);

    void setHoldingCost(double hc);

    void setFactoryDelay(int);

    void setOrderDelay(int);

    void setStartingInventory(int si);

    void setCurrentWeek(int week);

    void setShipmentDelay(int);

    //////
    /// Setters
    //////
    int getGId();

    int getWeeksToBePlayed();

    int getInfoCode();

    double getBackorderCost();

    double getHoldingCost();

    int getFactoryDelay();

    int getOrderDelay();

    int getStartingInventory();

    int getCurrentWeek();

    int getShipmentDelay();

    /// 
    // For test cases
    ///
    void setOrderTimeDelay(int i) {setOrderDelay(i);};
    int getOrderTimeDelay() {return orderDelay;}

    void setInstrId(int id) {this->instrid = id;};
    void setPFactId(int id) {this->pFactId = id;};
    void setPDistributorId(int id) {this->pDistributorId = id;};
    void setPWholesalerId(int id) {this->pWholesalerId = id;};
    void setPRetailerId(int id) {this->pRetailerId = id;};

    int getInstrId() {return this->instrid;};
    int getPFactId() {return this->pFactId;};
    int getPDistributorId() {return this->pDistributorId;};
    int getPWholesalerId() {return this->pWholesalerId;};
    int getPRetailerId() {return this->pRetailerId;};

    std::vector<std::string> generatePasswords();

};

#endif //GAME_H
