#include "Behavior.h"

int ResponsibleBehavior::buyPotions(int coins, int hp)
{
    int max_buyable = coins / POTION_COST;               // max number of potions that can be bought with the coins
    int hp_required = (100 - hp);                        // hp that can be gained to reach maximum
    int potions_required = hp_required / POTION_HP_GAIN; // potions needed to reach full hp
    if (potions_required * POTION_HP_GAIN < hp_required) // make sure to not leave any remaining hp
        potions_required++;

    return (max_buyable < potions_required) ? max_buyable : potions_required;
}

int RiskTakingBehavior::buyPotions(int coins, int hp)
{
    // only buy 1 potion if hp is lower than 50 and the player has the coins for it
    if (hp < 50 && coins >= POTION_COST)
        return 1;
    return 0;
}