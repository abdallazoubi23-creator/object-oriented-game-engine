
#pragma once

#include <string>

using namespace std;

class Card
{
protected:
    string m_name;

public:
    /**
     * Constructor of Card class
     *
     * @param name - name of the card
     *
     * @return - Card object with the given name
     *
     */
    Card(string name) : m_name(name){};

    /**
     * Gets the description string for a card
     *
     * @return - A string description of the card
     *
     */
    virtual string getDescription() const { return this->m_name; };

    /**
     * Check whether the card is an encounter or not
     *
     * @return - true for encounter cards, false otherwise
     *
     */
    virtual bool isEncounter() { return false; };

    /**
     * Check whether the card is an event or not
     *
     * @return - true for event cards, false otherwise
     *
     */
    virtual bool isEvent() { return false; };

    /**
     * Check whether the card is a SolarEclipse or not
     *
     * @return - true for SolarEclipse cards, false otherwise
     *
     */
    virtual bool isSolarEclipse() { return false; };

    /**
     * Check whether the card is a PotionsMerchant or not
     *
     * @return - true for PotionsMerchant cards, false otherwise
     *
     */
    virtual bool isPotionsMerchant() { return false; };

    /**
     * Get the combat power of the card
     *
     * @return - the combat power of the card
     *
     */
    virtual int getPower() { return 0; };

    /**
     * Get the loot of the card
     *
     * @return - the loot of the card
     *
     */
    virtual int getLoot() { return 0; };

    /**
     * Get the damage of the card
     *
     * @return - the damage of the card
     *
     */
    virtual int getDamage() { return 0; };
};
