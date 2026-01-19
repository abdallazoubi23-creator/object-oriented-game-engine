#pragma once

#include <string>
#include "../Players/Player.h"

using namespace std;

class Monster
{
protected:
    string m_name;
    int m_power;
    int m_loot;
    int m_damage;

public:
    /**
     * Constructor of Monster class with a name, power, loot and damage
     *
     * @param name - name of the monster
     * @param power - power of the monster
     * @param loot - loot of the monster
     * @param damage - damage of the monster
     *
     * @return - A monster object with given name, power, loot and damage
     *
     */
    Monster(string name, int power, int loot, int damage);

    string getName() const { return this->m_name; };
    int getPower() { return this->m_power; };
    int getLoot() { return this->m_loot; };
    int getDamage() { return this->m_damage; };
    string getDescription() const;
};

class Goblin : public Monster
{
public:
    Goblin() : Monster("Goblin", 5, 2, 10){};
};

class Giant : public Monster
{
public:
    Giant() : Monster("Giant", 12, 5, 25){};
};

class Dragon : public Monster
{
public:
    Dragon() : Monster("Dragon", 17, 100, 9001){};
};