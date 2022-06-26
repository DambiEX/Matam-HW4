#include "Wizard.h"

const std::string Wizard::WIZARD = "Wizard";

void Wizard::playFairy() {
    heal(ACTION_MODIFIER);
    printFairyMessage(true);
}

void Wizard::heal(int amount) {
    Player::heal(HEAL_MULTIPLIER * amount);
}

Wizard::Wizard(const std::string &name) : Player(name) {

}

std::string Wizard::getClassString() const {
    return WIZARD;
}
