#include <iostream>
#include <string>
#include "Creature.h"
#include "UserInput.h"

int main()
{
    for (int i{ 0 }; i < 10; ++i)
    {
        Creature::Monster m{ Creature::Monster::getRandomMonster() };
        std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
    }

    return 0;
}