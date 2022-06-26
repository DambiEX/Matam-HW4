
#include "Gang.h"

const std::string Gang::GANG = "Gang";
const std::string Gang::END_GANG = "EndGang";

Gang::Gang() : Card(GANG), m_monsters_queue() {
}

Gang::Gang(const Gang &other) : Card(GANG), m_monsters_queue() {
    *this = other;
}

Gang &Gang::operator=(const Gang &other) {
    for (const std::unique_ptr<Monster> &monster: other.m_monsters_queue)
    {
        m_monsters_queue.push_back(std::unique_ptr<Monster>(monster.get()));
    }
    return *this;
}

void Gang::activate(Player *player) {
    bool player_is_winning = true;
    for (const std::unique_ptr<Monster> &monster: m_monsters_queue)
    {
        if (player_is_winning && monster->playerWonBattle(player))
        {
            monster->playerAddCoins(player);
        }
        else
        {
            player_is_winning = false;
            monster->playerLoseBattle(player);
            printLossBattle(player->getName(), monster->get_name());
        }
    }
    if (player_is_winning)
    {
        player->levelUp(1);
        printWinBattle(player->getName(), get_name());
    }
}

void Gang::addMonster(std::unique_ptr<Monster> *monster_pointer) {
    m_monsters_queue.push_back(std::unique_ptr<Monster>(std::move(*monster_pointer)));
}
