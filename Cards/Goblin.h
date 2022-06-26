#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"

class Goblin : public Monster {
public:
    static const std::string GOBLIN;

    Goblin();

private:
    static const int GOBLIN_FORCE = 6;
    static const int GOBLIN_LOOT = 2;
    static const int GOBLIN_HP_DAMAGE = 10;
    static const int GOBLIN_FORCE_DAMAGE = 0;
};

#endif //GOBLIN_H
