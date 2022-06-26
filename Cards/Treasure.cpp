#include "Treasure.h"

const std::string Treasure::TREASURE = "Treasure";

void Treasure::activate(Player *player) {
    player->playTreasure();
}

