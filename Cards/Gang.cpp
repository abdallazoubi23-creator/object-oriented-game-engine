#include "Gang.h"

void Gang::addMonster(shared_ptr<Monster> monster)
{
    this->m_monsters.push_back(monster);    // Add monster
    this->m_power += monster->getPower();   // Add combat power
    this->m_loot += monster->getLoot();     // Add loot
    this->m_damage += monster->getDamage(); // Add damage
}

string Gang::getDescription() const
{
    return "Gang of " + to_string(this->m_size) + " members (power " + to_string(this->m_power) + ", loot " + to_string(this->m_loot) + ", damage " + to_string(this->m_damage) + ")";
}