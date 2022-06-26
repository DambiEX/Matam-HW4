#ifndef FIGHTER_CPP_BATTLE_H
#define FIGHTER_CPP_BATTLE_H

#include "Card.h"

class Monster : public Card {
public:
    static const int DEFAULT_LEVEL_GAIN = 1;

    ~Monster() override = default;

    Monster(const Monster &) = default;

    Monster &operator=(const Monster &) = default;

    /*
     * returns true if player won the battle
     */
    bool playerWonBattle(Player *player) const;

    /*
     * incurs HP and force damage on player.
     */
    void playerLoseBattle(Player *player) const;

    void playerAddCoins(Player *player) const;

    static void playerLevelUp(Player *player);

protected:
    int m_force;
    int m_loot;
    int m_HP_damage;
    int m_force_damage;

    explicit Monster(const std::string &name, int force, int loot, int HP_damage, int force_damage);

    /*
     * the player fights with the monster
     */
    void activate(Player *player) override;

    void printCard(std::ostream &stream) const override;

    virtual bool isDragon() const;
};


#endif //FIGHTER_CPP_BATTLE_H
