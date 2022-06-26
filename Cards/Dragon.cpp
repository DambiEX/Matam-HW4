#include "Dragon.h"

const std::string Dragon::DRAGON = "Dragon";

Dragon::Dragon() : Monster(DRAGON, DRAGON_FORCE, DRAGON_LOOT, DRAGON_HP_DAMAGE,
                           DRAGON_FORCE_DAMAGE) {
}

bool Dragon::isDragon() const {
    return true;
}
