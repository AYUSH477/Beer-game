#include "playerevent.h"
#include "player.h"

class Player;

#ifndef _SHIPMENT_H
#define _SHIPMENT_H

class Shipment : public PlayerEvent {
public: 
    Shipment();

    Shipment(int, int, int, PlayerInterface*);

    void executeShipment();
};

#endif
