#include "Merchant.h"

const std::string Merchant::MERCHANT = "Merchant";

void Merchant::activate(Player *player) {
    player->playMerchant();
}


