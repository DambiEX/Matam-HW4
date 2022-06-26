#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    static const std::string BARFIGHT;

    Barfight() : Card(BARFIGHT) {}

    void activate(Player *player) override;
};

#endif //BARFIGHT_H
