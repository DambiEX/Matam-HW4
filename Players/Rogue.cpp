#include "Rogue.h"

const std::string Rogue::ROGUE = "Rogue";

Rogue::Rogue(const std::string &name) : Player(name) {
}

void Rogue::addCoins(int amount) {
    Player::addCoins(amount * MONEY_MULTIPLIER);
}

void Rogue::playPitfall() {
    printPitfallMessage(true);
}

std::string Rogue::getClassString() const {
    return ROGUE;
}

