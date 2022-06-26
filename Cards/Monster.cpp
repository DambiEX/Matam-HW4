#include "Monster.h"

Monster::Monster(const std::string& name, int force, int loot, int HP_damage, int force_damage)
: Card(name), m_force(force), m_loot(loot), m_HP_damage(HP_damage), m_force_damage(force_damage)
{}

bool Monster::playerWonBattle(Player *player) const{
    return (player->WonBattle(m_force));
}

void Monster::playerLevelUp(Player *player) {
    player->levelUp(DEFAULT_LEVEL_GAIN);
}

void Monster::playerAddCoins(Player *player) const{
    player->addCoins(m_loot);
}

void Monster::playerLoseBattle(Player *player) const{
    player->lose_battle(m_HP_damage, m_force_damage);
}

void Monster::activate(Player *player) {
    if (playerWonBattle(player))
    {
        playerAddCoins(player);
        playerLevelUp(player);
        printWinBattle(player->getName(), get_name());
    }
    else
    {
        playerLoseBattle(player);
        printLossBattle(player->getName(), get_name());
    }
}

void Monster::printCard(std::ostream &stream) const {
    printCardDetails(stream, get_name());
    printMonsterDetails(stream, m_force, m_HP_damage, m_loot, isDragon());
    printEndOfCardDetails(stream);
}

bool Monster::isDragon() const{
    return false;
}