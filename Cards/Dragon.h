#ifndef DRAGON_H
#define DRAGON_H

#include "Monster.h"

class Dragon : public Monster {
public:
    Dragon();

    static const std::string DRAGON;

    bool isDragon() const override;

private:
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;
    static const int DRAGON_HP_DAMAGE = 1000;
    static const int DRAGON_FORCE_DAMAGE = 0;
};

#endif //DRAGON_H
