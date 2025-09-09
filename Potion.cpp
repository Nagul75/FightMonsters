//
// Created by regal on 9/9/25.
//

#include "Potion.h"
#include "Random.h"

Potion::Potion Potion::Potion::getRandomPotion()
{
    const auto randomPotion{static_cast<Type>(Random::get(0, max_types - 1))};
    const auto randomSize{static_cast<Size>(Random::get(0, max_sizes - 1))};

    return Potion{randomPotion, randomSize};
}
