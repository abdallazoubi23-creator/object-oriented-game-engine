#include "Warrior.h"

string Warrior::getJobName() const
{
    return "Warrior";
}

string Warrior::solarEclipse()
{
    int dec = 0;
    if (this->m_force > 0)
        dec = -1;
    this->m_force += dec;
    return this->m_name + " was affected by a solar eclipse! their force has changed by " + to_string(dec) + "!";
}