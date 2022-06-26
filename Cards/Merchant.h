#ifndef TEST_CPP_MERCHANT_H
#define TEST_CPP_MERCHANT_H

#include "Card.h"

class Merchant : public Card {
public:
    static const std::string MERCHANT;

    Merchant() : Card("Merchant") {}

    void activate(Player *player) override;

};

#endif //TEST_CPP_MERCHANT_H