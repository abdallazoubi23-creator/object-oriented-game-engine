#include "Monster.h"

Monster::Monster(string name, int power, int loot, int damage) : m_name(name),
                                                                 m_power(power),
                                                                 m_loot(loot),
                                                                 m_damage(damage) {}

string Monster::getDescription() const
{
    return this->m_name + " (power " + to_string(this->m_power) + ", loot " + to_string(this->m_loot) + ", damage " + to_string(this->m_damage) + ")";
}
