#include <iostream>
#include <string>
#include "Creature.h"
#include "UserInput.h"

int main()
{
    Creature::Monster m{ Creature::Monster::Type::slime };
    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

    return 0;
}