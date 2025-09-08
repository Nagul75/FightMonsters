//
// Created by regal on 9/8/25.
//

#include "Creature.h"

void Creature::Creature::addGold(const int gold)
{
    m_gold+=gold;
}

void Creature::Creature::reduceHealth(const int health)
{
    m_health-=health;
}

bool Creature::Creature::isDead() const
{
    return m_health <= 0;
}

bool Creature::Player::hasWon() const
{
    return m_level == 20;
}

void Creature::Player::levelUp()
{
    if (!hasWon())
    {
        m_level++;
        m_damage++;
    }
}



