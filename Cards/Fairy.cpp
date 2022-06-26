#include "Fairy.h"

const std::string Fairy::FAIRY = "Fairy";

void Fairy::activate(Player *player) {
    player->playFairy();
}

