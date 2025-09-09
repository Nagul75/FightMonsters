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

char UserInput::runOrFight()
{
    while (true)
    {
        std::cout << "(R)un or (F)ight: ";
        char choice{};
        std::cin >> choice;
        if (!std::cin)
        {
            if (std::cin.eof()) std::exit(0);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! \n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice != 'r' && choice != 'f') continue;
        return choice;
    }
}
