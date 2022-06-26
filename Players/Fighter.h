#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"
#include "../utilities.h"


class Fighter : public Player {
public:
    static const std::string FIGHTER;
    static const int FORCE_MULTIPLIER = 2;

    explicit Fighter(const std::string &name);

    std::string getClassString() const override;

    int getFightingForce() const override;

    void playBarfight() override;
};

#endif //FIGHTER_H
