#pragma once

#define POTION_COST 5
#define POTION_HP_GAIN 10

#include <string>

using namespace std;

class Behavior
{
public:
    virtual string getName() const = 0;

    /**
     * Function to implement the action of buying of potions by a
     * player of a specific behavior
     *
     * @param coins - the coins to buy potions with
     * @param hp - the current hp of the player
     *
     * @return - the number of potions the player will buy
     *
     */
    virtual int buyPotions(int coins, int hp) { return 0; };
};

class ResponsibleBehavior : public Behavior
{
public:
    string getName() const { return "Responsible"; };
    int buyPotions(int coins, int hp);
};

class RiskTakingBehavior : public Behavior
{
public:
    string getName() const { return "RiskTaking"; };
    int buyPotions(int coins, int hp);
};