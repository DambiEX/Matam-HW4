#include "Player.h"
#include "../utilities.h"

int Player::fill(int threshold, int attribute, int amount, int negativity) {
    if (amount <= 0)
    {
        return attribute;
    }
    int change = amount * negativity;
    if ((attribute + change) * negativity > threshold)
    {
        return threshold;
    }
    else
    {
        return attribute + change;
    }
}

Player::Player(const std::string &name) : m_name(name), m_level(INITIAL_LEVEL), m_maxHP(MAX_HP),
                                          m_HP(m_maxHP),
                                          m_force(INITIAL_FORCE), m_coins(ACTION_MODIFIER) {
    for (char letter: name)
    {
        if (!std::isalpha(letter) || std::isspace(letter))
        {
            throw InvalidName(name);
        }
    }
}

void Player::levelUp(int level_gain) {
    if (m_level + level_gain >= MAX_LEVEL)
    {
        m_level = MAX_LEVEL;
    }
    else
    {
        m_level += level_gain;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int amount) {
    if (amount > 0)
    {
        m_force += amount;
    }
}

void Player::loseForce(int amount) {
    if (m_force - amount >= 0)
    {
        m_force -= amount;
    }
    else
    {
        m_force = 0;
    }
}

void Player::heal(int amount) {
    m_HP = fill(m_maxHP, m_HP, amount, UPPER_BOUND);
}

void Player::takeDamage(int amount) {
    m_HP = fill(0, m_HP, amount, LOWER_BOUND);
}

bool Player::isEnoughMoney(int amount) const {
    return m_coins >= amount;
}

bool Player::isKnockedOut() const {
    return m_HP <= 0;
}

void Player::addCoins(int amount) {
    m_coins += amount;
}

void Player::pay(int amount) {
    m_coins -= amount;
}

int Player::getForce() const {
    return m_force;
}

int Player::getFightingForce() const {
    return m_level + getForce();
}

int Player::getHP() const {
    return m_HP;
}

std::string Player::getName() const {
    return m_name;
}

int Player::getCoins() const {
    return m_coins;
}

void Player::playBarfight() {
    takeDamage(ACTION_MODIFIER);
    printBarfightMessage(false);
}

void Player::playTreasure() {
    addCoins(ACTION_MODIFIER);
    printTreasureMessage();
}

void Player::playFairy() {
    printFairyMessage(false);
}

void Player::playPitfall() {
    takeDamage(ACTION_MODIFIER);
    printPitfallMessage(false);
}

void Player::lose_battle(int damage, int force_damage) {
    takeDamage(damage);
    loseForce(force_damage);
}

void Player::playMerchant() {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, getName(), getCoins());
    int player_choice = NO_CHOICE;
    while (true)
    {
        std::string input;
        std::getline(std::cin, input, END_LINE);
        if (stringIsNumber(input))
        {
            player_choice = std::stoi(input);
            if (player_choice == BUY_NOTHING || player_choice == BUY_FORCE ||
                player_choice == BUY_HP)
            {
                break;
            }
            else
            {
                printInvalidInput();
            }
        }
        else
        {
            printInvalidInput();
        }
    }

    if (player_choice == BUY_NOTHING)
    {
        printMerchantSummary(std::cout, m_name, player_choice, BUY_NOTHING);
    }
    else if (player_choice == BUY_HP)
    {
        if (isEnoughMoney(HP_PRICE))
        {
            pay(HP_PRICE);
            heal(MERCHANT_HEAL);
            printMerchantSummary(std::cout, m_name, player_choice, HP_PRICE);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, m_name, player_choice, BUY_NOTHING);
        }
    }
    else if (player_choice == BUY_FORCE)
    {
        if (isEnoughMoney(FORCE_PRICE))
        {
            pay(FORCE_PRICE);
            buff(MERCHANT_FORCE);
            printMerchantSummary(std::cout, m_name, player_choice, FORCE_PRICE);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, m_name, player_choice, BUY_NOTHING);
        }
    }
}

bool Player::WonBattle(int force) const {
    return (getFightingForce() >= force);
}

std::ostream &operator<<(std::ostream &output, const Player &player) {
    printPlayerDetails(std::cout, player.getName(), player.getClassString(), player.getLevel(),
                       player.getForce(),
                       player.getHP(), player.getCoins());
    return output;
}

bool Player::stringIsNumber(std::string str) {
    if (str.empty())
    {
        return false;
    }
    for (char letter: str)
    {
        if (!isdigit(letter))
        {
            return false;
        }
    }
    return true;
}







