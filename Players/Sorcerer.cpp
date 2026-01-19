#include "Sorcerer.h"

string Sorcerer::getJobName() const
{
    return "Sorcerer";
}

string Sorcerer::solarEclipse()
{
    this->m_force++;
    return this->m_name + " was affected by a solar eclipse! their force has changed by 1!";
}