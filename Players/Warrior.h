#pragma once

#include "Player.h"

class Warrior : public Player
{
public:
    Warrior(string name, shared_ptr<Behavior>behavior) : Player(name, behavior){};
    string getJobName() const;
    int getCombatPower() { return this->m_level + 2 * this->m_force; };
    string solarEclipse();
};