#ifndef PITFALL_H
#define PITFALL_H

#include "Card.h"

class Pitfall : public Card {
public:
    static const std::string PITFALL;

    Pitfall() : Card(PITFALL) {}

    void activate(Player *player) override;
};

#endif //PITFALL_H
