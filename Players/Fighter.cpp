#include "Fighter.h"

const std::string Fighter::FIGHTER = "Fighter";

int Fighter::getFightingForce() const {
    return FORCE_MULTIPLIER * m_force + m_level;
}

void Fighter::playBarfight() {
    printBarfightMessage(true);
}

Fighter::Fighter(const std::string &name) : Player(name) {

}

std::string Fighter::getClassString() const {
    return FIGHTER;
}
