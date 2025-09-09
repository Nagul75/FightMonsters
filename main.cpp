#include <iostream>
#include <string>
#include "Creature.h"
#include "Random.h"
#include "UserInput.h"

void attackMonster(Creature::Player& player, Creature::Monster& monster)
{
    monster.reduceHealth(player.getDamage());
    std::cout << "You dealt " << player.getDamage() << " damage to the " << monster.getName() << ".\n";
}

void attackPlayer(Creature::Player& player, const Creature::Monster& monster)
{
    player.reduceHealth(monster.getDamage());
    std::cout << "The " << monster.getName() << " dealt " << monster.getDamage() << " damage to you.\n";
}

void fightMonster(Creature::Player& player, Creature::Monster& monster)
{
    while (!player.isDead() && !monster.isDead())
    {
        std::cout << monster.getName() << ": HP - " << monster.getHealth() << " | DMG - " << monster.getDamage() << '\n';
        std::cout << player.getName() << ": HP - " << player.getHealth() << " | DMG - " << player.getDamage() << " | GLD - " << player.getGold() << '\n';

        const char choice{UserInput::runOrFight()};
        if (choice == 'f')
        {
            attackMonster(player, monster);
            if (monster.isDead())
            {
                std::cout << "You killed the " << monster.getName() << "!\n";
                player.addGold(monster.getGold());
                player.levelUp();
                std::cout << "You have leveled up! HP and DMG increased. \n";
                continue;
            }
            attackPlayer(player, monster);
        }
        else
        {
            if (Random::get(0, 1) == 1)
            {
                std::cout << "You have successfully fled! \n";
                return;
            }
            std::cout << "Your attempt to flee was unsuccessful! \n";
            attackPlayer(player, monster);
        }
    }
    if (player.isDead())
    {
        std::cout << "You were killed!\n";
        std::cout << "You reached level " << player.getLevel() << " and amassed " << player.getGold() << " gold.\n";
    }
}

int main()
{
    const std::string name{UserInput::getName()};
    Creature::Player player{name};
    std::cout << "Welcome " << player.getName() << '\n';
    while (!player.hasWon()) // reach level 20 to win
    {
        Creature::Monster monster{Creature::Monster::getRandomMonster()};
        std::cout << "You have encountered a " << monster.getName() << "(" << monster.getSymbol() << "). \n";
        fightMonster(player, monster);
        if (player.isDead())
        {
            break;
        }
    }
    if (player.hasWon())
    {
        std::cout << "You have won the game! \n";
    }
    return 0;
}

