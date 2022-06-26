#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    static const std::string TREASURE;

    Treasure() : Card(TREASURE) {}

    void activate(Player *player) override;

};

#endif //TREASURE_H
