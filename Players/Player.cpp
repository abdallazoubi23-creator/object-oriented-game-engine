
#include "Player.h"

Player::Player(string name, shared_ptr<Behavior>behavior) : m_name(name),
                                                  m_level(INITIAL_LEVEL),
                                                  m_force(INITIAL_FORCE),
                                                  m_hp(INITIAL_HP),
                                                  m_coins(INITIAL_COINS),
                                                  m_behavior(behavior) {}

string Player::getDescription() const
{
    return this->m_name + ", " + this->getJobName() + " with " + this->getBehaviorName() + " behavior (level " + to_string(this->m_level) + ", force " + to_string(this->m_force) + ")";
}

void Player::getDamage(int damage)
{
    this->m_hp = (this->m_hp > damage) ? this->m_hp - damage : 0;
}

string Player::playCard(shared_ptr<Card>card)
{
    // For encounter cards, do the combat
    if (card->isEncounter())
    {
        return this->combat(card);
    }

    // for event cards, apply the effects of the event
    else if (card->isEvent())
    {
        if (card->isSolarEclipse())
            return this->solarEclipse();
        else if (card->isPotionsMerchant())
            return this->buyPotions();
    }

    return "";
}

string Player::combat(shared_ptr<Card>encounter)
{
    // If the player has a larger combat power
    if (this->getCombatPower() > encounter->getPower())
    {
        this->levelUp();                    // Level them up
        this->lootUp(encounter->getLoot()); // Add loot to their economy
        return this->m_name + " won the encounter, gained " + to_string(encounter->getLoot()) + " coins and leveled up!";
    }

    // In case of failure
    else
    {
        this->getDamage(encounter->getDamage()); // Inflict damage
        return this->m_name + " lost the encounter and took " + to_string(encounter->getDamage()) + " damage!";
    }
}

string Player::buyPotions()
{
    int potions_to_buy = this->m_behavior->buyPotions(this->m_coins, this->m_hp); // number of potions to buy based on behavior
    this->m_coins -= potions_to_buy * POTION_COST;                                // cost of the potions
    this->m_hp += potions_to_buy * POTION_HP_GAIN;                                // amount of hp gained
    return this->m_name + " bought " + to_string(potions_to_buy) + " potions!";
}

bool Player::isGreaterThan(shared_ptr<Player>player)
{
    // player with larger level is higher
    if (this->m_level > player->m_level)
        return true;
    else if (this->m_level < player->m_level)
        return false;

    // for players with same level, the one with more coins is higher
    if (this->m_coins > player->m_coins)
        return true;
    if (this->m_coins < player->m_coins)
        return false;

    // if still the coins are same, the name which is lexicographically smaller
    // is the higher one
    int name_compare = this->m_name.compare(player->m_name);
    return (name_compare <= 0);
}