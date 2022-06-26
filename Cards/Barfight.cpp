#include "Barfight.h"

const std::string Barfight::BARFIGHT = "Barfight";

void Barfight::activate(Player *player) {
    player->playBarfight();
}