#pragma once

#include <string>
#include "Card.h"
#include "../Players/Sorcerer.h"
#include "../Players/Warrior.h"

using namespace std;

class Event : public Card
{
public:
    /**
     * Constructor of Event class with a name
     *
     * @param name -  name of the event
     *
     * @return - An Event card object with the given name
     *
     */
    Event(string name) : Card(name){};

    bool isEncounter() { return false; };
    bool isEvent() { return true; };

    virtual bool isSolarEclipse() { return false; };
    virtual bool isPotionsMerchant() { return false; };
};

class SolarEclipse : public Event
{
public:
    SolarEclipse() : Event("SolarEclipse"){};
    bool isSolarEclipse() { return true; };
    bool isPotionsMerchant() { return false; };
};

class PotionsMerchant : public Event
{
public:
    PotionsMerchant() : Event("PotionsMerchant"){};
    bool isSolarEclipse() { return false; };
    bool isPotionsMerchant() { return true; };
};