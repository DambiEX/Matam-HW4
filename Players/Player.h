#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    static bool stringIsNumber(std::string basicString);

    //level:

    int getLevel() const;

    void levelUp(int level_gain);


    //force:

    /*
     * fighter gets more fighting force.
     */
    virtual int getFightingForce() const;

    void buff(int amount);

    void loseForce(int amount);


    //hp:

    int getHP() const;

    virtual void heal(int amount);

    void takeDamage(int amount);

    bool isKnockedOut() const;


    //coins:

    int getCoins() const;

    virtual void addCoins(int amount);

    bool isEnoughMoney(int amount) const;

    void pay(int amount);


    //class and name:

    /*
     * returns the name of the class
     */
    virtual std::string getClassString() const = 0;

    std::string getName() const;

    friend std::ostream &operator<<(std::ostream &stream, const Player &p);


    //cards: plays the type of card on this player.

    virtual void playPitfall();

    void playMerchant();

    void playTreasure();

    virtual void playBarfight();

    virtual void playFairy();

    bool WonBattle(int force) const;

    void lose_battle(int damage, int force_damage);


    //constructors:

    explicit Player(const std::string &name);

    Player(const Player &) = default;

    virtual ~Player() = default;

protected:
    //const nums
    static const int ACTION_MODIFIER = 10;
    static const int MAX_HP = 100;
    static const int BUY_NOTHING = 0;
    static const int BUY_HP = 1;
    static const int BUY_FORCE = 2;
    static const int INITIAL_LEVEL = 1;
    static const int HP_PRICE = 5;
    static const int MERCHANT_HEAL = 1;
    static const int FORCE_PRICE = 10;
    static const int MERCHANT_FORCE = 1;
    static const int INITIAL_FORCE = 5;
    static const int UPPER_BOUND = 1;
    static const int LOWER_BOUND = -1;
    static const int NO_CHOICE = -1;
    static const char END_LINE = '\n';

    std::string m_name;
    int m_level, m_maxHP, m_HP, m_force, m_coins;
private:
    const int MAX_LEVEL = 10;

    /*
     * fills an attribute up to the threshold. used for taking damage and healing.
     */
    static int fill(int threshold, int attribute, int amount, int negativity);

    int getForce() const;
};


#endif //PLAYER_H
