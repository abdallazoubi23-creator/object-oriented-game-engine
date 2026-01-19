#pragma once

#include <string>
#include <vector>
#include "Monster.h"

using namespace std;

class Gang
{
protected:
    vector<shared_ptr<Monster>> m_monsters;
    int m_size;
    int m_power;
    int m_loot;
    int m_damage;

public:
    /**
     * Constructor of Gang class with a given size
     *
     * @param size - The size of the gang
     *
     * @return - A gang object with no monsters initially
     *
     */
    Gang(int size) : m_monsters(), m_size(size), m_power(0), m_loot(0), m_damage(0){};

    /**
     * Adds a monster to the gang
     *
     * @param monster -  The monster to add
     *
     * @return - void
     *
     */
    void addMonster(shared_ptr<Monster> monster);

    string getDescription() const;

    int getPower() { return this->m_power; };
    int getLoot() { return this->m_loot; };
    int getDamage() { return this->m_damage; };
};