cmake_minimum_required(VERSION 3.21)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(ex4
        .idea/.gitignore
        .idea/.name
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        inputs/badFormat_test.txt
        inputs/badFormat_test_start_of_file.txt
        inputs/deck.txt
        inputs/dragonDen_test_expected.txt
        inputs/empty.txt
        inputs/goblinCave_test_expected.txt
        inputs/merchantInput_test_expected.txt
        inputs/noMonster_test_expected.txt
        inputs/roundLimit_test_expected.txt
        inputs/vampireLair_test_expected.txt
        tests/allTen_test_expected.txt
        tests/badPlayerInput_test_expected.txt
        tests/dragonDen_test_expected.txt
        tests/goblinCave_test_expected.txt
        tests/merchantInput_test_expected.txt
        tests/noMonster_test_expected.txt
        tests/roundLimit_test_expected.txt
        tests/vampireLair_test_expected.txt
        deck.txt
        Mtmchkin.h
        Mtmchkin.cpp
        test.cpp
        utilities.cpp
        utilities.h
        Players/Player.cpp Players/Player.h Cards/Card.cpp Cards/Card.h Cards/Merchant.cpp
        Cards/Merchant.h Cards/Treasure.cpp Cards/Treasure.h Cards/Pitfall.cpp
        Cards/Pitfall.h Cards/Fairy.cpp Cards/Fairy.h
        Players/Rogue.cpp Players/Rogue.h Players/Wizard.cpp Players/Wizard.h
        Players/Fighter.cpp Players/Fighter.h Cards/Barfight.cpp Cards/Barfight.h Cards/Dragon.cpp Cards/Dragon.h
        Cards/Vampire.cpp Cards/Vampire.h Cards/Goblin.cpp Cards/Goblin.h Cards/all_cards.h Players/all_players.h Cards/Monster.cpp Cards/Monster.h Cards/Gang.cpp Cards/Gang.h Exception.cpp tool/main.cpp)
