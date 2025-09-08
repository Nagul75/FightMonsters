#include <iostream>
#include <string>
#include "Creature.h"
#include "UserInput.h"

int main()
{
    const std::string name{UserInput::getName()};
    Creature::Player player{name};
    std::cout << "Welcome " << player.getName() << '\n';
    std::cout << "You have " << player.getHealth() << " and are carrying " << player.getGold() << " gold \n";
    player.addGold(100);
    player.reduceHealth(5);
    std::cout << "You have " << player.getHealth() << " and are carrying " << player.getGold() << " gold \n";
    return 0;
}