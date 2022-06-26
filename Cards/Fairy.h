#ifndef FAIRY_H
#define FAIRY_H

#include "Card.h"

class Fairy : public Card {
public:
    static const std::string FAIRY;

    Fairy() : Card("Fairy") {}

    void activate(Player *player) override;
};

#endif //FAIRY_H
