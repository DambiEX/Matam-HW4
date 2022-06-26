#include "Goblin.h"

const std::string Goblin::GOBLIN = "Goblin";

Goblin::Goblin() : Monster(GOBLIN, GOBLIN_FORCE, GOBLIN_LOOT, GOBLIN_HP_DAMAGE,
                           GOBLIN_FORCE_DAMAGE) {

}
