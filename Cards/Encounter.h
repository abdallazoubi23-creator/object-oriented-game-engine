#pragma once

#include "Card.h"
#include "Monster.h"
#include "Gang.h"

class Encounter : public Card
{
protected:
    shared_ptr<Monster>m_monster;
    shared_ptr<Gang>m_gang;
    bool is_gang;

public:
    /**
     * Constructor of Encounter class with a monster
     *
     * @param monster -  The monster for the encounter card
     *
     * @return - An Encounter card object with the given monster
     *
     */
    Encounter(shared_ptr<Monster>monster) : Card("Monster"), m_monster(monster), m_gang(), is_gang(false){};

    /**
     * Constructor of Encounter class with a gang
     *
     * @param gang -  The gang for the encounter card
     *
     * @return - An Encounter card object with the given gang
     *
     */
    Encounter(shared_ptr<Gang>gang) : Card("Gang"), m_monster(), m_gang(gang), is_gang(true){};

    string getDescription() const;

    bool isEncounter() { return true; };
    bool isEvent() { return false; };

    int getPower();
    int getLoot();
    int getDamage();
};