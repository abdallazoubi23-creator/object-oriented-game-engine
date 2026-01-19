#pragma once

#include "Player.h"

class Sorcerer : public Player
{
public:
    Sorcerer(string name, shared_ptr<Behavior>behavior) : Player(name, behavior){};
    string getJobName() const;
    int getCombatPower() { return this->m_level + this->m_force; }
    string solarEclipse();
};