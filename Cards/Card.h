#ifndef CARD_H_
#define CARD_H_

#include "../Exception.h"
#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

class Card {
public:

    Card(const Card &) = default;

    Card &operator=(const Card &other) = default;

    virtual ~Card() = default;

    /*
     * activates the ability of the card on the player.
     */
    virtual void activate(Player *player) = 0;


    //prints:

    std::string get_name() const;

    virtual void printCard(std::ostream &stream) const;

    friend std::ostream &operator<<(std::ostream &stream, Card &card);

protected:
    explicit Card(const std::string &name);

private:
    std::string m_name;
};

#endif /* CARD_H_ */
