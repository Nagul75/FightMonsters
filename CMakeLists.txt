cmake_minimum_required(VERSION 4.0)
project(FightMonsters)

set(CMAKE_CXX_STANDARD 20)

add_executable(FightMonsters main.cpp
        Creature.h
        Creature.cpp
        UserInput.h
        UserInput.cpp
        Random.h)
