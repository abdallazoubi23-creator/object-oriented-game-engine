#include "Encounter.h"

string Encounter::getDescription() const
{
    if (this->is_gang)
        return this->m_gang->getDescription();
    else
        return this->m_monster->getDescription();
}

int Encounter::getPower()
{
    return this->is_gang ? this->m_gang->getPower() : this->m_monster->getPower();
}

int Encounter::getLoot()
{
    return this->is_gang ? this->m_gang->getLoot() : this->m_monster->getLoot();
}

int Encounter::getDamage()
{
    return this->is_gang ? this->m_gang->getDamage() : this->m_monster->getDamage();
}