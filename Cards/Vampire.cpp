#include "Vampire.h"

const std::string Vampire::VAMPIRE = "Vampire";

Vampire::Vampire() : Monster(VAMPIRE, VAMPIRE_FORCE, VAMPIRE_LOOT, VAMPIRE_HP_DAMAGE,
                             VAMPIRE_FORCE_DAMAGE) {

}
