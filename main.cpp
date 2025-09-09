#include <iostream>
#include <string>
#include "Creature.h"
#include "Random.h"
#include "UserInput.h"


void fightMonster(Creature::Player& player, Creature::Monster& monster);
bool attackMonster(Creature::Player& player, Creature::Monster& monster);  // if monster dead - return true | else return false
bool attackPlayer(Creature::Player& player, Creature::Monster& monster);   // if player dead - return true | else return false

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

void fightMonster(Creature::Player& player, Creature::Monster& monster)
{
    while (true)
    {
        std::cout << monster.getName() << ": HP - " << monster.getHealth() << " | DMG - " << monster.getDamage() << " | GLD - " << monster.getGold() << '\n';
        std::cout << player.getName() << ": HP - " << player.getHealth() << " | DMG - " << player.getDamage() << " | GLD - " << player.getGold() << '\n';
        const char choice{UserInput::runOrFight()};
        if (choice == 'f')  // fight monster
        {
            if (attackMonster(player, monster))
            {
                return; // successfully killed the monster
            }
            if (player.isDead())
            {
                return; // player died
            }
        }
        else if (choice == 'r') // run away
        {
            int runSuccess {Random::get(0, 1)};  //50% chance of success
            if (!runSuccess)
            {
                std::cout << "Your attempt to flee was unsuccessful! \n";
                if (attackPlayer(player, monster))
                {
                    return; // player died
                }
            }
            else
            {
                std::cout << "You ran away successfully! \n";
                return;
            }
        }
    }
}

bool attackMonster(Creature::Player& player, Creature::Monster& monster)
{
    monster.reduceHealth(player.getDamage()); // deal damage to monster
    std::cout << "You dealt " << player.getDamage() << " damage to the " << monster.getName() << ". \n";
    if (!monster.isDead()) // if monster didn't die from the attack
    {
        if (attackPlayer(player, monster))
        {
            return false;  // monster hasn't died
        }
    }
    else
    {
        std::cout << "You killed the " << monster.getName() << '\n';
        player.addGold(monster.getGold());
        player.levelUp();
        std::cout << "You have leveled up! HP++ DMG++ \n";
        return true; // monster died
    }
    return false;  // monster hasn't died
}

bool attackPlayer(Creature::Player& player, const Creature::Monster& monster)
{
    player.reduceHealth(monster.getDamage());
    std::cout << "The " << monster.getName() << " dealt " << monster.getDamage() << " damage to you. \n";
    if (player.isDead())
    {
        std::cout << "You were killed! \n";
        std::cout << "You reached level " << player.getLevel() << " and amassed " << player.getGold() << " gold. \n";
        return true;
    }
    return false;
}

