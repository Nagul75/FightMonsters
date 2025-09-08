//
// Created by regal on 9/8/25.
//

#include "UserInput.h"
#include <iostream>
#include <limits>

std::string UserInput::getName()
{
    std::string name{};
    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, name);
    return name;
}
