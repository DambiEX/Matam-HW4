#ifndef ROGUE_H
#define ROGUE_H

#include "Player.h"
#include "../utilities.h"


class Rogue : public Player {
public:
    static const std::string ROGUE;
    static const int MONEY_MULTIPLIER = 2;

    explicit Rogue(const std::string &name);

    std::string getClassString() const override;

    void addCoins(int amount) override;

    void playPitfall() override;
};

#endif //ROGUE_H
