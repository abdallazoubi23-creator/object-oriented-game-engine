
#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "Behavior.h"
#include "../Cards/Card.h"

using namespace std;

class Player
{
protected:
    string m_name;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
    shared_ptr<Behavior>m_behavior;

    static int const INITIAL_LEVEL = 1;
    static int const INITIAL_FORCE = 5;
    static int const INITIAL_HP = 100;
    static int const INITIAL_COINS = 10;

public:
    /**
     * Constructor of Player class
     *
     * @param name - name of the player
     * @param behavior - behavior of the player
     *
     * @return - Player object with the given name and behavior
     *
     */
    Player(string name, shared_ptr<Behavior>behavior);

    string getDescription() const;
    string getName() const { return this->m_name; };
    int getLevel() const { return this->m_level; };
    int getForce() const { return this->m_force; };
    int getHealthPoints() const { return this->m_hp; };
    int getCoins() const { return this->m_coins; };

    /**
     * Check whether the player is still alive
     *
     * @return - true if alive, else false
     *
     */
    bool isAlive() { return (this->m_hp > 0); };

    string getBehaviorName() const { return this->m_behavior->getName(); };

    /**
     * level up the player
     *
     * @return - void
     *
     */
    void levelUp() { this->m_level++; };

    /**
     * add loot to the players coins
     *
     * @param loot - the amount of coins to add
     *
     * @return - void
     *
     */
    void lootUp(int loot) { this->m_coins += loot; };

    /**
     * apply damage to a player's hp
     *
     * @param damage - the damage to inflict onto the player
     *
     * @return - void
     *
     */
    void getDamage(int damage);

    virtual int getCombatPower() = 0;
    virtual string getJobName() const { return "Unknown"; };

    /**
     * play a card and apply all its effects to the player
     *
     * @param card - the card to be played
     *
     * @return - a string showing the outcome of the played card
     *
     */
    string playCard(shared_ptr<Card>card);

    /**
     * combat against the monster/ganag of an encounter card
     *
     * @param encounter - the encounter card being played
     *
     * @return - string outcome of the combat
     *
     */
    string combat(shared_ptr<Card>encounter);

    /**
     * apply the effect of SolarEclipse to the player
     *
     * @return - string outcome of the combat
     *
     */
    virtual string solarEclipse() { return ""; };

    /**
     * buy potions in case of a PotionsMechant event
     *
     * @return - string outcome
     *
     */
    string buyPotions();

    /**
     * compare this player with another player to check if
     * he ranks higher in the leaderboard
     *
     * @param player - the player to compare against
     *
     * @return - true if this player is higher, else false
     *
     */
    bool isGreaterThan(shared_ptr<Player>player);
};
