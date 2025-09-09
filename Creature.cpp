//
// Created by regal on 9/8/25.
//

#include "Creature.h"

#include "Random.h"

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

Creature::Monster Creature::Monster::getRandomMonster()
{
    return Monster{static_cast<Monster::Type>(Random::get(0, Monster::max_types - 1))};
}

void Creature::Player::drinkPotion(const Potion::Potion potion)
{
    if (potion.getPotionType() == Potion::Potion::health)
    {
        switch (potion.getPotionSize())
        {
        case Potion::Potion::small: m_health += Potion::EffectHealthSmall;
                                    break;
        case Potion::Potion::medium: m_health += Potion::EffectHealthMedium;
                                    break;
        case Potion::Potion::large: m_health += Potion::EffectHealthLarge;
                                    break;
        default: break;
        }
    }
    else if (potion.getPotionType() == Potion::Potion::strength)
    {
        switch (potion.getPotionSize())
        {
        case Potion::Potion::small: m_damage+=Potion::EffectStrengthSmall;
            break;
        case Potion::Potion::medium: m_damage += Potion::EffectStrengthMedium;
            break;
        case Potion::Potion::large: m_damage += Potion::EffectStrengthLarge;
            break;
        default: break;
        }
    }
    else if (potion.getPotionType() == Potion::Potion::poison)
    {
        switch (potion.getPotionSize())
        {
        case Potion::Potion::small: m_health -=Potion::EffectPoisonSmall;
            break;
        case Potion::Potion::medium: m_health -= Potion::EffectPoisonMedium;
            break;
        case Potion::Potion::large: m_health -= Potion::EffectPoisonLarge;
            break;
        default: break;
        }
    }
}




