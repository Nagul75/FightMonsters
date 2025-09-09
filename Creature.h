//
// Created by regal on 9/8/25.
//

#ifndef FIGHTMONSTERS_CREATURE_H
#define FIGHTMONSTERS_CREATURE_H

#include <string>
#include <utility>
#include "Potion.h"

namespace Creature
{
    class Creature
    {
    public:
        Creature(std::string name, const char symbol, const int health, const int damage, const int gold)
            :m_name(std::move(name)), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
        {}

        [[nodiscard]] std::string_view getName() const {return m_name;}
        [[nodiscard]] char getSymbol() const {return m_symbol;}
        [[nodiscard]] int getHealth() const {return m_health;}
        [[nodiscard]] int getDamage() const {return m_damage;}
        [[nodiscard]] int getGold() const {return m_gold;}

        void reduceHealth(int);
        [[nodiscard]] bool isDead() const;
        void addGold(int);

    protected:
        std::string m_name {};
        char m_symbol{};
        int m_health{};
        int m_damage{};
        int m_gold{};
    };

    class Player : public Creature
    {
    public:
        explicit Player(std::string name, const char symbol='@', const int health=10, const int damage=1, const int gold=0)
            :Creature(std::move(name), symbol, health, damage, gold)
        {
        }

        [[nodiscard]] int getLevel() const {return m_level;}

        void levelUp();
        [[nodiscard]] bool hasWon() const;
        void drinkPotion(Potion::Potion potion);

    private:
        int m_level{1};
    };

    class Monster : public Creature
    {
    public:
        static inline Creature monsterData[]
        {
            Creature{"dragon", 'D', 20, 4, 100},
            Creature{"orc", 'o', 4, 2, 25},
            Creature{"slime", 's', 1, 1, 10}
        };

        static Monster getRandomMonster();

        enum Type
        {
            dragon,
            orc,
            slime,
            max_types,
        };

        static_assert(std::size(monsterData) == max_types);

        explicit Monster(const Type monster)
            :Creature(monsterData[monster])
        {}

        Monster(std::string name, const char symbol, const int health, const int damage, const int gold)
            :Creature(std::move(name), symbol, health, damage, gold)
        {}
    };


}

#endif //FIGHTMONSTERS_CREATURE_H