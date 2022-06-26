#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"
#include "../utilities.h"

class Wizard : public Player {
public:
    static const std::string WIZARD;
    static const int HEAL_MULTIPLIER = 2;

    explicit Wizard(const std::string &name);

    std::string getClassString() const override;

    void heal(int amount) override;

    void playFairy() override;
};

#endif //WIZARD_H
