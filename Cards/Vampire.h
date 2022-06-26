#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Monster.h"

class Vampire : public Monster {
public:
    static const std::string VAMPIRE;

    Vampire();

private:
    static const int VAMPIRE_FORCE = 10;
    static const int VAMPIRE_LOOT = 2;
    static const int VAMPIRE_HP_DAMAGE = 10;
    static const int VAMPIRE_FORCE_DAMAGE = 1;
};

#endif //VAMPIRE_H
