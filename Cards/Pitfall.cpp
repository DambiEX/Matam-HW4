#include "Pitfall.h"

const std::string Pitfall::PITFALL = "Pitfall";

void Pitfall::activate(Player *player) {
    player->playPitfall();
}